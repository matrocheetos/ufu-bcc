package exC;

public class Motocicleta implements Veiculo {
    
    private String marca, modelo, cor;
    private int potencia;

    public String marca() {return marca;}
    public String modelo() {return modelo;}
    public String cor() {return cor;}
    public int potencia() {return potencia;}

    public Motocicleta(String marca, String modelo, String cor, int potencia) {
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.potencia = potencia;
    }

    @Override
    public void mostraDados() {
        System.out.println("Marca: "+marca);
        System.out.println("Modelo: "+modelo);
        System.out.println("Cor: "+cor);
        System.out.println("Potencia: "+potencia);
    }
}
