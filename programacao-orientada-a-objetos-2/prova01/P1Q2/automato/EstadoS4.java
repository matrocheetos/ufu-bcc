package automato;

public class EstadoS4 extends Estado {

    public EstadoS4(Automato automato) {
        super(automato);
    }

    @Override
    protected void mudaEstado() {
        if(this.getAutomato().getCaracter() == 'd') {
            this.getAutomato().nextCaracter();
            this.getAutomato().setEstado(new EstadoS3(this.getAutomato()));
        } else {
            System.out.println("cadeia valida");
        }
    }
}
