package mvc_modelo;

import personagem.Personagem;

import java.util.Observable;
import java.util.Observer;

public class

InimigoGrafico extends PersonagemGrafico implements Observer {

    private final int velocidade = 0;
    public InimigoGrafico(Personagem i, int x, int y){
        super(i,x,y);
    }

    public void update(Observable subject, Object arg) {

        PersonagemGrafico p = (PersonagemGrafico) subject;

        // ataque
        if( Math.abs(this.getX() - p.getX()) < 5 && Math.abs(this.getY() - p.getY()) < 5){
            this.atacar(p);
        }

        // movimento horizontal
        if(this.getX() < p.getX()){
            this.setX(this.getX() + 1);
        }else if(this.getX() > p.getX()){
            this.setX(this.getX() - 1);
        }
        // movimento vertical
        if(this.getY() < p.getY()){
            this.setY(this.getY() + 1);
        }else if(this.getY() > p.getY()){
            this.setY(this.getY() - 1);
        }
    }
}
