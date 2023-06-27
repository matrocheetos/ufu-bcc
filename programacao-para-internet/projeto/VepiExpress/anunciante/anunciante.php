<?php
require "../php/sessionVerification.php";

session_start();
exitWhenNotLoggedIn();
?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width">
  <link rel="icon" type="image/png" href="../images/favicon.png">

  <link rel="stylesheet" href="../styles/reset.css">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">
  <link rel="stylesheet" href="../styles/global.css">
  <link rel="stylesheet" href="../styles/anunciante.css">

  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>VepiExpress | Página do Anunciante</title>

  <style>
    footer>p {
      margin: 0;
      font-size: 100%;
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
      <li><a href="../php/logout.php">Logout</a></li>
    </ul>
  </nav>

  <main>
    <div class="container px-4 py-5" id="hanging-icons">
      <h2 class="pb-2 border-bottom">Página do anunciante</h2>
      <div class="row g-4 py-5 row-cols-1 row-cols-lg-3">
        <div class="col align-items-start">
          <div>
            <h2>Novo anúncio</h2>
            <p>Formulário para criação de novo anúncio.</p>
            <a href="novoAnuncio.php" class="btn btn-primary">
              Criar anúncio
            </a>
          </div>
        </div>
        <div class="col align-items-start">
          
          <div>
            <h2>Seus anúncios</h2>
            <p>Página com listagem e possibilidade de exclusão de seus anúncios.</p>
            <a href="listaAnuncios.php" class="btn btn-primary">
              Listar anúncios
            </a>
          </div>
        </div>
        <div class="col align-items-start">
          
          <div>
            <h2>Mensagens</h2>
            <p>Página para visualização e exclusão de mensagens de interesse postadas por usuários.</p>
            <a href="mensagens.php" class="btn btn-primary">
              Visualizar mensagens
            </a>
          </div>
        </div>
        <div class="col align-items-start">
          
          <div>
            <h2>Cadastro</h2>
            <p>Página para alteração dos dados de cadastro.</p>
            <a href="alteraCadastro.php" class="btn btn-primary">
              Alterar cadastro
            </a>
          </div>
        </div>
      </div>
    </div>
  </main>

  <footer>
    <p>© 2023 VepiExpress®™. Todos os direitos reservados.</p>
  </footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>

</body>

</html>