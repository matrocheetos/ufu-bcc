package personagem;

import ataque.*;
import corrida.CorridaRapida;
import pulo.PuloBaixo;

public class PersonagemMedieval03 extends Personagem {
    
    public PersonagemMedieval03(String nome){
        super(nome);
        setPulo(new PuloBaixo());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkForte());
    }
    
}
