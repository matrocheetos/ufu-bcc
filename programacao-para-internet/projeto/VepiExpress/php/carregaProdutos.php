<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

class Anuncio
{
  public $id_anuncio;
  public $titulo;
  public $descricao;
  public $preco;
  public $data;

  function __construct($id_anuncio, $titulo, $descricao, $preco, $data)
  {
    $this->id_anuncio = $id_anuncio;
    $this->titulo = $titulo;
    $this->descricao = $descricao;
    $this->preco = $preco;
    $this->data = $data;
  }
}

$pagina = $_GET['p'] ?? '';

if (trim($pagina) == "" or intval($pagina) < 1)
  $pagina = 1;

$offset = (intval($pagina) - 1) * 6;

$sql = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio
  FROM Anuncio
  ORDER BY data_hora_anuncio DESC
  LIMIT 6 OFFSET {$offset}
  SQL;


try {
  $stmt =  $pdo->query($sql);
} catch (Exception $e) {
  exit('Falha ao carregar produtos: ' . $e->getMessage());
}

$anuncios = array();
while ($row = $stmt->fetch()) {
  // limita tamanho das strings para os cards
  if (strlen($row['titulo']) > 36) {
    $tit = substr($row['titulo'], 0, 36) . "...";
  } else {
    $tit = $row['titulo'];
  }
  if (strlen($row['descricao']) > 100) {
    $desc = substr($row['descricao'], 0, 100) . "...";
  } else {
    $desc = $row['descricao'];
  }

  $anuncios[] = new Anuncio($row['id_anuncio'], $tit, $desc, $row['preco'], $row['data_hora_anuncio']);
}


header('Content-type: application/json');
echo json_encode($anuncios);
