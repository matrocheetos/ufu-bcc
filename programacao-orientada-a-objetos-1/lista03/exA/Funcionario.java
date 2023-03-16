package exA;

public class Funcionario {
    
    private String nome;
    private int rg;
    private double salario;

    public Funcionario(String nome, int rg, double salario) {
        this.nome = nome;
        this.rg = rg;
        this.salario = salario;
    }

    public void mostra() {
        System.out.println("Nome: "+nome);
        System.out.println("RG: "+rg);
        System.out.println("Salario base: "+salario);
    }

    public String getNome() {
        return nome;
    }

    public int getRG() {
        return rg;
    }

    public double getSalario() {
        return salario;
    }
}