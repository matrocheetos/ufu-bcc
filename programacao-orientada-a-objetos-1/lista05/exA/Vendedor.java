package exA;

public class Vendedor extends Funcionario {
    
    private double comissao;

    public Vendedor(String nome, String matricula, double salario_base, double comissao) {
        super(nome,matricula,salario_base);
        this.comissao = comissao;
    }

    public double calcula_salario() {
        return (getSalario() + comissao);
    }
}
