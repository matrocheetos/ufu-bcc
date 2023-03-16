package personagem;

import ataque.*;
import corrida.*;
import pulo.*;

public class PersonagemMedieval04 extends Personagem{
    
    public PersonagemMedieval04(String nome){
        super(nome);
        setPulo(new PuloBaixo());
        setCorrida(new CorridaDevagar());
        setAtaque(new AtkFraco());
    }
}
