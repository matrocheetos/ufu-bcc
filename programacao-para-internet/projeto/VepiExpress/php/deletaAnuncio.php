<?php

require "conexaoMysql.php";
require "sessionVerification.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();
$anunciante_email = $_SESSION['user'];

$id_anuncio = $_GET["id_anuncio"] ?? "";

$sql = <<<SQL
  DELETE Anuncio
  FROM Anuncio
  INNER JOIN Anunciante
    ON Anuncio.id_anunciante = Anunciante.id_anunciante
  WHERE
    Anuncio.id_anuncio = ? AND
    Anunciante.email = "{$anunciante_email}"
  SQL;

try{
  $pdo->beginTransaction();

  $stmt = $pdo->prepare($sql);
  if(!$stmt->execute([$id_anuncio]))
    throw new Exception('Falha ao obter ID do anuncio.');

  $pdo->commit();
} catch (Exception $e){
  $pdo->rollBack();
  exit('Falha ao deletar anúncio: ' . $e->getMessage());
}

header('Location: ../anunciante/listaAnuncios.php');
exit();