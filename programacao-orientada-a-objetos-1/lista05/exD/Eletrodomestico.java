package exD;

public class Eletrodomestico implements Produto {
    
    private int id, ano;
    private String unidade, categoria;
    private double preco;

    public int id() {return id;}
    public int ano() {return ano;}
    public String unidade() {return unidade;}
    public String categoria() {return categoria;}
    public double preco() {return preco;}

    public Eletrodomestico(int id, int ano, String unidade, String categoria, double preco) {
        this.id = id;
        this.ano = ano;
        this.unidade = unidade;
        this.categoria = categoria;
        this.preco = preco;
    }
}
