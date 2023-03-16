package personagem;

import ataque.*;
import corrida.*;
import pulo.*;

public class PersonagemFuturista04 extends Personagem{
    
    public PersonagemFuturista04(String nome){
        super(nome);
        setPulo(new PuloBaixo());
        setCorrida(new CorridaDevagar());
        setAtaque(new AtkFraco());
    }
}
