package principal;

import personagem.*;
import ataque.*;


public class Principal {
    public static void main(String[] args) {
        Personagem personagem = new Personagem02();
        Escudo escudo1 = new Escudo(5);
        Escudo escudo2 = new Escudo(2);
        Escudo escudo3 = new Escudo(3);

        personagem.setEscudo(escudo1);

        personagem.atacar();

        Ataque poder = new PoderEletrico(personagem.getAtaque());
        personagem.setAtaque(poder);

        poder = new PoderFogo(personagem.getAtaque());
        personagem.setAtaque(poder);

        personagem.atacar();
        personagem.correr();
        personagem.pular();

        personagem.ganharVida(10);
        personagem.perderVida(50);
        personagem.ganharVida(45);

        escudo1.setSucessor(escudo2);
        escudo2.setSucessor(escudo3);

        personagem.perderVida(50);

        personagem.perderVida(20);
        personagem.perderVida(1000);
    }
}
