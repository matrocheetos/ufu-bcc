// funcionalidade para o botão "Amei" nas páginas de produto
// (temporário, estado é perdido ao mudar de página)
function funcionalidadeBotaoAmei() {

  const nodeBtt = document.querySelector("#amei");

  nodeBtt.addEventListener("click", () => {
    nodeBtt.style.color = "red"
  });

  nodeBtt.addEventListener("dblclick", () => {
    nodeBtt.style.color = "black"
  });

}