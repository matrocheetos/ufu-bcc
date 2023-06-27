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

  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">
  <link rel="stylesheet" href="../styles/reset.css">
  <link rel="stylesheet" href="../styles/global.css">
  <link rel="stylesheet" href="../styles/modal.css">

  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>VepiExpress | Novo anúncio</title>

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
    <div class="container-sm pt-3 pb-3">
      <form id="formCadastroAnuncio" name="formulario" action="../php/cadastroAnuncio.php" method="post" enctype="multipart/form-data" class="needs-validation" novalidate>
        <div class="row pb-2 pt-2 ">
          <div class="col-sm-6 pb-2 pt-2">
            <label for="titulo" class="form-label">Título do anúncio</label>
            <input type="text" class="form-control" name="titulo" id="titulo" required>
          </div>
          <div class="col-md-3 pb-2 pt-2">
            <label for="categoria" class="form-label">Categoria</label>
            <select id="categoria" class="form-select" name="categoria" required>
              <option selected disabled value="">Selecionar...</option>
              <!-- opções inseridas pelo javascript -->
            </select>
            <div class="invalid-feedback">Escolha uma categoria</div>
          </div>
          <div class="col-sm-3 pb-2 pt-2">
            <label for="preco" class="form-label">Preço</label>
            <input type="number" step="0.01" min="0" max="99999999.99" class="form-control" name="preco" id="preco" required>
            <div class="invalid-feedback">Insira um preço válido</div>
          </div>
        </div>
        <div class="row pb-2 pt-2">
          <div class="col-sm">
            <label for="descricao" class="form-label">Descrição</label>
            <textarea class="form-control" id="descricao" name="descricao" required></textarea>
            <div class="invalid-feedback">Insira uma descrição do produto</div>
          </div>
        </div>
        <div class="row pb-2 pt-2">
          <div class="col-md-2 pb-2 pt-2">
            <label for="cep" class="form-label">CEP</label>
            <input type="text" class="form-control" name="cep" id="cep" required>
            <div class="invalid-feedback">CEP inválido</div>
          </div>
          <div class="col-md-3 pb-2 pt-2">
            <label for="bairro" class="form-label">Bairro</label>
            <input type="text" class="form-control" name="bairro" id="bairro" required>
            <div class="invalid-feedback">Insira um bairro</div>
          </div>
          <div class="col-md-4 pb-2 pt-2">
            <label for="cidade" class="form-label">Cidade</label>
            <input type="text" class="form-control" name="cidade" id="cidade" required>
            <div class="invalid-feedback">Insira uma cidade</div>
          </div>
          <div class="col-md-3 pb-2 pt-2">
            <label for="estado" class="form-label">Estado</label>
            <select name="estado" id="estado" class="form-select" required>
              <option selected disabled value="">Selecionar...</option>
              <option value="ac">Acre</option>
              <option value="al">Alagoas</option>
              <option value="ap">Amapá</option>
              <option value="am">Amazonas</option>
              <option value="ba">Bahia</option>
              <option value="ce">Ceará</option>
              <option value="df">Distrito Federal</option>
              <option value="es">Espírito Santo</option>
              <option value="go">Goiás</option>
              <option value="ma">Maranhão</option>
              <option value="mt">Mato Grosso</option>
              <option value="ms">Mato Grosso Do Sul</option>
              <option value="mg">Minas Gerais</option>
              <option value="pa">Pará</option>
              <option value="pb">Paraíba</option>
              <option value="pr">Paraná</option>
              <option value="pe">Pernambuco</option>
              <option value="pi">Piauí</option>
              <option value="rj">Rio de Janeiro</option>
              <option value="rn">Rio Grande do Norte</option>
              <option value="rs">Rio Grande do Sul</option>
              <option value="ro">Rondônia</option>
              <option value="rr">Roraima</option>
              <option value="sc">Santa Catarina</option>
              <option value="sp">São Paulo</option>
              <option value="se">Sergipe</option>
              <option value="to">Tocantins</option>
            </select>
            <div class="invalid-feedback">Insira um estado</div>
          </div>
        </div>
        <div class="row">
          <div class="mb-3 pb-2 pt-2">
            <label for="foto" class="form-label">Foto em formato '.jpg'</label>
            <input type="file" class="form-control" name="foto" id="foto" accept=".jpg" required>
            <div class="invalid-feedback">Insira uma foto do produto</div>
          </div>
        </div>
        <div class="row">
          <div class="d-grid gap-2 col-2 mx-auto">
            <button class="btn btn-primary btn-lg btn-block" type="submit">Anunciar</button>
          </div>
        </div>

      </form>
    </div>

    <div class="modal hidden" tabindex="-1" id="modalSucesso">
      <div class="modal-dialog modal-dialog-centered">
        <div class="modal-content">
          <div class="modal-header">
            <h5 class="modal-title">Sucesso!</h5>
            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close" id="botaoModalFecha"></button>
          </div>
          <div class="modal-body">
            <p>Cadastro de anúncio realizado com sucesso.</p>
          </div>
          <div class="modal-footer">
            <button type="button" class="btn btn-secondary" data-bs-dismiss="modal" id="botaoModalNovoAnuncio">Criar outro anúncio</button>
            <button type="button" class="btn btn-primary" id="botaoModalListaAnuncios">Listar meus anúncios</button>
          </div>
        </div>
      </div>
    </div>


  </main>

  <footer>
    <p>© 2023 VepiExpress®™. Todos os direitos reservados.</p>
  </footer>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>

  <script src="../scripts/valida_form.js"></script>
  <script src="../scripts/busca_endereco.js"></script>
  <script src="../scripts/carrega_categorias.js"></script>

  <script>
    function sendFormCadastroAnuncio(form) {
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
            // mostra modal
            const modal = document.getElementById("modalSucesso");
            modal.classList.remove('hidden');
          } else {
            document.querySelector("#cadastroFailMsg").style.display = 'block';
            form.senha.value = "";
            form.senha.focus();
          }
        })
        .catch(error => console.error("Erro de rede ou processamento: " + error))

    }

    window.onload = function() {
      // carrega opções de categorias
      carregaCategorias();

      const inputCep = document.querySelector("#cep");
      const form = document.querySelector("#formCadastroAnuncio");

      // busca endereço no banco de dados
      inputCep.onkeyup = () => buscaEndereco(inputCep, form);

      // valida form e envia form cadastro
      form.onsubmit = function(e) {
        if (validaFormBootstrap(form))
          sendFormCadastroAnuncio(form);
        e.preventDefault();
      }

      // funcionalidade da modal
      const modal = document.getElementById("modalSucesso");
      const modalBtnFecha = document.getElementById("botaoModalFecha");
      const modalBtnNovo = document.getElementById("botaoModalNovoAnuncio");
      const modalBtnLista = document.getElementById("botaoModalListaAnuncios");

      modalBtnFecha.addEventListener('click', function() {
        modal.classList.add('hidden');
        window.location.href = "#";
      });

      modalBtnNovo.addEventListener('click', function() {
        modal.classList.add('hidden');
        limpaFormBootstrap(form);
        window.location.href = "#"
      });

      modalBtnLista.addEventListener('click', function() {
        modal.classList.add('hidden');
        window.location.href = "./listaAnuncios.php";
      });
    }
  </script>

</body>

</html>