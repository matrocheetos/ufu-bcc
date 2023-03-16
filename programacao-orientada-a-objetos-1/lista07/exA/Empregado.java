package exA;

public class Empregado implements Comparable<Empregado> {
    
    private String CPF;
    private int idade;
    private double salario;

    public String getCPF() { return this.CPF; }
    public int getIdade() { return this.idade; }
    public double getSalario() { return this.salario; }

    public Empregado(String CPF, int idade, double salario) {
        this.CPF = CPF;
        this.idade = idade;
        this.salario = salario;
    }

    @Override //da interface 'Comparable':
    public int compareTo(Empregado b) {
        if(this.getIdade()>b.getIdade())
            return this.getIdade();
        else
            return b.getIdade();
    }

}
