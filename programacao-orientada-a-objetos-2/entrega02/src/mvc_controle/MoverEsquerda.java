package mvc_controle;

import mvc_modelo.PersonagemGrafico;

public class MoverEsquerda implements Command {
    private PersonagemGrafico p;
    public MoverEsquerda(PersonagemGrafico p){
        this.p = p;
    }

    public void execute(){
        p.moverEsq();
    }
}
