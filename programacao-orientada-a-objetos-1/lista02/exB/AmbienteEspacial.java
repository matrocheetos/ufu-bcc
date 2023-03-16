import java.util.Scanner;

public class AmbienteEspacial {
    
    public static void main(String a[]) {
        
        NaveEspacial v[] = new NaveEspacial[5];
        Scanner sc = new Scanner(System.in);
        int op = 0;
        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Criar nave");
            System.out.println("2) Exibir naves");
            System.out.println("3) Comparar velocidade");
            System.out.println("4) Sair");
            if(NaveEspacial.getCt()>=3)
                System.out.println("Superpopulacao de Naves");
            System.out.print("OPCAO: ");
            op = sc.nextInt();

            switch (op) {
                case 1:
                    String s;
                    if(NaveEspacial.getCt()<3) {
                        System.out.print("Nome da nave: ");
                        sc.nextLine();
                        s = sc.nextLine();
                    } else if (NaveEspacial.getCt()<5){
                        s = "Nave com Defeito";
                    } else {
                        System.out.println("Limite de naves atingido");
                        break;
                    }
                    NaveEspacial n = new NaveEspacial(s);
                    v[NaveEspacial.getCt()-1] = n;
                    break;
                case 2:
                    for(int i=0;i<NaveEspacial.getCt();i++) {
                        System.out.println("Nave "+i+": ");
                        v[i].mostrarNave();
                    }
                    break;
                case 3: //prof testou todas "for(...)"
                    System.out.print("Nave A: ");
                    int x = sc.nextInt();
                    System.out.print("Nave B: ");
                    int y = sc.nextInt();
                    v[x].naveMaisRapida(v[y]);
                    break;
            }
        } while (op!=4);
    }
}
