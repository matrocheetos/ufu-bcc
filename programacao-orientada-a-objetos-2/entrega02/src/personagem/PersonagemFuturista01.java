package personagem;

import ataque.*;
import corrida.CorridaMedia;
import pulo.PuloMedio;

public class PersonagemFuturista01 extends Personagem {
    
    public PersonagemFuturista01(String nome){
        super(nome);
        setPulo(new PuloMedio());
        setCorrida(new CorridaMedia());
        setAtaque(new AtkForte());   
    }
}
