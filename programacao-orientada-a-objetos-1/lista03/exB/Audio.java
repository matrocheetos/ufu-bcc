package exB;

public class Audio extends Midia {
    
    private String cantor;
    private int nroDeFaixas;

    public Audio(String nome, String genero, int tipo, int ano, int nroDeCopias, double preco,
                    String cantor, int nroDeFaixas) {
        
        super(nome,genero,tipo,ano,nroDeCopias,preco);
        this.cantor = cantor;
        this.nroDeFaixas = nroDeFaixas;
    }

    public void mostra() {
        super.mostra();
        System.out.println("Cantor: "+cantor);
        System.out.println("Numero de faixas: "+nroDeFaixas);
    }
}