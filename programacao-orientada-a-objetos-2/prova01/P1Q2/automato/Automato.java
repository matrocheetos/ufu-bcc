package automato;

public class Automato {
    private String cadeia;
    private Estado estado;

    public Automato(String cadeia) {
        this.cadeia = cadeia;
        System.out.println("cadeia ["+this.cadeia+"]:");
        this.setEstadoInicial(this.cadeia);
    }

    public void setEstado(Estado estado) {
        this.estado = estado;
    }

    private void setEstadoInicial(String cadeia) {
        if(cadeia.charAt(0) != 'a') {
            System.out.println("cadeia invalida");
        } else {
            this.setEstado(new EstadoS1(this));
        }
    }

    public char getCaracter() {
        return cadeia.charAt(0);
    }

    public void nextCaracter() {
        if(cadeia.length()>1) {
            this.cadeia = cadeia.substring(1);
        } else {
            this.cadeia = "0"; // fim da cadeia
        }
    }
}
