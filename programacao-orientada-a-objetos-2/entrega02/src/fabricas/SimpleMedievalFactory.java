package fabricas;

import java.util.Random;
import personagem.Personagem;
import personagem.PersonagemMedieval01;
import personagem.PersonagemMedieval02;
import personagem.PersonagemMedieval03;
import personagem.PersonagemMedieval04;
import personagem.PersonagemMedieval05;

public class SimpleMedievalFactory extends MedievalFactory{
    
    private static SimpleMedievalFactory instancia = null;
    
    private SimpleMedievalFactory(){}
    
    public static SimpleMedievalFactory getInstance() {
        if (instancia == null) 
            instancia = new SimpleMedievalFactory();
        return instancia;
    }
 
    public Personagem createPersonagem(){
        Personagem p = null;
        Random gerador = new Random();
        double rand = gerador.nextDouble();
        
        if(rand <= 0.2){
            p = new PersonagemMedieval01("Guerreiro");
            System.out.println("Criou personagem medieval guerreiro!");
        }else if(rand <= 0.4){
            p = new PersonagemMedieval02("Arqueiro");
            System.out.println("Criou personagem medieval arqueiro!");
        }else if(rand <= 0.6){
            p = new PersonagemMedieval03("Mago");
            System.out.println("Criou personagem medieval mago!");
        }else if(rand <= 0.8){
            p = new PersonagemMedieval04("Druida");
            System.out.println("Criou personagem medieval druida!");
        }else if(rand <= 1.0){
             p = new PersonagemMedieval05("Elfo");
             System.out.println("Criou personagem medieval elfo!");
        }
        return p;
    }
}
