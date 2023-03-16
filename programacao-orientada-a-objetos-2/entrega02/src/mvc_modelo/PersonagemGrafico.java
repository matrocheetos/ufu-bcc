package mvc_modelo;

import personagem.Personagem;
import principal.Constantes;

import java.util.Observable;

public class PersonagemGrafico extends Observable {
    Personagem p;
    private int x;
    private int y;
    private final int velocidade = 10; //pixels q se movem

    public PersonagemGrafico(Personagem p, int x, int y){
        this.p = p;
        this.x = x;
        this.y = y;
        this.p.setLife(5000);
    }

    public int getX() {return this.x;}
    public int getY() {return this.y;}
    public void setX(int x){this.x = x; }
    public void setY(int y){this.y = y; }

    public void moverEsq(){
        if(getX() >= 0)
            setX(getX() - this.velocidade);
    }

    public void moverDir(){
        if(getX() <= Constantes.coordX)
            setX(getX() + this.velocidade);

    }

    public void moverCima(){
        if(getY() >= 0) {
            setY(getY() - this.velocidade);
        }
    }

    public void moverBaixo(){
        if(getY() <= Constantes.coordY)
            setY(getY() + this.velocidade);
    }

    public void atacar(PersonagemGrafico inimigo){
        this.p.atacar(inimigo.p);
    }

    public void show(){
        setChanged();
        notifyObservers();
    }

    public Personagem getP(){return p;};

}
