<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

class Categoria
{
  public $id_categoria;
  public $nome_categoria;
  public $descricao_categoria;

  function __construct($id_categoria, $nome_categoria, $descricao_categoria)
  {
    $this->id_categoria = $id_categoria;
    $this->nome_categoria = $nome_categoria;
    $this->descricao_categoria = $descricao_categoria;
  }
}

$sql_categorias = <<<SQL
  SELECT id_categoria, nome_categoria, descricao_categoria
  FROM Categoria
  SQL;

try {
  $stmt = $pdo->prepare($sql_categorias);
  $stmt->execute();
}catch (Exception $e) {
  exit('Falha ao carregar categorias: ' . $e->getMessage());
}

$categorias = array();
while ($row = $stmt->fetch()) {
  $categorias[] = new Categoria($row['id_categoria'], $row['nome_categoria'], $row['descricao_categoria']);
}

header('Content-Type: application/json');
echo json_encode($categorias);