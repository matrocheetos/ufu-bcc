package estados;

import personagem.Personagem;

public abstract class Estado {
    private Personagem personagem;
    private int limiteInferior; //definido nas classes concretas
    private int limiteSuperior; //definido nas classes concretas
    
    public Estado (Personagem personagem){
        this.personagem = personagem;
        setLimites();
    }
    
    protected abstract void setLimites(); //implementado nas classes concretas

    public Personagem getPersonagem() {
        return personagem;
    }
    
    public void perderVida(int dano){
        int nVida = this.personagem.getLife() - dano;
        if(nVida < 0)
            nVida = 0;
        
        this.personagem.setLife(nVida);
        this.verificarAlteracaoEstado();
    }
    
    public void ganharVida(int vida){
        int nVida = this.personagem.getLife() + vida;
        if(nVida > 100)
            nVida = 100;
        
        this.personagem.setLife(nVida);
        this.verificarAlteracaoEstado();
    }
    
    protected abstract void verificarAlteracaoEstado(); //implementado nas classes concretas

    /**
     * @return the limiteInferior
     */
    public int getLimiteInferior() {
        return limiteInferior;
    }

    /**
     * @param limiteInferior the limiteInferior to set
     */
    public void setLimiteInferior(int limiteInferior) {
        this.limiteInferior = limiteInferior;
    }

    /**
     * @return the limiteSuperior
     */
    public int getLimiteSuperior() {
        return limiteSuperior;
    }

    /**
     * @param limiteSuperior the limiteSuperior to set
     */
    public void setLimiteSuperior(int limiteSuperior) {
        this.limiteSuperior = limiteSuperior;
    }
    
}