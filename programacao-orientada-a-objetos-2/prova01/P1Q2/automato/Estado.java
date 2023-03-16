package automato;

public abstract class Estado {
    private Automato automato;


    public Estado (Automato automato) {
        this.automato = automato;
        this.mudaEstado();
    }

    protected abstract void mudaEstado();

    public Automato getAutomato() {
        return automato;
    }
}
