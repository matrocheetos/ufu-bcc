package personagem;

import ataque.*;
import corrida.*;
import pulo.*;

public class PersonagemFuturista05 extends Personagem{
    
    public PersonagemFuturista05(String nome){
        super(nome);
        setPulo(new PuloAlto());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkForte());
    }
}