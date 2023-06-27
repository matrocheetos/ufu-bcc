<?php

require "conexaoMysql.php";
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

$nome = $_POST["nome"] ?? "";
$cpf = $_POST["cpf"] ?? "";
$email = $_POST["email"] ?? "";
$senha = $_POST["senha"] ?? "";
$telefone = $_POST["telefone"] ?? "";
$novasenha = $_POST["novasenha"] ?? "";

if (empty($nome) or empty($cpf) or empty($email) or empty($senha) or empty($telefone) or empty($novasenha)) {
  exit("Erro! Um ou mais campos vazios.");
}

// calcula um hash de senha seguro para armazenar no BD
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

function validaSenha($pdo, $email, $senha)
{
  $sql_senha = <<<SQL
    SELECT senha_hash
    FROM Anunciante
    WHERE email = ?
    SQL;

  try {
    $stmt = $pdo->prepare($sql_senha);
    $stmt->execute([$email]);
    $senhaHash = $stmt->fetchColumn();

    if (!$senhaHash)
      return false; // email não encontrado

    if (!password_verify($senha, $senhaHash))
      return false; // senha incorreta

    // email e senha corretos
    return true;
  } catch (Exception $e) {
    exit('Falha inesperada: ' . $e->getMessage());
  }
}

if (!validaSenha($pdo, $email, $senha)) {
  exit('Erro! Sua senha está incorreta');
}

$sql = <<<SQL
  UPDATE Anunciante 
  SET nome_anunciante = ?, cpf = ?, senha_hash = ?, telefone = ?
  WHERE email = ?
  SQL;

$novasenha_hash = password_hash($novasenha, PASSWORD_DEFAULT);

try {

  $stmt = $pdo->prepare($sql);
  $stmt->execute([$nome, $cpf, $novasenha_hash, $telefone, $email]);

  $response = new RequestResponse(true, 'anunciante.php');
  header('Content-type: application/json');
  echo json_encode($response);
  exit();
} catch (Exception $e) {

  $response = new RequestResponse(false, '');
  header('Content-type: application/json');
  echo json_encode($response);
  exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
