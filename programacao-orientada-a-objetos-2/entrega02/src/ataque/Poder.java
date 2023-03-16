package ataque;

public abstract class Poder extends Ataque{
    private Ataque ataque;

    public Poder(Ataque ataque){
        this.ataque = ataque;
    }

}
