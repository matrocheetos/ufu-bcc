<?php

require "conexaoMysql.php";
require "sessionVerification.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();

class RequestResponse
{
  public $success;
  public $detail;

  function __construct($success, $detail)
  {
    $this->success = $success;
    $this->detail = $detail;
  }
}



$titulo = $_POST["titulo"] ?? "";
$descricao = $_POST["descricao"] ?? "";
$preco = $_POST["preco"] ?? "";
$cep_anuncio = $_POST["cep"] ?? "";
$bairro_anuncio = $_POST["bairro"] ?? "";
$cidade_anuncio = $_POST["cidade"] ?? "";
$estado_anuncio = $_POST["estado"] ?? "";
$id_categoria = $_POST["categoria"] ?? "";

// $nome_foto = basename($_FILES['foto']['name']);
$nome_foto = 'foto1.jpg';
$uploaddir = '../images/anuncio/';
$uploadfile = $uploaddir . $nome_foto;

$anunciante_email = $_SESSION['user'];

$data_anuncio = new DateTime('now');
$data_anuncio = $data_anuncio->format('Y-m-d h:m:s');


// if (
//   trim($titulo) == "" or trim($descricao) == "" or trim($preco) == "" or trim($cep_anuncio) == ""
//   or trim($bairro_anuncio) == "" or trim($cidade_anuncio) == "" or trim($estado_anuncio) == ""
//   or trim($nome_categoria)
// ) {
//   exit("Erro! Um ou mais campos vazios.");
// }

// =========================================

$sql_id_anunciante = <<<SQL
  SELECT id_anunciante
  FROM Anunciante
  WHERE email = ?
  SQL;

$sql_anuncio = <<<SQL
  INSERT INTO Anuncio (titulo, descricao, preco, data_hora_anuncio, cep_anuncio, bairro_anuncio, cidade_anuncio, estado_anuncio, id_anunciante, id_categoria)
  VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
  SQL;

$sql_foto = <<<SQL
  INSERT INTO Foto (id_anuncio, nome_arq_foto)
  VALUES(?, ?)
  SQL;

// =========================================

try {
  $pdo->beginTransaction();

  // ================================
  // encontra id_anunciante
  $stmt1 = $pdo->prepare($sql_id_anunciante);
  if (!$stmt1->execute([$anunciante_email]))
    throw new Exception('Falha ao obter ID do anunciante.');

  $id_anunciante = $stmt1->fetchColumn();
  if (!$id_anunciante)
    exit('Erro! id_anunciante não encontrado.');

  // ================================
  // insere anuncio na tabela
  $stmt3 = $pdo->prepare($sql_anuncio);
  if (!$stmt3->execute([
    $titulo, $descricao, $preco, $data_anuncio, $cep_anuncio,
    $bairro_anuncio, $cidade_anuncio, $estado_anuncio,
    $id_anunciante, $id_categoria
  ]))
    throw new Exception('Falha ao inserir anúncio.');

  // ================================
  // insere nome da foto na tabela
  $id_anuncio = $pdo->lastInsertId();
  
  $stmt4 = $pdo->prepare($sql_foto);
  if(!$stmt4->execute([$id_anuncio, $nome_foto]))
    throw new Exception('Falha ao inserir foto.');

  if(!move_uploaded_file($_FILES['userfile']['tmp_name'], $uploadfile)) {
    // throw new Exception('Falha ao inserir foto.');
  }
    

  // ================================
  // efetiva as operações
  $pdo->commit();

  $response = new RequestResponse(true, '../anunciante/novoAnuncio.php');
  header('Content-type: application/json');
  echo json_encode($response);
  exit();
} catch (Exception $e) {
  $pdo->rollBack();
  $response = new RequestResponse(false, '');
  header('Content-type: application/json');
  echo json_encode($response);
  exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
