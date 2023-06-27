<?php
require "../php/conexaoMysql.php";
require "../php/sessionVerification.php";

session_start();
exitWhenNotLoggedIn();

$pdo = mysqlConnect();

$anunciante_email = $_SESSION['user'];
// $anunciante_email = 'joao@gmail.com'

$sql = <<<SQL
  SELECT nome_anunciante, cpf, senha_hash, telefone FROM Anunciante
  WHERE email = ?
  SQL;

try{
  $stmt = $pdo->prepare($sql);
  $stmt->execute([$anunciante_email]);
  $cadastro = $stmt->fetch(PDO::FETCH_ASSOC);
} catch (Exception $e) {
    exit('Falha ao obter dados do cadastro' . $e->getMessage());
}

$nome = htmlspecialchars($cadastro['nome_anunciante']);
$cpf = htmlspecialchars($cadastro['cpf']);
$telefone = htmlspecialchars($cadastro['telefone']);

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
  <link rel="stylesheet" href="../styles/form.css">
  <script src="../scripts/valida_form.js"></script>
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>VepiExpress | Dados do cadastro</title>

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
    <form id="formCadastro" name="formulario" action="../php/alteraCadastro.php" method="post">
      <div class="campo">
        <label for="nome">Nome:</label>
        <input type="text" id="nome" name="nome" value="<?php echo($nome) ?>" autofocus>
        <span></span>
      </div>
      <div class="campo">
        <label for="cpf">CPF:</label>
        <input type="text" id="cpf" name="cpf" value="<?php echo($cpf) ?>" pattern="\d{3}\.\d{3}\.\d{3}-\d{2}" placeholder="xxx.xxx.xxx-xx">
        <span></span>
      </div>
      <div class="campo">
        <label for="telefone">Telefone:</label>
        <input type="tel" id="telefone" name="telefone" value="<?php echo($telefone) ?>" pattern="\([0-9]{2}\)[\s][0-9]{5}-[0-9]{4}"
          placeholder="(xx) xxxxx-xxxx">
        <span></span>
      </div>
      <div class="campo">
        <label for="email">Email</label>
        <input type="email" id="email" name="email" value="<?php echo($anunciante_email) ?>" readonly>
        <span></span>
      </div>
      <div class="campo">
        <label for="senha">Senha:</label>
        <input type="password" id="senha" name="senha">
        <span></span>
      </div>
      <div class="campo">
        <label for="novasenha">Nova senha:</label>
        <input type="password" id="novasenha" name="novasenha">
        <span></span>
      </div>
      <div>
        <span id="cadastroFailMsg">Erro ao cadastrar.</span>
        <span id="cadastroSuccessMsg">Cadastrado com sucesso!</span>
      </div>

      <button type="submit">Alterar cadastro</button>
    </form>
  </main>

  <footer>
    <p>© 2023 VepiExpress®™. Todos os direitos reservados.</p>
  </footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>
  <script>
    function sendFormCadastro(form) {

      let formData = new FormData(form);
      const options = {
        method: "POST",
        body: formData
      }

      fetch(form.getAttribute("action"), options)
        .then(response => {
          if (!response.ok) {
            throw new Error("Sem resposta: " + response.status);
          }
          return response.json()
        })
        .then(cadastroResponse => {
          if (cadastroResponse.success) {
            document.querySelector("#cadastroSuccessMsg").style.display = 'block';
            form.nome.value = "";
            form.cpf.value = "";
            form.telefone.value = "";
            form.email.value = "";
            form.senha.value = "";
            form.novasenha.value = "";
            // window.location = cadastroResponse.detail;
          } else {
            document.querySelector("#cadastroFailMsg").style.display = 'block';
            form.senha.value = "";
            form.senha.focus();
          }
        })
        .catch(error => console.error("Erro de rede ou processamento: " + error))

    }

    window.onload = function () {
      const form = document.querySelector("#formCadastro");
      form.onsubmit = function (e) {
        if (validaForm()) {
          sendFormCadastro(form);
        } else {
          e.preventDefault();
        }
      }
    }
  </script>
</body>

</html>