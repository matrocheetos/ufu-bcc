package exA;

public class Cubo extends FormaTridimensional {
    
    private float lado;

    public Cubo(String id, String cor, int x, int y, int z, float lado) {
        super(id, cor, x, y, z);
        this.lado = lado;
    }

    public double obterVolume() {
        return (lado*lado*lado);
    }

    public void mostra() {
        super.mostra();
        System.out.println("Lado: "+lado);
    }
}
