package fabricas;

import personagem.Personagem;

public abstract class FuturistaFactory extends AbstractPersonagemFactory{
    public abstract Personagem createPersonagem();   

    public void Jogar(){
        Personagem p1 = createPersonagem();
        Personagem p2 = createPersonagem();
        //p1.atacar();
        p1.correr();
       // p2.atacar();
   }
    
}
