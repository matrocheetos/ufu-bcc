package exC;

import java.util.Scanner;

public class Principal {
    
    public static void main(String z[]) {

        Veiculo v[] = new Veiculo[5];
        Scanner sc = new Scanner(System.in);
        int op = 0, ct = 0;

        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Registrar veiculo");
            System.out.println("2) Mostrar marca do veiculo vermelho mais e menos potente");
            System.out.println("3) Sair");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.print("Marca: ");
                    sc.nextLine(); //limpa buffer
                    String marca = sc.nextLine();
                    System.out.print("Modelo: ");
                    String modelo = sc.nextLine();
                    System.out.print("Cor: ");
                    String cor = sc.nextLine();
                    System.out.print("Potencia: ");
                    int potencia = sc.nextInt();

                    System.out.print("Tipo de veiculo (1)Carro ou (2)Motocicleta: ");
                    int tipo = sc.nextInt();
                    if(tipo == 1) {
                        v[ct] = new Carro(marca,modelo,cor,potencia);
                    } else if(tipo == 2) {
                        v[ct] = new Motocicleta(marca,modelo,cor,potencia);
                    } else {
                        System.out.println("Tipo invalido!");
                        break;
                    }
                    ct++;
                    break;
                case 2:
                    if(ct>0) {
                        int maisPotente=-1, menosPotente=-1;
                        for(int i=0;i<ct;i++) {
                            if(v[i].cor().equals("vermelho")) {
                                if(maisPotente==-1 && menosPotente==-1) {
                                    maisPotente = i;
                                    menosPotente = i;
                                } else {
                                    if(v[i].potencia() > v[maisPotente].potencia()) {
                                        maisPotente = i;
                                    } else if(v[i].potencia() < v[maisPotente].potencia()) {
                                        menosPotente = i;
                                    }
                                }
                            }
                        }
                        if(maisPotente==-1 && menosPotente==-1) {
                            System.out.println("Nenhum veiculo vermelho registrado!");
                        } else {
                            System.out.println("Marca do veiculo vermelho mais potente: "+v[maisPotente].marca());
                            System.out.println("Marca do veiculo vermelho menos potente: "+v[menosPotente].marca());
                        }
                    } else {
                        System.out.println("Nenhum veiculo registrado!");
                    }
                    break;
            }
        } while(op!=3);
    }
}
