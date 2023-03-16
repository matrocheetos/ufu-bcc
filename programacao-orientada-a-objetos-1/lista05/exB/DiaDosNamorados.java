package exB;

public class DiaDosNamorados extends CartaoWeb {
    
    private String namorado;
    private int anosDeNamoro;

    public DiaDosNamorados(String destinatario, String namorado, int anosDeNamoro) {
        super(destinatario);
        this.namorado = namorado;
        this.anosDeNamoro = anosDeNamoro;
    }

    public void showMessage() {
        System.out.println("Feliz Dia dos Namorados, meu amor!");
        System.out.println(anosDeNamoro+" ano(s) de namoro eh muito god. Te amo!");
        System.out.println("De: "+namorado+" Para: "+getDestinatario());
    }
}
