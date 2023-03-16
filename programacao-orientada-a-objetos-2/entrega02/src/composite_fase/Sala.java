package composite_fase;

import personagem.Personagem;
import templateMethodJogar.*;

public class Sala implements Fase{

    private Fase caminho1;
    private Fase caminho2;
    private Personagem inimigo;
    private Jogar jogar;

    public Sala(Fase f1, Fase f2, Personagem inimigo) {
        this.caminho1 = f1;
        this.caminho2 = f2;
        this.inimigo = inimigo;
        //jogar = new JogarAleatorio();
        //jogar = new JogarInterativo();
    }
    public Fase getCaminho (int porta){
        if (porta == 1) {
            return caminho1;
        } else {
            return caminho2;
        }
    }

    public int isSala(){return 0;};

    public void jogar(Personagem p){
        jogar.templateJogar(p,this);
    }

    public Personagem getInimigo(){return this.inimigo;}

}

