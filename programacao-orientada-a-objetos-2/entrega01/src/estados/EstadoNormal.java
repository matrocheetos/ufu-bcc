package estados;

import ataque.*;
import corrida.CorridaMedia;
import personagem.Personagem;

public class EstadoNormal extends Estado{

    public EstadoNormal(Personagem personagem){
        super(personagem);
        this.getPersonagem().setCorrida(new CorridaMedia());
        this.getPersonagem().setAtaque(new AtkMedio());
        System.out.println("Entrou em estado normal!");
    }
    
    @Override
    protected void setLimites() {
        setLimiteInferior(31);
        setLimiteSuperior(70);
    }

    @Override
    protected void verificarAlteracaoEstado() {
        if(this.getPersonagem().getLife() < this.getLimiteInferior()){
            this.getPersonagem().setEstado(new EstadoPerigo(this.getPersonagem()));
            this.getPersonagem().getEstado().verificarAlteracaoEstado();
        }else{
            if(this.getPersonagem().getLife() > this.getLimiteSuperior()){
                this.getPersonagem().setEstado(new EstadoForte(this.getPersonagem()));
                this.getPersonagem().getEstado().verificarAlteracaoEstado();
            }
        }
    }
    
}
