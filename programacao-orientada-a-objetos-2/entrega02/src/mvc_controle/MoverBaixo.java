package mvc_controle;

import mvc_modelo.PersonagemGrafico;

public class MoverBaixo implements Command {
    private PersonagemGrafico p;
    public MoverBaixo(PersonagemGrafico p){
        this.p = p;
    }

    public void execute(){
        p.moverBaixo();
    }

}
