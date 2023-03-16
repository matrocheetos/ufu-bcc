import java.util.Random;

public class NaveEspacial {
    
    private static int ct = 0;
    private String nome;
    private int velocidade;

    public static int getCt() {
        return ct;
    }

    public NaveEspacial(String s) {
        setNome(s);
        setVelocidade();
        ct++;
    }

    public void mostrarNave() {
        if(velocidade!=0) {
            System.out.println("- nome: "+nome); //getNome()
            System.out.println("- velocidade: "+velocidade); //getVelocidade()
        } else {
            System.out.println("- nave inoperante");
        }
    }

    public void setNome(String s) {
        nome = s;
    }

    public void setVelocidade() { //nao fazer o random dentro do setVelocidade()
        if(ct<3) {
            Random random = new Random();
            velocidade = random.nextInt(10-5)+5;
        } else {
            velocidade = 0;
        }
    }

    public void naveMaisRapida(NaveEspacial n) { //public boolean
        if(n.velocidade==velocidade) {
            System.out.println("Naves A e B tem mesma velocidade");
        } else if(n.velocidade>velocidade) {
            System.out.println("Nave B e mais rapida"); //return false
        } else {
            System.out.println("Nave A e mais rapida"); //return true
        }
    }
}
