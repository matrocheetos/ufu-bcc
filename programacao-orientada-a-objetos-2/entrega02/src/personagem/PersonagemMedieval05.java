package personagem;

import ataque.*;
import corrida.*;
import pulo.*;

public class PersonagemMedieval05 extends Personagem{
    
    public PersonagemMedieval05(String nome){
        super(nome);
        setPulo(new PuloAlto());
        setCorrida(new CorridaRapida());
        setAtaque(new AtkForte());
    }
}