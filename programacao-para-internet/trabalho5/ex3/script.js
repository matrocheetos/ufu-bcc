document.addEventListener('DOMContentLoaded', function() {
    const msg = document.getElementById("msg")
    const enviar = document.getElementById("enviar")
    const fechar = document.getElementById("fechar")
    const caixa_msg = document.getElementById("caixa_msg")
    const main = document.querySelector("main")

    function showMessage(mensagem) {
        if (mensagem.value != "") {
            caixa_msg.style.visibility = 'visible';
            caixa_msg.textContent = mensagem.value;
        }
    }

    function hideMessage() {
        caixa_msg.style.visibility = 'hidden';
        main.style.height = 'auto';
        msg.value = ""

    }

    enviar.addEventListener('click', function () { showMessage(msg) } );
    fechar.addEventListener('click', function () { hideMessage() })
});