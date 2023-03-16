package exB;

import java.util.Scanner;

public class Principal {

    public static void main(String z[]) {

        CartaoWeb c[] = new CartaoWeb[10];
        Scanner sc = new Scanner(System.in);
        int op = 0, ct = 0;

        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Criar cartao");
            System.out.println("2) Exibir mensagens cadastradas");
            System.out.println("3) Exibir mensagens de Dia dos Namorados");
            System.out.println("4) Exibir mensagens de Natal");
            System.out.println("5) Exibir mensagens de Aniversario");
            System.out.println("6) Sair");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.print("Destinatario: ");
                    sc.nextLine(); //limpa buffer
                    String destinatario = sc.nextLine();

                    System.out.print("Tipo de cartao (1)Dia dos Namorados, (2)Natal ou (3)Aniversario: ");
                    int tipo = sc.nextInt();
                    if(tipo == 1) {
                        System.out.print("Nome do(a) namorado(a): ");
                        sc.nextLine(); //limpa buffer
                        String namorado = sc.nextLine();
                        System.out.print("Anos de namoro: ");
                        int anosDeNamoro = sc.nextInt();
                        c[ct] = new DiaDosNamorados(destinatario,namorado,anosDeNamoro);
                    } else if(tipo == 2) {
                        c[ct] = new Natal(destinatario);
                    } else if(tipo == 3) {
                        System.out.print("Data do aniversario: ");
                        sc.nextLine(); //limpa buffer
                        String dataDoAniversario = sc.nextLine();
                        c[ct] = new Aniversario(destinatario,dataDoAniversario);
                    } else {
                        System.out.println("Tipo invalido!");
                        break;
                    }
                    ct++;
                    break;
                case 2:
                    for(int i=0;i<ct;i++) {
                        System.out.println("Cartao "+i+")");
                        c[i].showMessage();
                    }
                    break;
                case 3:
                    for(int i=0;i<ct;i++) {
                        if(c[i] instanceof DiaDosNamorados) {
                            System.out.println("Cartao "+i+")");
                            c[i].showMessage();
                        }
                    }
                    break;
                case 4:
                    for(int i=0;i<ct;i++) {
                        if(c[i] instanceof Natal) {
                            System.out.println("Cartao "+i+")");
                            c[i].showMessage();
                        }
                    }
                    break;
                case 5:
                    for(int i=0;i<ct;i++) {
                        if(c[i] instanceof Aniversario) {
                            System.out.println("Cartao "+i+")");
                            c[i].showMessage();
                        }
                    }
                    break;
            }
        } while(op!=6);
    }
}
