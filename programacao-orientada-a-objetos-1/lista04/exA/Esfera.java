package exA;

public class Esfera extends FormaTridimensional {
    
    private float raio;

    public Esfera(String id, String cor, int x, int y, int z, float raio) {
        super(id, cor, x, y, z);
        this.raio = raio;
    }

    public double obterVolume() {
        return (((raio*raio*raio)*4*3.14)/3);
    }

    public boolean interceptam(Esfera e) {
        if((getX()+raio) >= (e.getX()+raio) || (getY()+raio) >= (e.getZ()+raio) || (getY()+raio) >= (e.getZ()+raio))
            return true;
        else
            return false;
    }

    public void mostra() {
        super.mostra();
        System.out.println("Raio: "+raio);
    }
}
