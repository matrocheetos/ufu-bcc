package fabricas;

import objetos.*;

public class Objeto2DFactory extends ObjetoAbstractFactory {
    @Override
    public Copo fabricarCopo() {
        return new Copo2D();
    }

    @Override
    public Garrafa fabricarGarrafa() {
        return new Garrafa2D();
    }

    @Override
    public Prato fabricarPrato() {
        return new Prato2D();
    }
}
