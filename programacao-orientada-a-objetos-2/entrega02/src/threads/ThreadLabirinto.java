package threads;

import composite_fase.*;
import personagem.Personagem;

public class ThreadLabirinto implements Runnable{
    private Fase labirinto;
    private Personagem personagem;
    public ThreadLabirinto(Fase labirinto, Personagem p){
       this.labirinto = labirinto;
       this.personagem = p;
    }
    
    public void run(){
        labirinto.jogar(personagem);
    }
}
