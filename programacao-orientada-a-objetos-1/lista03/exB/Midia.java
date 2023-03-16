package exB;

public class Midia {
    
    private String nome, genero;
    private int tipo; // (1)audio (2)video
    private int ano, nroDeCopias;
    private double preco;

    public Midia(String nome, String genero, int tipo, int ano, int nroDeCopias, double preco) {
        this.nome = nome;
        this.genero = genero;
        this.tipo = tipo;
        this.ano = ano;
        this.nroDeCopias = nroDeCopias;
        this.preco = preco;
    }

    public void mostra(){
        System.out.println("Nome: "+nome);   
        System.out.println("Genero: "+genero);
        if (tipo==1) System.out.println("Tipo: audio");
        else System.out.println("Tipo: video");
        System.out.println("Ano: "+ano);
        System.out.println("Numero de copias: "+nroDeCopias);
        System.out.println("Preco de locacao: "+preco);
    }

    public String getNome() {
        return nome;
    }

    public String getGenero() {
        return genero;
    }

    public int getTipo() {
        return tipo;
    }

    public int getAno() {
        return ano;
    }

    public int getNroDeCopias() {
        return nroDeCopias;
    }

    public double getPreco() {
        return preco;
    }
}