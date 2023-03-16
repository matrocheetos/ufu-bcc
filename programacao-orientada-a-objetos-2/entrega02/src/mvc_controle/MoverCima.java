package mvc_controle;

import mvc_modelo.PersonagemGrafico;

public class MoverCima implements Command {
    private PersonagemGrafico p;
    public MoverCima(PersonagemGrafico p){
        this.p = p;
    }

    public void execute(){
        p.moverCima();
    }

}
