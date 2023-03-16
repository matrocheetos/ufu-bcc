package automato;

public class EstadoS2 extends Estado {

    public EstadoS2(Automato automato) {
        super(automato);
    }

    @Override
    protected void mudaEstado() {
        if(this.getAutomato().getCaracter() == 'a') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS2(this.getAutomato()));
        } else if(this.getAutomato().getCaracter() == 'b') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS1(this.getAutomato()));
        } else if(this.getAutomato().getCaracter() == 'c') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS4(this.getAutomato()));
        } else {
            System.out.println("cadeia invalida");
        }
    }
}
