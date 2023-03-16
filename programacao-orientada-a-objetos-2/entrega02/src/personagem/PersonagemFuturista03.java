package personagem;

import ataque.*;
import corrida.CorridaRapida;
import pulo.PuloBaixo;

public class PersonagemFuturista03 extends Personagem {
    
    public PersonagemFuturista03(String nome){
        super(nome);
        setPulo(new PuloBaixo());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkForte());
    }
    
}
