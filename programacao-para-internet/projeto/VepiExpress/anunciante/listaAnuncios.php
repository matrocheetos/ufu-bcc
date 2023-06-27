<?php
require "../php/conexaoMysql.php";
require "../php/sessionVerification.php";

session_start();
exitWhenNotLoggedIn();


$pdo = mysqlConnect();
$anunciante_email = $_SESSION['user'];

$sql_lista_anuncios = <<<SQL
  SELECT
    Anuncio.id_anuncio as id_anuncio,
    Anuncio.titulo as titulo,
    Anuncio.descricao as descricao,
    Anuncio.preco as preco,
    Anunciante.id_anunciante
  FROM Anuncio
  INNER JOIN Anunciante
  ON Anuncio.id_anunciante = Anunciante.id_anunciante
  AND Anunciante.email = "{$anunciante_email}"
  SQL;

try {
  $stmt =  $pdo->query($sql_lista_anuncios);
} catch (Exception $e) {
  exit('Falha ao obter anúncios: ' . $e->getMessage());
}

?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width">
  <link rel="icon" type="image/png" href="../images/favicon.png">

  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">
  <link rel="stylesheet" href="../styles/reset.css">
  <link rel="stylesheet" href="../styles/global.css">
  <link rel="stylesheet" href="../styles/listas.css">

  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>VepiExpress | Lista de anúncios</title>


</head>

<body>

  <header>
    <svg width="230" height="42" viewBox="0 0 918 168" fill="currentColor">
      <use xlink:href="../vepiexpress.svg#VepiExpress"></use>
    </svg>
  </header>

  <nav>
    <ul>
      <li><a href="../index.html">Home</a></li>
      <li><a href="anunciante.php">Página do anunciante</a></li>
    </ul>
  </nav>

  <main>
    <div class="container px-4 py-5">
      <h2 class="h2">Lista de anúncios</h2>
      <div class="anuncioLista">
        <div class="anuncioItem">
          <hr>
          <h3 class="h3">Produto exemplo</h3>
          <p>Descrição do produto.</p>
          <div class="preco">R$ 1000,00</div><br>
          <div class="row">
            <a href="../anuncio/produto.php?=" class="btn btn-primary">Página do produto</a>
            <a href="../php/deletaAnuncio.php?id_anuncio=$id_anuncio" class="btn btn-danger">Deletar produto</a>
          </div>
        </div>
        <?php
        while ($row = $stmt->fetch()) {
          $id_anuncio = $row['id_anuncio'];
          $titulo = htmlspecialchars($row['titulo']);
          $descricao = htmlspecialchars($row['descricao']);
          $preco = htmlspecialchars($row['preco']);
        
          echo <<<HTML
            <div class="anuncioItem">
              <hr>
              <h3 class="h3">$titulo</h3>
              <p>$descricao</p>
              <div class="preco">R\$ $preco</div><br>
              <div class="row">
                <a href="../anuncio/produto.php?anuncio=$id_anuncio" class="btn btn-primary">Página do produto</a>
                <a href="../php/deletaAnuncio.php?id_anuncio=$id_anuncio" class="btn btn-danger">Deletar produto</a>
              </div>
            </div>
          HTML;
        }
        ?>
      </div>

    </div>
  </main>

  <footer>
    <p>© 2023 VepiExpress®™. Todos os direitos reservados.</p>
  </footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>

</body>

</html>