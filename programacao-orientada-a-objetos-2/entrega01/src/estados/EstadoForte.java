package estados;

import ataque.*;
import corrida.CorridaRapida;
import personagem.Personagem;

public class EstadoForte extends Estado{

    public EstadoForte(Personagem personagem){
        super(personagem);
        this.getPersonagem().setCorrida(new CorridaRapida());
        this.getPersonagem().setAtaque(new AtkForte());
        System.out.println("Entrou em estado forte!");
    }
    
    @Override
    protected void setLimites() {
        setLimiteInferior(71);
        setLimiteSuperior(100);
    }

    @Override
    protected void verificarAlteracaoEstado() {
        if(this.getPersonagem().getLife() < this.getLimiteInferior()){
            this.getPersonagem().setEstado(new EstadoNormal(this.getPersonagem()));
            this.getPersonagem().getEstado().verificarAlteracaoEstado();
        }
    }
    
}
