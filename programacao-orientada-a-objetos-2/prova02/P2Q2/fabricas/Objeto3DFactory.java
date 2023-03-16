package fabricas;

import objetos.*;

public class Objeto3DFactory extends ObjetoAbstractFactory {
    @Override
    public Copo fabricarCopo() {
        return new Copo3D();
    }

    @Override
    public Garrafa fabricarGarrafa() {
        return new Garrafa3D();
    }

    @Override
    public Prato fabricarPrato() {
        return new Prato3D();
    }
}
