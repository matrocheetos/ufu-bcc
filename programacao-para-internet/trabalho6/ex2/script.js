window.onload = function () {
    // escolhe elemento da classe modal
    const modal = document.querySelector(".modal");
    // escolhe botao que vai fechar a janela modal
    const botaoFecha = modal.querySelector(".botaoFecha");

    // esconde a modal
    botaoFecha.addEventListener("click", function () {
        modal.style.display = 'none';
    });

    // abre a modal
    const botaoAbre = document.getElementById("botaoAbre");
    botaoAbre.addEventListener("click", function () {
        modal.style.display = 'block';
    })
}