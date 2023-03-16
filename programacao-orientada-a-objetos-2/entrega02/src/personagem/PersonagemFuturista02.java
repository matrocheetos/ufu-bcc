package personagem;

import ataque.*;
import corrida.CorridaRapida;
import pulo.PuloAlto;

public class PersonagemFuturista02 extends Personagem {
    
    public PersonagemFuturista02(String nome){
        super(nome);
        setPulo(new PuloAlto());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkMedio());
        
    }
}
