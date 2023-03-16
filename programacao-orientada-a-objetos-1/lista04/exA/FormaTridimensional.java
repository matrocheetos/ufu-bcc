package exA;

public class FormaTridimensional extends Forma {
    
    private int x, y, z; // coordenadas

    public FormaTridimensional(String id, String cor, int x, int y, int z) {
        super(id, cor);
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void mostra() {
        super.mostra();
        System.out.println("x: "+x);
        System.out.println("y: "+y);
        System.out.println("z: "+z);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getZ() {
        return z;
    }
}
