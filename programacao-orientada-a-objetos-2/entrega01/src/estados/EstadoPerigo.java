package estados;

import ataque.*;
import corrida.CorridaDevagar;
import personagem.Personagem;

public class EstadoPerigo extends Estado{

    public EstadoPerigo(Personagem personagem){
        super(personagem);
        this.getPersonagem().setCorrida(new CorridaDevagar());
        this.getPersonagem().setAtaque(new AtkFraco());
        System.out.println("Entrou em estado de perigo!");
    }
    
    @Override
    protected void setLimites() {
        setLimiteInferior(1);
        setLimiteSuperior(30);
    }

    @Override
    protected void verificarAlteracaoEstado() {
        if(this.getPersonagem().getLife() < this.getLimiteInferior()){
            this.getPersonagem().setEstado(new EstadoMorto(this.getPersonagem()));
            this.getPersonagem().getEstado().verificarAlteracaoEstado();
        }else{
            if(this.getPersonagem().getLife() > this.getLimiteSuperior()){
                this.getPersonagem().setEstado(new EstadoNormal(this.getPersonagem()));
                this.getPersonagem().getEstado().verificarAlteracaoEstado();
            }
        }
    }
    
}
