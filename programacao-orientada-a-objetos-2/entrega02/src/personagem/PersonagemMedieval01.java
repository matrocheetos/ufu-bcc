package personagem;

import ataque.*;
import corrida.CorridaMedia;
import pulo.PuloMedio;

public class PersonagemMedieval01 extends Personagem {
    
    public PersonagemMedieval01(String nome){
        super(nome);
        setPulo(new PuloMedio());
        setCorrida(new CorridaMedia());
        setAtaque(new AtkForte());   
    }
}
