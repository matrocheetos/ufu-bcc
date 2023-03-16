package templateMethodJogar;

import composite_fase.*;
import personagem.Personagem;

import java.util.Random;

public class JogarAleatorio extends Jogar{

    public Fase selecionarCaminho(Sala f){

        double valor = Math.random();
        if(valor < 0.5){
            return f.getCaminho(1);
        }else{
            return f.getCaminho(2);
        }
    }

    public void lutar(Personagem p){
        Random gerador = new Random();
        int dano = gerador.nextInt(10) + 1;

        p.perderVida(dano);
    }
}
