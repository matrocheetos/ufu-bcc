package exA;

public class Administrador extends Funcionario {
        
    private int horaExtra;

    public Administrador(String nome, int rg, double salario) {
        super(nome, rg, salario);
        this.horaExtra = 0;
    }

    public void addHoras(int horas) {
        this.horaExtra = this.horaExtra + horas;
    }

    public double salarioTotal(){
        double total = getSalario() + ((0.01*getSalario())*horaExtra);
        this.horaExtra = 0;
        return total;
    }

    public void mostra() {
        super.mostra();
        System.out.println("Horas extra acumuladas: "+horaExtra);
    }
}