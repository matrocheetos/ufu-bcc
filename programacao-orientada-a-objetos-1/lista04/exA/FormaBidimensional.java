package exA;

public class FormaBidimensional extends Forma {
    
    private int x, y; // coordenadas

    public FormaBidimensional(String id, String cor, int x, int y) {
        super(id, cor);
        this.x = x;
        this.y = y;
    }

    public void mostra() {
        super.mostra();
        System.out.println("x: "+x);
        System.out.println("y: "+y);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
