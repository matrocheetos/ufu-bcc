package fabricas;

import ataque.*;
import java.util.Random;
import personagem.Escudo;
import personagem.*;


public class AdvancedFuturistaFactory extends FuturistaFactory{
    
    private static AdvancedFuturistaFactory instancia = null;
    
    private AdvancedFuturistaFactory(){};
    
    public static AdvancedFuturistaFactory getInstance() {
        if (instancia == null) 
            instancia = new AdvancedFuturistaFactory();
        return instancia;
    }
     
    public Personagem createPersonagem(){
        Personagem p = null;
        Random gerador = new Random();
        double rand = gerador.nextDouble();
        
        if(rand <= 0.2){
            p = new PersonagemFuturista01("Androide avançado");
            Ataque poder = new PoderFogo(p.getAtaque());
            p.setAtaque(poder);
            System.out.println("Criou personagem futurista Androide avançado!");
        }else if(rand <= 0.4){
            p = new PersonagemFuturista02("Ciborgue avançado");
            Escudo escudo = new Escudo(20);
            p.setEscudo(escudo);
            System.out.println("Criou personagem futurista Ciborgue avançado!");
        }else if(rand <= 0.6){
            p = new PersonagemFuturista03("Covenant avançado");
            Ataque poder = new PoderEletrico(p.getAtaque());
            p.setAtaque(poder);
            System.out.println("Criou personagem futurista Covenant avançado!");
        }else if(rand <= 0.8){
            p = new PersonagemFuturista04("Tecnomago avançado");
            Ataque poder = new PoderGelo(p.getAtaque());
            p.setAtaque(poder);
            Escudo escudo = new Escudo(10);
            p.setEscudo(escudo);
            System.out.println("Criou personagem futurista Tecnomago avançado!");
        }else if(rand <= 1.0){
             p = new PersonagemFuturista05("Pirata espacial avançado");
             Ataque poder = new PoderGelo(p.getAtaque());
             Ataque poder2 = new PoderFogo(poder);
             p.setAtaque(poder2);
             System.out.println("Criou personagem futurista Pirata espacial avançado!");
        }
        return p;
    }
}