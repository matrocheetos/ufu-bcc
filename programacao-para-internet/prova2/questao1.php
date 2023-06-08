<?php

require "./conexaoMysql.php";
$pdo = mysqlConnect();

$nome = $_POST["nome"] ?? "";
$cpf = $_POST["cpf"] ?? "";
$email = $_POST["email"] ?? "";
$admissao = $_POST["admissao"] ?? "";
$cargo = $_POST["cargo"] ?? "";
$salario = $_POST["salario"] ?? "";


try {

  $sql = <<<SQL
  INSERT INTO cliente (nome, cpf, email, admissao, cargo, salario)
  VALUES (?, ?, ?, ?, ?, ?, ?)
  SQL;

  $stmt = $pdo->prepare($sql);
  $stmt->execute([
    $nome, $cpf, $email, $admissao, $cargo, $salario
  ]);

  $sql = <<<SQL
  SELECT *
  FROM pessoa, funcionario
  WHERE pessoa.codigo = funcionario.cod_pessoa
  SQL;

  $stmt = $pdo->query($sql);

} 
catch (Exception $e) {
  exit('Falha na criação ou listagem de funcionários: ' . $e->getMessage());
}

?>
<!doctype html>
<html lang="pt-BR">

<head>
  <meta charset="utf-8">
  <!-- 1: Tag de responsividade -->
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Prova 2 - Questão 1</title>

  <!-- 2: Bootstrap CSS -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
  <style>
    body {
      padding-top: 2rem;
    }
    img {
      width: 20px;
    }
  </style>  
</head>

<body>

  <div class="container">
    <h3>Funcionários Cadastrados</h3>
    <table class="table table-striped table-hover">
      <tr>
        <th></th>
        <th>Nome</th>
        <th>CPF</th>
        <th>Email</th>
        <th>Admissão</th>
        <th>Cargo</th>
        <th>Salário</th>
      </tr>

      <?php
      while ($row = $stmt->fetch()) {
        $nome = htmlspecialchars($row['nome']);
        $cpf = htmlspecialchars($row['cpf']);
        $email = htmlspecialchars($row['email']);
        $cargo = htmlspecialchars($row['cargo']);
        $salario = htmlspecialchars($row['salario']);

        $admissao = new DateTime($row['admissao']);
        $admissaoFormatoDiaMesAno = $admissao->format('d-m-Y');

        echo <<<HTML
          <tr>
            <td>$nome</td> 
            <td>$cpf</td>
            <td>$email</td>
            <td>$admissaoFormatoDiaMesAno</td>
            <td>$cargo</td>
            <td>$salario</td>
          </tr>      
        HTML;
      }
      ?>

    </table>
  </div>

</body>

</html>