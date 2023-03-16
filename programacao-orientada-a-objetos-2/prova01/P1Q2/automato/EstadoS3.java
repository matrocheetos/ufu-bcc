package automato;

public class EstadoS3 extends Estado {

    public EstadoS3(Automato automato) {
        super(automato);
    }

    @Override
    protected void mudaEstado() {
        if(this.getAutomato().getCaracter() == 'a') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS1(this.getAutomato()));
        } else if(this.getAutomato().getCaracter() == 'b') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS4(this.getAutomato()));
        } else {
            System.out.println("cadeia invalida");
        }
    }
}
