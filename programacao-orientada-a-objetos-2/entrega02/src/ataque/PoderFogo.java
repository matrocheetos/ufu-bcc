package ataque;

public class PoderFogo extends Poder{

    public PoderFogo(Ataque ataque){
        super(ataque);
        this.dano = ataque.dano + 10;
        this.descricao = ataque.descricao + "[Bonus de poder de fogo!]";
    }

}
