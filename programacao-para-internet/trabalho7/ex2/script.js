window.onload = function () {
    // uso dos botões para mudar o conteúdo da página
    const botoes = document.querySelectorAll("nav button");
    for (let botao of botoes) {
        botao.addEventListener("click", mudaAba);
    }
    abreAba(2); // abre a aba inicial
    
    // modal
    const modal = document.getElementById("avisoModal");
    const botaoFecha = modal.querySelector(".btn-close");
    
    // validação do formulário
    document.forms.formCadastro.onsubmit = validaFormModal;

    // fecha modal
    botaoFecha.addEventListener("click", function () {
        modal.className = "modal fade";
        modal.style.display = 'none';
    });
}

function mudaAba (e) {
    // abre a aba correspondente ao botão de acordo com sua posição <li>
    const botaoAcionado = e.target;
    const liBotao = botaoAcionado.parentNode;
    const nodes = Array.from(liBotao.parentNode.children);
    const index = nodes.indexOf(liBotao);
    abreAba(index);
}

function abreAba (i) {
    // fecha aba atual
    const tabActive = document.querySelector(".tabActive");
    if (tabActive !== null) { tabActive.className = ""; }

    const buttonActive = document.querySelector(".buttonActive");
    if(buttonActive !== null) { buttonActive.className = ""; }

    // abre nova aba a partir do parâmetro 'i'
    document.querySelectorAll(".tabs section")[i].className = "tabActive";
    document.querySelectorAll("nav button")[i].className = "buttonActive";
    
    // volta para o topo da página
    window.scrollTo(0,0);
}

function validaFormModal (e) {
    let form = e.target;
    let formValido = true;
    const modal = document.getElementById("avisoModal");

    // verifica se campos do formulário estão preenchidos
    // utiliza o <span> para mostrar mensagem de aviso
    if (form.usuario.value === "") {
        formValido = false;
    }
    if (form.usrSenha.value === "") {
        formValido = false;
    }
    if (form.usrEmail.value === "") {
        formValido = false;
    }

    // impede submissão do formulário
    if (!formValido) {
        modal.style.display = 'block';
        modal.className = "modal";
        e.preventDefault();
    }
}