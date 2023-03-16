package mvc_controle;

import mvc_modelo.PersonagemGrafico;
import principal.Constantes;

public class Atacar{
    PersonagemGrafico p;

    public Atacar(PersonagemGrafico p){
        this.p = p;
    }
    public void execute(PersonagemGrafico[] inimigo) {
        for (int i = 0; i < Constantes.maxInimigos; i++) {
            if (Math.abs(this.p.getX() - inimigo[i].getX()) < 150 && Math.abs(this.p.getY() - inimigo[i].getY()) < 150) {
                this.p.atacar(inimigo[i]);
                System.out.printf("atacou");
            }
        }
    }

}
