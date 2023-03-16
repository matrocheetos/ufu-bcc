package personagem;

import ataque.*;
import corrida.CorridaRapida;
import pulo.PuloAlto;

public class PersonagemMedieval02 extends Personagem {
    
    public PersonagemMedieval02(String nome){
        super(nome);
        setPulo(new PuloAlto());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkMedio());
        
    }
}
