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

if (empty($nome) or empty($cpf) or empty($email) or empty($senha) or empty($telefone)) {
  exit("Erro! Um ou mais campos vazios.");
}

// calcula um hash de senha seguro para armazenar no BD
$hashsenha = password_hash($senha, PASSWORD_DEFAULT);

$sql = <<<SQL
  INSERT INTO Anunciante (nome_anunciante, cpf, email, senha_hash, telefone)
  VALUES (?, ?, ?, ?, ?)
  SQL;

try {

  $stmt = $pdo->prepare($sql);
  $stmt->execute([$nome, $cpf, $email, $hashsenha, $telefone]);

  $response = new RequestResponse(true, '/cadastro.html');
  header('Content-type: application/json');
  echo json_encode($response);
  exit();

} catch (Exception $e) {

  $response = new RequestResponse(false, '');
  header('Content-type: application/json');
  echo json_encode($response);
  exit('Falha ao cadastrar os dados: ' . $e->getMessage());

}
