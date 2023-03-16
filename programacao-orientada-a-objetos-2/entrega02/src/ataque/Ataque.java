package ataque;

import personagem.Personagem;

public abstract class Ataque {
    protected int dano;
    protected String descricao;

    public int atacar(Personagem p) {
        System.out.println(descricao + "\nDano: " + dano);
        p.perderVida(dano);
        return dano;
    }

}
