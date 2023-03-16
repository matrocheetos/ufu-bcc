package efeito;

import forma.Forma;

public class Textura extends Efeito {
    public Textura(Forma forma) {
        super(forma);
        setDescricao(forma.getDescricao() + " textura");
    }
}
