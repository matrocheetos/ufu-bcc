package exA;

public class Vendedor extends Funcionario {
    
    private static double comissao = 0.05;
    private double totalDeVendas;

    public Vendedor(String nome, int rg, double salario) {
        super(nome, rg, salario);
        this.totalDeVendas = 0;
    }

    public void addVendas(double vendas) {
        this.totalDeVendas = this.totalDeVendas + vendas;
    }

    public double salarioTotal() {
        double total = getSalario() + (totalDeVendas*comissao);
        this.totalDeVendas = 0;
        return total;
    }

    public void mostra() {
        super.mostra();
        System.out.println("Total de vendas: "+totalDeVendas);
    }
}