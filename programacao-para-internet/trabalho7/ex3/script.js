window.onload = function () {
    // uso dos botões para mudar o conteúdo da página
    botoes = document.querySelectorAll(".nav-item");
    for (let botao of botoes) {
        botao.addEventListener("click", mudaAba);
    }
    abreAba(0); // abre a aba inicial

    // validação do formulário
    document.forms.formCadastro.onsubmit = validaForm;
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

    const buttonActive = document.querySelector(".active");
    if(buttonActive !== null) { buttonActive.className = "nav-link"; }

    // abre nova aba a partir do parâmetro 'i'
    document.querySelectorAll(".tabs section")[i].className = "tabActive";
    document.querySelectorAll(".nav-link")[i].className = "nav-link active";
    
    // volta para o topo da página
    window.scrollTo(0,0);
}

function validaForm (e) {
    let form = e.target;
    let formValido = true;

    // seleciona o elemento <span> após os campos
    const spanUsr = form.usuario.nextElementSibling;
    const spanSenha = form.usrSenha.nextElementSibling;
    const spanEmail = form.usrEmail.nextElementSibling;

    // esvazia <span>
    spanUsr.textContent = "";
    spanSenha.textContent = "";
    spanEmail.textContent = "";

    // verifica se campos do formulário estão preenchidos
    // utiliza o <span> para mostrar mensagem de aviso
    if (form.usuario.value === "") {
        spanUsr.textContent = "O usuário deve ser preenchido";
        formValido = false;
    }
    if (form.usrSenha.value === "") {
        spanSenha.textContent = "A senha deve ser preenchida";
        formValido = false;
    }
    if (form.usrEmail.value === "") {
        spanEmail.textContent = "O e-mail deve ser preenchido";
        formValido = false;
    }

    // impede submissão do formulário
    if (!formValido) e.preventDefault();
}