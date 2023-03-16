package exB;

public abstract class CartaoWeb {
    
    private String destinatario;

    public abstract void showMessage();

    public CartaoWeb(String destinatario) {
        this.destinatario = destinatario;
    }

    public String getDestinatario() {
        return destinatario;
    }
}
