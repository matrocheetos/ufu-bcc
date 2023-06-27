<?php
require "../php/conexaoMysql.php";

$pdo = mysqlConnect();

$id_anuncio = $_GET['anuncio'] ?? '';

if (empty($id_anuncio)) {
  header('Location: ../index.html');
  exit;
}

$sql_produto = <<<SQL
  SELECT id_anuncio, titulo, descricao, preco, data_hora_anuncio, cep_anuncio, bairro_anuncio, cidade_anuncio, estado_anuncio
  FROM Anuncio
  WHERE id_anuncio = ?
  SQL;

try {
  $stmt = $pdo->prepare($sql_produto);
  $stmt->execute([$id_anuncio]);
  $produto = $stmt->fetch(PDO::FETCH_ASSOC);
  if (empty($produto)) {
    header('Location: ../index.html');
    exit;
  }
} catch (Exception $e) {
  exit('Falha ao obter dados do produto: ' . $e->getMessage());
}

$titulo = htmlspecialchars($produto['titulo']);
$descricao = htmlspecialchars($produto['descricao']);
$preco = htmlspecialchars($produto['preco']);
$data_hora_anuncio = htmlspecialchars($produto['data_hora_anuncio']);
$cep_anuncio = htmlspecialchars($produto['cep_anuncio']);
$bairro_anuncio = htmlspecialchars($produto['bairro_anuncio']);
$cidade_anuncio = htmlspecialchars($produto['cidade_anuncio']);
$estado_anuncio = htmlspecialchars(strtoupper($produto['estado_anuncio']));

$nome_foto = "foto" . $id_anuncio . ".jpg";

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
  <link rel="stylesheet" href="../styles/produto.css">
  <title>VepiExpress | Produto</title>

  <style>
    span {
      display: none;
      font-weight: 700;
    }
  </style>

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
      <li><a href="produtos.html">Produtos</a></li>
      <li><a href="../resultados.html">Busca</a></li>
      <li><a href="../produto.html">Produto exemplo</a></li>
    </ul>
  </nav>

  <main>
    <?php
    echo <<<HTML
    <div id="layoutProd">
      <img src="../images/anuncio/$nome_foto" alt="imagem $titulo" width="300" height="300">
      <div id="produto">
        <div>
          <h1>$titulo</h1>
        </div>
        <div>
          <h2>R$ $preco</h2>
        </div>
        <div>
          <p><b>Descrição: </b>$descricao</p>
        </div>
        <div>
          <button type="button" class="btn btn-lg" id="amei">
            <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-heart-fill" viewBox="0 0 16 16">
              <path fill-rule="evenodd" d="M8 1.314C12.438-3.248 23.534 4.735 8 15-7.534 4.736 3.562-3.248 8 1.314z" />
            </svg>
          </button>
        </div>
      </div>
    </div>
    <hr>
    <div class="campo">
      <div class="titulo">
        <h3>Informações adicionais</h3>
      </div>
      <div class="container-sm pt-3 pb-3">
        <p><b>Data de criação do anúncio: </b>$data_hora_anuncio</p>
        <p><b>Entrega de: </b>$cidade_anuncio, $estado_anuncio</p>
      </div>
    </div>
    HTML;
    ?>
    <hr>
    <div class="campo">
      <div class="titulo">
        <h3>Tenho interesse</h3>
      </div>
      <div id="comentario" class="container-sm pt-3 pb-3">
        <form id="formInteresse" name="formulario" action="interesse.php" method="post" class="needs-validation" novalidate>
          <div class="pb-2 pt-2">
            <label for="mensagem" class="form-label">Mensagem para o anunciante</label>
            <textarea class="form-control" rows="2" name="mensagem" id="mensagem" required></textarea>
            <div class="invalid-feedback">Escreva uma mensagem</div>
          </div>
          <div class="pb-4 pt-2">
            <label for="contato" class="form-label">Email de contato</label>
            <input type="email" class="form-control" name="contato" id="contato" required>
            <div class="invalid-feedback">Insira um email</div>
          </div>
          <?php
          echo <<<HTML
            <div class="pb-4 pt-2">
              <label for="id_anuncio" class="form-label">ID do anúncio</label>
              <input type="text" class="form-control" name="id_anuncio" id="id_anuncio" value="$id_anuncio" placeholder="$id_anuncio" readonly required>
              <div class="invalid-feedback">ID inválido</div>
            </div>
            HTML;
          ?>
          <div class="d-grid mt-6 pt-6">
            <button class="btn btn-primary btn-lg btn-block" type="submit">Enviar interesse</button>
          </div>
          <div>
            <span id="cadastroFailMsg">Erro ao enviar interesse.</span>
            <span id="cadastroSuccessMsg">Interesse enviado!</span>
          </div>
        </form>
      </div>
    </div>
  </main>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>

  <script src="../scripts/produto.js"></script>

  <script>
    async function sendFormInteresse(form) {
      let formData = new FormData(form);
      const options = {
        method: "POST",
        body: formData
      }

      try {
        let request = await fetch(form.getAttribute("action"), options);
        if (!request.ok) {
          throw new Error("Sem resposta do servidor: " + request.status);
        }
      } catch (e) {
        console.error(e);
      }
    }

    window.onload = function() {
      funcionalidadeBotaoAmei();

      const form = document.querySelector("#formInteresse");
      form.onsubmit = function(e) {
        
        document.querySelector("#cadastroSuccessMsg").style.display = 'none';
        document.querySelector("#cadastroFailMsg").style.display = 'none';

        if (validaFormBootstrap(form))
          sendFormInteresse(form);
        e.preventDefault();
      }
    }
  </script>

  <footer>
    <p>© 2023 VepiExpress®™. Todos os direitos reservados.</p>
  </footer>

</body>

</html>