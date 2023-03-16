package estados;

import personagem.Personagem;

public class EstadoMorto extends Estado{
    
    public EstadoMorto(Personagem personagem){
        super(personagem);
        System.out.println("Entrou em estado de morto!");
    }

    @Override
    protected void setLimites() {
        setLimiteInferior(0);
        setLimiteSuperior(0);
    }

    @Override
    protected void verificarAlteracaoEstado() {
        System.out.println("Personagem morreu! Fim de Jogo!");
    }
 
}
