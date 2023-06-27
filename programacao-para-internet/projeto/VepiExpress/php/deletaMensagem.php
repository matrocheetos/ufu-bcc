<?php

require "conexaoMysql.php";
require "sessionVerification.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();
$anunciante_email = $_SESSION['user'];

$id_interesse = $_GET["id_interesse"] ?? "";

$sql = <<<SQL
  DELETE Interesse
  FROM Interesse
  INNER JOIN Anuncio
  ON Anuncio.id_anuncio = Interesse.id_anuncio
  INNER JOIN Anunciante
  ON Anuncio.id_anunciante = Anunciante.id_anunciante
  WHERE Interesse.id_interesse = ?
  AND Anunciante.email = "{$anunciante_email}"
SQL;

try{
  $pdo->beginTransaction();

  $stmt = $pdo->prepare($sql);
  if(!$stmt->execute([$id_interesse]))
    throw new Exception('Falha ao obter ID do interesse.');

  $pdo->commit();

  $response = new RequestResponse(true, '../anunciante/mensagens.php');
  header('Content-type: application/json');
  echo json_encode($response);
  exit();

} catch (Exception $e){
  $pdo->rollBack();
  $response = new RequestResponse(false, '');
  header('Content-type: application/json');
  echo json_encode($response);
  exit('Falha ao obter anúncios: ' . $e->getMessage());
}