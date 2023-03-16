package ataque;

public class PoderGelo extends Poder {

    public PoderGelo(Ataque ataque){
        super(ataque);
        this.dano = ataque.dano + 11;
        this.descricao = ataque.descricao + "[Bonus de poder de gelo!]";
    }
}
