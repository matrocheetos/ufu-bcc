package exA;

public class Forma {
    
    private String id;
    private String cor;

    public Forma(String id, String cor) {
        this.id = id;
        this.cor = cor;
    }

    public void mostra() {
        System.out.println("ID: "+id);
        System.out.println("Cor: "+cor);
    }

    public String getID() {
        return id;
    }

    public double obterArea() {
        return -1;
    }
    public double obterVolume() {
        return -1;
    }
    public boolean interceptam(Forma f) {
        return false;
    }
}
