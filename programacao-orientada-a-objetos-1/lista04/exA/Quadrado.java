package exA;

public class Quadrado extends FormaBidimensional {
    
    private float lado;

    public Quadrado(String id, String cor, int x, int y, float lado) {
        super(id, cor, x, y);
        this.lado = lado;
    }

    public double obterArea() {
        return (lado*lado);
    }

    public void mostra() {
        super.mostra();
        System.out.println("Lado: "+lado);
    }
}
