package composite_fase;

import personagem.Personagem;

public class Folha01 implements Fase {

    public void jogar(Personagem p){
        System.out.println(p.getNome() + " ganhou!");
    }

    public Fase getCaminho(int porta){return this;}

    public int isSala(){return 1;};

    public Personagem getInimigo(){return null;};
}
