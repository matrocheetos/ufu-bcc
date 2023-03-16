package ataque;

public abstract class Ataque {
    protected int dano;
    protected String descricao;

    public int atacar() {
        System.out.println(descricao + "\nDano: " + dano);
        return dano;
    }

}
