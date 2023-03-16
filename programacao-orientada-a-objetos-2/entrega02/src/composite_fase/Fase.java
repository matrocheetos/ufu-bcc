package composite_fase;

import personagem.Personagem;

public interface Fase{
    Fase getCaminho(int porta);

    void jogar(Personagem p);

    public int isSala();

    public Personagem getInimigo();

}
