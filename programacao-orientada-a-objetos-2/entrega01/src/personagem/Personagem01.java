package personagem;

import ataque.*;
import corrida.CorridaMedia;
import pulo.PuloMedio;

public class Personagem01 extends Personagem {
    
    public Personagem01(){
        super();
        setPulo(new PuloMedio());
        setCorrida(new CorridaMedia());
        setAtaque(new AtkForte());

         
    }
}
