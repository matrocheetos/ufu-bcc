package templateMethodJogar;

import composite_fase.*;
import personagem.Personagem;

import java.util.Random;
import java.util.Scanner;

public class JogarInterativo extends Jogar{

    public Fase selecionarCaminho(Sala f){
        int escolha;
        while(true) {
            Scanner teclado = new Scanner(System.in);
            System.out.println("Porta 1 ou 2? ");
            escolha = teclado.nextInt();
            if(escolha==1 || escolha==2) {
                break;
            }else{
                System.out.println("Escolha invalida!\n");
            }
        }
        return f.getCaminho(escolha);
    }

    public void lutar(Personagem p){
        Scanner teclado = new Scanner(System.in);
        Random gerador = new Random();
        int dano = gerador.nextInt(10) + 1;
        int escolha;

        while(true) {
            System.out.println("Adivinhe o dano (1 a 10): ");
            escolha = teclado.nextInt();

            if (escolha >= 1 && escolha <= 10)
                break;
            else
                System.out.println("Escolha invalida!\n");
        }

        if(escolha != dano) {
            System.out.println("dano aleatorio: "+dano);
            p.perderVida(escolha);
        }else
            System.out.printf("Acertou! Nao recebe dano\n");
    }

}
