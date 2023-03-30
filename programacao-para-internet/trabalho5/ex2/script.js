document.addEventListener('DOMContentLoaded', function() {
    // troca nome
    // primeiro h1:
    const nome = document.querySelector("h1");
    nome.addEventListener("click", function() {
        nome.textContent = "Horizon";
    })

    // troca subtitulos
    const subtitulos = document.querySelectorAll("h2");
    for(let subtitulo of subtitulos)
        subtitulo.addEventListener("click", () => subtitulo.textContent = "Obrigado");
});
