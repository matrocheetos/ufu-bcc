<?php
require "../php/conexaoMysql.php";
require "../php/sessionVerification.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();
$anunciante_email = $_SESSION['user'];

$sql_lista_mensagens = <<<SQL
  SELECT
    Interesse.id_interesse,
    Interesse.mensagem,
    Interesse.data_hora_interesse,
    Interesse.contato,
    Anuncio.id_anuncio,
    Anunciante.id_anunciante
  FROM Interesse
  INNER JOIN Anuncio
  ON Interesse.id_anuncio = Anuncio.id_anuncio
  INNER JOIN Anunciante
  ON Anuncio.id_anunciante = Anunciante.id_anunciante
  AND Anunciante.email = "{$anunciante_email}"
  SQL;

try {

  $stmt =  $pdo->prepare($sql_lista_mensagens);
  if (!$stmt->execute())
    throw new Exception('Falha ao obter mensagens deixadas em anúncios do anunciante.');
  $lista_mensagens = $stmt->fetchAll(PDO::FETCH_ASSOC);

} catch (Exception $e) {
  exit('Falha ao obter mensagens: ' . $e->getMessage());
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
  <title>VepiExpress | Mensagens de interesse</title>

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
      <h2>Mensagens em seus anúncios</h2>
      <div class="anuncioLista">
        <div class="anuncioItem">
          <hr>
          <h3 class="h3">Mensagem exemplo</h3>
          <p>Mensagem deixada pelo usuário.</p>
          <p><a href="mailto:contato@email.com">contato@email.com</a></p>
          <div class="data">2023-06-01 00:00:00</div><br>
          <div class="row">
            <a href="../anuncio/produto.php?=" class="btn btn-primary">Página do produto</a>
            <a href="../php/deletaMensagem.php?=" class="btn btn-danger">Deletar mensagem</a>
        </div>
      </div>
    </div>
  <?php
  foreach ($lista_mensagens as $mensagem) {
    $id_interesse = htmlspecialchars($mensagem['id_interesse']);
    $mensagem_interesse = htmlspecialchars($mensagem['mensagem']);
    $data = htmlspecialchars($mensagem['data_hora_interesse']);
    $contato = htmlspecialchars($mensagem['contato']);
    $id_anuncio = htmlspecialchars($mensagem['id_anuncio']);
    $id_anunciante = htmlspecialchars($mensagem['id_anunciante']);

    echo <<<HTML
      <div class="anuncioItem">
        <hr>
        <h3 class="h3">Mensagem ID $id_interesse em anúncio ID $id_anuncio</h3>
        <p>$mensagem_interesse</p>
        <p><a href="mailto:$contato">$contato</a></p>
        <div class="data">$data</div><br>
        <div class="row">
          <a href="../anuncio/produto.php?anuncio=$id_anuncio" class="btn btn-primary">Página do produto</a>
          <a href="../php/deletaMensagem.php?id_interesse=$id_interesse" class="btn btn-danger">Deletar mensagem</a>
      </div>
    HTML;
  }
  ?>

  </main>

  <footer>
    <p>© 2023 VepiExpress®™. Todos os direitos reservados.</p>
  </footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>

</body>

</html>