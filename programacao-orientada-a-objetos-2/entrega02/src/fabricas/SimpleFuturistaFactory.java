package fabricas;

import java.util.Random;
import personagem.*;


public class SimpleFuturistaFactory extends FuturistaFactory{
    
    private static SimpleFuturistaFactory instancia = null;
    
    private SimpleFuturistaFactory(){}
    
    public static SimpleFuturistaFactory getInstance() {
        if (instancia == null) 
            instancia = new SimpleFuturistaFactory();
        return instancia;
    }
 
    public Personagem createPersonagem(){
        Personagem p = null;
        Random gerador = new Random();
        double rand = gerador.nextDouble();
        
        if(rand <= 0.2){
            p = new PersonagemFuturista01("Androide");
            System.out.println("Criou personagem futurista Androide!");
        }else if(rand <= 0.4){
            p = new PersonagemFuturista02("Ciborgue");
            System.out.println("Criou personagem futurista Ciborgue!");
        }else if(rand <= 0.6){
            p = new PersonagemFuturista03("Covenant");
            System.out.println("Criou personagem futurista Covenant!");
        }else if(rand <= 0.8){
            p = new PersonagemFuturista04("Tecnomago");
            System.out.println("Criou personagem futurista Tecnomago!");
        }else if(rand <= 1.0){
             p = new PersonagemFuturista05("Pirata espacial");
             System.out.println("Criou personagem futurista Pirata espacial!");
        }
        return p;
    }
}
