package personagem;

import ataque.*;
import corrida.CorridaRapida;
import pulo.PuloBaixo;

public class Personagem03 extends Personagem {
    
    public Personagem03(){
        super();
        setPulo(new PuloBaixo());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkForte());
    }
    
}
