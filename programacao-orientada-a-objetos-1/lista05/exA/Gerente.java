package exA;

public class Gerente extends Funcionario {
    
    public Gerente(String nome, String matricula, double salario_base) {
        super(nome,matricula,salario_base);
    }

    public double calcula_salario() {
        return (getSalario() * 2);
    }
}
