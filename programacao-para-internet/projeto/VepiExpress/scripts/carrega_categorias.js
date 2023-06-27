// carrega categorias de produtos e as insere em uma lista de opções <select>
async function carregaCategorias() {

  try {
    let response = await fetch("../php/carregaCategorias.php");
    if (!response.ok) return;
    var categorias = await response.json();
  } catch (e) {
    console.error(e);
    return;
  }

  const selectCategoria = document.getElementById("categoria");
  for (let categoria of categorias) {
    let optionCategoria = document.createElement("option");
    optionCategoria.appendChild(document.createTextNode(categoria.nome_categoria));
    optionCategoria.value = categoria.id_categoria;

    selectCategoria.appendChild(optionCategoria);
  }
  
}