<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

class Endereco
{
  public $bairro;
  public $cidade;
  public $estado;

  function __construct($bairro, $cidade, $estado)
  {
    $this->bairro = $bairro;
    $this->cidade = $cidade;
    $this->estado = $estado;
  }
}

$cep = $_GET['cep'] ?? '';
if (strlen($cep) != 9) exit('CEP inválido.');

$sql = <<<SQL
  SELECT bairro_endereco, cidade_endereco, estado_endereco
  FROM Endereco
  WHERE cep_endereco = ?
  SQL;

try {
  $stmt = $pdo->prepare($sql);
  $stmt->execute([$cep]);
  $end = $stmt->fetch(PDO::FETCH_ASSOC);
} catch (Exception $e) {
  exit('Falha ao obter endereço do BD: ' . $e->getMessage());
}

$endereco = new Endereco($end['bairro_endereco'], $end['cidade_endereco'], $end['estado_endereco']);

header('Content-Type: application/json; charset=utf-8');
echo json_encode($endereco);
