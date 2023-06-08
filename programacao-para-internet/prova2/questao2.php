<?php

require "./conexaoMysql.php";
$pdo = mysqlConnect();

class Funcionario
{
    public $nome;
    public $cpf;
    public $email;
    public $admissao;
    public $cargo;
    public $salario;

    function __construct($nome, $cpf, $email, $admissao, $cargo, $salario)
    {
        $this->nome = $nome;
        $this->cpf = $cpf;
        $this->email = $email;
        $this->admissao = $admissao;
        $this->cargo = $cargo;
        $this->salario = $salario;
    }
}

$salMin = $_GET["salMin"] ?? "";
if (trim($salMin) == "")
    $salMin = 0;

try {

    $sql = <<<SQL
    SELECT *
    FROM pessoa, funcionario
    WHERE pessoa.codigo = funcionario.cod_pessoa AND funcionario.salario > (salMin)
    VALUES (?)
    SQL;
  
    $stmt = $pdo->prepare($sql);
    $stmt->execute([
      $salMin
    ]);

} 
catch (Exception $e) {
    exit('Falha na busca: ' . $e->getMessage());
}

$funcionarios = [];
while ($row = $stmt->fetch())
{
    echo $funcionarios[] = new Endereco($row['nome'], $row['cpf'], $row['email'], $row['admissao'], $row['cargo'], $row['salario']);
}

header('Content-type: application/json');
echo json_encode($funcionarios);


?>