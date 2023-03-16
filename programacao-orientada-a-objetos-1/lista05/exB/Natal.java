package exB;

public class Natal extends CartaoWeb {
    
    public Natal(String destinatario) {
        super(destinatario);
    }

    public void showMessage() {
        System.out.println("Feliz Natal, "+getDestinatario()+"!");
    }
}
