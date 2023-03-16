package personagem;

import ataque.*;
import corrida.CorridaRapida;
import pulo.PuloAlto;

public class Personagem02 extends Personagem {
    
    public Personagem02(){
        super();
        setPulo(new PuloAlto());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkMedio());
        
    }
}
