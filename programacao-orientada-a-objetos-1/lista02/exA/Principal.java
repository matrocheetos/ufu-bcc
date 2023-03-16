import java.util.Scanner;

public class Principal {

    public static void main(String a[]) {

        Tempo t = new Tempo(0,0,0);
        Scanner sc = new Scanner(System.in);
        int op = 0;
        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Informar tempo");
            System.out.println("2) Mostrar tempo (hh:mm:ss)");
            System.out.println("3) Mostrar tempo (hh:mm:ss AM/PM)");
            System.out.println("4) Ajuste de tempo (+1 min)");
            System.out.println("5) Ajuste de tempo (-1 min)");
            System.out.println("6) Sair");
            System.out.print("OPCAO: ");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.print("Hora: ");
                    int h = sc.nextInt();
                    System.out.print("Minuto: ");
                    int m = sc.nextInt();
                    System.out.print("Segundo: ");
                    int s = sc.nextInt();
                    t = new Tempo(h,m,s);
                    break;
                case 2:
                    System.out.println("Tempo: "+t.mostraTempo24());
                    break;
                case 3:
                    System.out.println("Tempo: "+t.mostraTempo12());
                    break;
                case 4:
                    t.ajustaTempoAdd();
                    System.out.println("+1 min");
                    break;
                case 5:
                    t.ajustaTempoSub();
                    System.out.println("-1 min");
                    break;
            }

        } while (op!=6);
    }
}
