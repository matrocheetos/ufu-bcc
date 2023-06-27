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

// ===================================
// palavras chave
$palavraschave = $_POST['input-busca'] ?? '';
if (trim($palavraschave)=="") {
  $chaves = ["","","","",""];
} else {
  $chaves = explode(' ', $palavraschave);
}

$pchave = array();
foreach ($chaves as $chave)
  $pchave[] = $chave;

if(!empty($pchave[0]))
  $pchave1 = "%".$pchave[0]."%";
else
  $pchave1 = "%%";

if(!empty($pchave[1]))
  $pchave2 = "%".$pchave[1]."%";
else
  $pchave2 = "%%";

if(!empty($pchave[2]))
  $pchave3 = "%".$pchave[2]."%";
else
  $pchave3 = "%%";

if(!empty($pchave[3]))
  $pchave4 = "%".$pchave[3]."%";
else
  $pchave4 = "%%";

if(!empty($pchave[4]))
  $pchave5 = "%".$pchave[4]."%";
else
  $pchave5 = "%%";
// ===================================

$tipochave = $_POST['avancada'] ?? ''; // título ou descrição
$categoria = $_POST['categoria'] ?? '';
$precomin = $_POST['precomin'] ?? '';
$precomax = $_POST['precomax'] ?? '';

if ($precomin > $precomax or $precomin=="" or $precomax=="" or $precomax==0) {
  $precomin = 0;
  $precomax = 9999.99;
} elseif ($precomin < 0){
  $precomin = 0;
}

// ===================================
// sql

$sql_busca_descricao = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio
  FROM Anuncio
  WHERE 
    descricao like ? AND
    descricao like ? AND
    descricao like ? AND
    descricao like ? AND
    descricao like ? AND
    preco <= ? AND
    preco >= ? AND
    id_categoria = ?
  ORDER BY data_hora_anuncio DESC
  SQL;

$sql_busca_titulo = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio
  FROM Anuncio
  WHERE 
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    preco <= ? AND
    preco >= ? AND
    id_categoria = ?
  ORDER BY data_hora_anuncio DESC
  SQL;

  $sql_busca_descricao_todas_categorias = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio
  FROM Anuncio
  WHERE 
    descricao like ? AND
    descricao like ? AND
    descricao like ? AND
    descricao like ? AND
    descricao like ? AND
    preco <= ? AND
    preco >= ?
  ORDER BY data_hora_anuncio DESC
  SQL;

$sql_busca_titulo_todas_categorias = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio
  FROM Anuncio
  WHERE 
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    preco <= ? AND
    preco >= ?
  ORDER BY data_hora_anuncio DESC
  SQL;

$sql_busca_simples = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio
  FROM Anuncio
  WHERE 
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    titulo like ? AND
    titulo like ?
  ORDER BY data_hora_anuncio DESC
  SQL;

// ===================================
// executa sql

try {
  if ($tipochave == 'desc' and trim($categoria)!="-1") {
    $stmt = $pdo->prepare($sql_busca_descricao);
    $stmt->execute([
      $pchave1, $pchave2, $pchave3, $pchave4, $pchave5,
      $precomax, $precomin, $categoria
    ]);

  } elseif ($tipochave == 'desc' and trim($categoria)=="-1") {
    $stmt = $pdo->prepare($sql_busca_descricao_todas_categorias);
    $stmt->execute([
      $pchave1, $pchave2, $pchave3, $pchave4, $pchave5,
      $precomax, $precomin
    ]);

  } elseif ($tipochave == 'titulo' and trim($categoria)!="-1") {
    $stmt = $pdo->prepare($sql_busca_titulo);
    $stmt->execute([
      $pchave1, $pchave2, $pchave3, $pchave4, $pchave5,
      $precomax, $precomin, $categoria
    ]);

  } elseif ($tipochave == 'titulo' and trim($categoria)=="-1") {
    $stmt = $pdo->prepare($sql_busca_titulo_todas_categorias);
    $stmt->execute([
      $pchave1, $pchave2, $pchave3, $pchave4, $pchave5,
      $precomax, $precomin
    ]);

  } else {
    $stmt = $pdo->prepare($sql_busca_simples);
    $stmt->execute([
      $pchave1, $pchave2, $pchave3, $pchave4, $pchave5
    ]);
  }
  
} catch (Exception $e) {
  exit('Falha ao realizar busca: ' . $e->getMessage());
}

// ===================================
// devolve resultados da consulta

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

header('Content-Type: application/json');
echo json_encode($anuncios);