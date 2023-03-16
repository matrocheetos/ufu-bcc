package exB;

public class Aniversario extends CartaoWeb {
    
    private String dataDoAniversario;

    public Aniversario(String destinatario, String dataDoAniversario) {
        super(destinatario);
        this.dataDoAniversario = dataDoAniversario;
    }

    public void showMessage() {
        System.out.println(dataDoAniversario);
        System.out.println("Feliz Aniversário, "+getDestinatario()+"!");
        System.out.println("Muitas felicidades e anos de vida!");
    }
}
