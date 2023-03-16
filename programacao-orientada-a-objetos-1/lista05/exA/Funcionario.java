package exA;

public abstract class Funcionario {
    
    private String nome, matricula;
    private double salario_base;

    public abstract double calcula_salario();

    public Funcionario(String nome, String matricula, double salario_base) {
        this.nome = nome;
        this.matricula = matricula;
        this.salario_base = salario_base;
    }

    public double getSalario() {
        return salario_base;
    }
}
