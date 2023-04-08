document.addEventListener('DOMContentLoaded', function () {

    const subtitulos = document.querySelectorAll('h2');

    subtitulos.forEach(subtitulo => {
        for(let subtitulo of subtitulos) {
            let conteudo = subtitulo.nextElementSibling
            subtitulo.addEventListener("click", () => conteudo.style.display = 'none')
            subtitulo.addEventListener("dblclick", () => conteudo.style.display = 'block')
        }
    });
});