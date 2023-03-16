package fabricas;

import objetos.*;

public abstract class ObjetoAbstractFactory {
    public abstract Copo fabricarCopo();
    public abstract Garrafa fabricarGarrafa();
    public abstract Prato fabricarPrato();
}
