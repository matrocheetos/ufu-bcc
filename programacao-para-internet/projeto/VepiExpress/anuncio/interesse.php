<?php

require "../php/conexaoMysql.php";
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

$mensagem = $_POST["mensagem"] ?? "";
$contato = $_POST["contato"] ?? "";
$id_anuncio = $_POST["id_anuncio"] ?? "";

if (
  trim($mensagem) == "" or trim($contato) == "" or trim($id_anuncio) == ""
) {
  exit("Erro! Um ou mais campos vazios.");
}

$data_hora_interesse = new DateTime('now');
$data_hora_interesse = $data_hora_interesse->format('Y-m-d h:m:s');

$sql_interesse = <<<SQL
  INSERT INTO Interesse (mensagem, data_hora_interesse, contato, id_anuncio)
  VALUES (?, ?, ?, ?)
  SQL;

try {

  $stmt = $pdo->prepare($sql_interesse);
  $stmt->execute([$mensagem, $data_hora_interesse, $contato, $id_anuncio]);
  
} catch (Exception $e) {
  exit('Erro ao registrar interesse' . $e->getMessage());
}

header('Location: #');
exit();