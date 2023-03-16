package efeito;

import forma.Forma;

public abstract class Efeito extends Forma {
    private Forma forma;

    public Efeito(Forma forma) {
        this.forma = forma;
    }

}
