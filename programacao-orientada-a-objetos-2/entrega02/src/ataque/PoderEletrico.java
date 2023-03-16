package ataque;

public class PoderEletrico extends Poder{

    public PoderEletrico(Ataque ataque){
        super(ataque);
        this.dano = ataque.dano + 12;
        this.descricao = ataque.descricao + "[Bonus de poder eletrico!]";
    }



}
