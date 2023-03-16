package templateMethodJogar;

import personagem.Personagem;
import composite_fase.*;

public abstract class Jogar{

    public final void templateJogar(Personagem p, Sala f) {

        try{
            Thread.sleep(3000);
        }catch(Exception e){}

        System.out.println(p.getNome() + " mudou de sala!" +
                "\nVida: " + p.getLife() +
                "\nInimigo: " + f.getInimigo().getNome() + "\n");

        lutar(p);
        if(p.getLife()<=0){
            System.out.printf("Voce morreu!");
        }else {
            selecionarCaminho(f).jogar(p);
        }
    }

    public abstract Fase selecionarCaminho(Sala f);

    public abstract void lutar(Personagem p);


}
