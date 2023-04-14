window.onload = function () {
    const campoNome = document.getElementById("campoNome");
    const campoCPF = document.getElementById("campoCPF");
    if(screen.width <= 576) {
        campoNome.className = "col";
        campoCPF.className = "col-5";
    }
}