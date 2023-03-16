package personagem;

public class Escudo {
    private int defesa;
    private Escudo sucessor;

    public Escudo(int defesa){
        this.defesa = defesa;
        this.setSucessor(null);
    }

    public void setSucessor(Escudo sucessor){this.sucessor = sucessor;}

    public Escudo getSucessor(){ return this.sucessor; }

    public int totalAtaque(int ataque){
        ataque -= defesa;
        System.out.println("Passou pelo escudo!");

        if(ataque > 0 && getSucessor() != null) {
            ataque = getSucessor().totalAtaque(ataque);
        } else if(ataque < 0){
            ataque = 0;
        }

        return ataque;
    }

}
