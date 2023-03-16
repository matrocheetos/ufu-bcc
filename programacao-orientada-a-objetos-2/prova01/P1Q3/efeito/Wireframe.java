package efeito;

import forma.Forma;

public class Wireframe extends Efeito {
    public Wireframe(Forma forma) {
        super(forma);
        setDescricao(forma.getDescricao() + " wireframe");
    }
}
