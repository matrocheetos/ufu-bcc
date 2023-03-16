package personagem;

import corrida.Corrida;
import estados.Estado;
import ataque.*;
import estados.EstadoNormal;
import pulo.Pulo;

public abstract class Personagem {
    private Ataque a;
    private Pulo p;
    private Corrida c;
    private int life;
    private Estado estado;
    private Escudo escudo;

    public Personagem(){
        setLife(70);
        setEstado(new EstadoNormal(this));
        this.escudo = null;
    }

    public void setAtaque(Ataque a) {
        this.a = a;
    }

    public Ataque getAtaque() {
        return this.a;
    }

    public void setPulo(Pulo p) {
        this.p = p;
    }

    public void setCorrida(Corrida c) {
        this.c = c;
    }
    
    public int atacar(){
        return a.atacar();
    }
    
    public void pular(){
        p.pular();
    }
    
    public void correr(){
        c.correr();
    }

    public void perderVida(int dano){
        System.out.println("\nVida antes: " + getLife());

        if(escudo != null){
            dano = escudo.totalAtaque(dano);
        }

        this.getEstado().perderVida(dano);
        System.out.println("Dano recebido: " + dano);
        System.out.println("Vida agora: " + getLife()+ "\n");
    }
    
    public void ganharVida(int vida){
        System.out.println("\nVida antes: " + getLife());
        this.getEstado().ganharVida(vida);
        System.out.println("Vida agora: " + getLife() + "\n");
    }
    
    public void setLife(int life) {
        this.life = life;
    }

    public int getLife() {
        return life;
    }

    public Estado getEstado() {
        return estado;
    }

    public void setEstado(Estado estado) {
        this.estado = estado;
    }

    public void setEscudo(Escudo escudo){ this.escudo = escudo; }
    
}
