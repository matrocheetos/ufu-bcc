package exA;

public class Triangulo extends FormaBidimensional {

    private float base, altura;

    public Triangulo(String id, String cor, int x, int y, float base, float altura) {
        super(id, cor, x, y);
        this.base = base;
        this.altura = altura;
    }

    public double obterArea() {
        return (base*altura);
    }

    public void mostra() {
        super.mostra();
        System.out.println("Base: "+base);
        System.out.println("Altura: "+altura);
    }
}
