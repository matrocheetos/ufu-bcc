package exA;

public class Tetraedro extends FormaTridimensional {
    
    private float base, altura, alturaDaBase;

    public Tetraedro(String id, String cor, int x, int y, int z, float base, float altura, float alturaDaBase) {
        super(id, cor, x, y, z);
        this.base = base;
        this.altura = altura;
        this.alturaDaBase = alturaDaBase;
    }

    public double obterVolume() {
        return (((base*alturaDaBase)*altura)/3);
    }

    public void mostra() {
        super.mostra();
        System.out.println("Base: "+base);
        System.out.println("Altura: "+altura);
        System.out.println("Altura da base: "+alturaDaBase);
    }
}
