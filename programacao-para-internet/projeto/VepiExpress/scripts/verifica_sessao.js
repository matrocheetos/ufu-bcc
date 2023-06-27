// verifica se há sessão ativa
async function verificaSessao() {
  try {
    let response = await fetch("../php/sessionVerificationLogin.php");
    if (response.ok)
      var redirect = await response.json();
    else
      return;
  } catch (e) {
    return;
  }
  if (redirect.success)
    window.location.href = redirect.detail;
}
