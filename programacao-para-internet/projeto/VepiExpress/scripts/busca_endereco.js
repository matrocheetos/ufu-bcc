// busca endereços para inserção automática em um form
async function buscaEndereco(cep, form) {
  let valorCep = cep.value.toString();
  if (valorCep.length != 9) return;

  try {
    let response = await fetch("/php/buscaEndereco.php?cep=" + valorCep);
    if (!response.ok) throw new Error(response.statusText);
    var endereco = await response.json();
  } catch (e) {
    console.error(e);
    return;
  }

  // let form = document.querySelector("form");
  form.bairro.value = endereco.bairro;
  form.cidade.value = endereco.cidade;
  form.estado.value = endereco.estado;
}