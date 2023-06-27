// insere anúncios buscados na árvore DOM
function carregaAnuncios(anuncios) {
  const cards = document.getElementById("cards");
  const template = document.getElementById("templ");

  for (let anuncio of anuncios) {
    // console.log(anuncio);
    let html = template.innerHTML
      .replace("{{id_anuncio}}", anuncio.id_anuncio)
      .replace("{{id_anuncio}}", anuncio.id_anuncio)
      .replace("{{titulo}}", anuncio.titulo)
      .replace("{{titulo}}", anuncio.titulo)
      .replace("{{descricao}}", anuncio.descricao)
      .replace("{{preco}}", anuncio.preco)

    cards.insertAdjacentHTML("beforeend", html);
  }
  // mostra cards menos o template original
  document.querySelectorAll('.card').forEach(elemento => {
    if (elemento.parentElement != "template")
      elemento.classList.remove("template");
  });
}

// ====================================
// busca anúncios a partir de termos
async function buscaAnuncios(form) {
  let formData = new FormData(form);
  const options = {
    method: "POST",
    body: formData
  }

  try {
    let response = await fetch(form.getAttribute("action"), options);
    if (!response.ok) {
      throw new Error("Sem resposta do servidor: " + response.status);
    }
    var anuncios = await response.json();
  } catch (e) {
    console.error(e);
    return;
  }
  carregaAnuncios(anuncios);

}

// ====================================
// busca os anúncios de uma página
async function getAnuncios(pagina) {
  try {
    let response = await fetch("./php/carregaProdutos.php?p="+pagina);
    if (!response.ok) {
      throw new Error("Sem resposta do servidor: " + response.status);
    }
    var anuncios = await response.json();
  } catch (e) {
    console.error(e);
    return;
  }

  carregaAnuncios(anuncios);
}