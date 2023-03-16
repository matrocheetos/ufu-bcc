package automato;

public class EstadoS1 extends Estado {

    public EstadoS1(Automato automato) {
        super(automato);
    }

    @Override
    protected void mudaEstado() {
        if(this.getAutomato().getCaracter() == 'a') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS2(this.getAutomato()));
        } else {
            System.out.println("cadeia invalida");
        }
    }
}
