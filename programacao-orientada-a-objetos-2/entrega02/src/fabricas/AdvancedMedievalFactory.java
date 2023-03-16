package fabricas;

import ataque.*;
import java.util.Random;

import personagem.*;

public class AdvancedMedievalFactory extends MedievalFactory{
    
    private static AdvancedMedievalFactory instancia = null;
    
    private AdvancedMedievalFactory(){}
    
    public static AdvancedMedievalFactory getInstance() {
        if (instancia == null) 
            instancia = new AdvancedMedievalFactory();
        return instancia;
    }
     
    public Personagem createPersonagem(){
        Personagem p = null;
        Random gerador = new Random();
        double rand = gerador.nextDouble();
        
        if(rand <= 0.2){
            p = new PersonagemMedieval01("Guerreiro");
            Ataque poder = new PoderFogo(p.getAtaque());
            p.setAtaque(poder);
            System.out.println("Criou personagem medieval guerreiro avançado!");
        }else if(rand <= 0.4){
            p = new PersonagemMedieval02("Arqueiro");
            Escudo escudo = new Escudo(20);
            p.setEscudo(escudo);
            System.out.println("Criou personagem medieval arqueiro avançado!");
        }else if(rand <= 0.6){
            p = new PersonagemMedieval03("Mago");
            Ataque poder = new PoderEletrico(p.getAtaque());
            p.setAtaque(poder);
            System.out.println("Criou personagem medieval mago avançado!");
        }else if(rand <= 0.8){
            p = new PersonagemMedieval04("Druida");
            Ataque poder = new PoderGelo(p.getAtaque());
            p.setAtaque(poder);
            Escudo escudo = new Escudo(10);
            p.setEscudo(escudo);
            System.out.println("Criou personagem medieval druida avançado!");
        }else{
             p = new PersonagemMedieval05("Elfo avançado");
             Ataque poder = new PoderGelo(p.getAtaque());
             Ataque poder2 = new PoderFogo(poder);
             p.setAtaque(poder2);
             System.out.println("Criou personagem medieval elfo avançado!");
        }
        return p;
    }
}