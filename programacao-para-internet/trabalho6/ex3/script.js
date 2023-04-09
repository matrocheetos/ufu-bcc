window.onload = function () {
    const interesse = document.getElementById("interesse");

    interesse.addEventListener("keydown", function onEvent(e) {
        // detecta a tecla "enter"
        if (e.key === "Enter" && interesse.value != "") {
            adicionaInteresse(interesse);
        }
    });
}

function adicionaInteresse(interesse) {
    const lista = document.getElementById("lista");
    // cria novos elementos
    const novoLi = document.createElement("li");
    const novoSpan = document.createElement("span");
    const novoBotao = document.createElement("button");

    // adiciona conteudo nos novos elementos
    novoSpan.textContent = interesse.value;
    novoBotao.textContent = '❌';

    // adiciona elementos à lista
    novoLi.appendChild(novoSpan);
    novoLi.appendChild(novoBotao);
    lista.appendChild(novoLi);
    
    interesse.value = '';

    // funcionalidade do botao
    novoBotao.onclick = function () {
        novoLi.remove();
    }
}