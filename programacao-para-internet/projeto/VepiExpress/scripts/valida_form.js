// ====================================
// valida se campos de forms contém valores e demonstra visualmente
function validaForm() {
  let formValido = true;

  const nosInput = document.querySelectorAll("input");

  for (let no of nosInput) {
    let span = no.nextElementSibling;
    span.textContent = "";

    if (no.value === "") {
      span.textContent = "Esse campo deve ser preenchido";
      formValido = false;
    }
  }

  return formValido;
}

// ====================================
// valida se campos de forms contém valores e demonstra visualmente
// uso apenas em forms bootstrap na parte restrita
function validaFormBootstrap(form) {
  let formValido = true;

  const nosInput = document.querySelectorAll(".form-control");
  for (let no of nosInput) {
    if (no.value === "") {
      no.className = "form-control is-invalid";
      formValido = false;
    } else {
      no.className = "form-control is-valid";
    }
  }

  const nosSelect = document.querySelectorAll(".form-select");
  for (let no of nosSelect) {
    if (no.value === "") {
      no.className = "form-select is-invalid";
      formValido = false;
    } else {
      no.className = "form-select is-valid";
    }
  }

  form.classList.add('was-validated');
  return formValido;
}

// ====================================
// limpa os campos do form e remove indicadores de validação bootstrap
function limpaFormBootstrap(form) {
  const nosInput = document.querySelectorAll(".form-control");
  for (let no of nosInput) {
    no.className = "form-control";
    no.value = "";
  }
  const nosSelect = document.querySelectorAll(".form-select");
  for (let no of nosSelect) {
    no.className = "form-select";
    no.value = "";
  }

  form.classList.remove('was-validated');
}