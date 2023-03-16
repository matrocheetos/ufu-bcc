package mvc_controle;

import mvc_modelo.PersonagemGrafico;

public class MoverDireita implements Command {
    private PersonagemGrafico p;
    public MoverDireita(PersonagemGrafico p){
        this.p = p;
    }

    public void execute(){
        p.moverDir();
    }
}
