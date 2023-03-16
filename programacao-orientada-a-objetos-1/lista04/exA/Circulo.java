package exA;

public class Circulo extends FormaBidimensional {
    
    private float raio;

    public Circulo(String id, String cor, int x, int y, float raio) {
        super(id, cor, x, y);
        this.raio = raio;
    }

    public double obterArea() {
        return ((raio*raio)*3.14);
    }

    public boolean interceptam(Circulo c) {
        if((getX()+raio) >= (c.getX()+raio) || (getY()+raio) >= (c.getY()+raio))
            return true;
        else
            return false;
    }

    public void mostra() {
        super.mostra();
        System.out.println("Raio: "+raio);
    }
}
