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

$email = $_POST['email'] ?? '';
$senha = $_POST['senha'] ?? '';

function checkUserCredentials($pdo, $email, $senha)
{
  $sql = <<<SQL
    SELECT senha_hash
    FROM Anunciante
    WHERE email = ?
    SQL;

  try {
    $stmt = $pdo->prepare($sql);
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

if (checkUserCredentials($pdo, $email, $senha)) {
  // cria uma nova sessão para o usuário
  session_start();
  $_SESSION['loggedIn'] = true;
  $_SESSION['user'] = $email;
  $response = new RequestResponse(true, '/anunciante/anunciante.php');
} else
  $response = new RequestResponse(false, '');

echo json_encode($response);
