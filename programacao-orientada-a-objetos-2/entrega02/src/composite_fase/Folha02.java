package composite_fase;

import personagem.Personagem;

public class Folha02 implements Fase {

    public void jogar(Personagem p){
        System.out.println(p.getNome() + " perdeu!");
    }

    public Fase getCaminho(int porta){return this;}

    public int isSala(){return -1;};

    public Personagem getInimigo(){return null;};
}
