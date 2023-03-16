package exA;

import java.util.Scanner;

public class Principal {
    
    public static void main(String z[]) {

        Funcionario f[] = new Funcionario[5];
        Scanner sc = new Scanner(System.in);
        int op = 0, ct = 0;
        
        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Registrar funcionario");
            System.out.println("2) Calcular salarios");
            System.out.println("3) Mostrar media salarial de cada tipo de funcionario");
            System.out.println("4) Sair");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.print("Nome: ");
                    sc.nextLine(); //limpa buffer
                    String nome = sc.nextLine();
                    System.out.print("Matricula: ");
                    String matricula = sc.nextLine();
                    System.out.print("Salario base: ");
                    double salario_base = sc.nextDouble();

                    System.out.print("Tipo de funcionario (1)Gerente, (2)Assistente ou (3)Vendedor: ");
                    int tipo = sc.nextInt();
                    if(tipo == 1) {
                        f[ct] = new Gerente(nome,matricula,salario_base);
                    } else if(tipo == 2) {
                        f[ct] = new Assistente(nome,matricula,salario_base);
                    } else if(tipo == 3) {
                        System.out.print("Comissao: ");
                        double comissao = sc.nextDouble();
                        f[ct] = new Vendedor(nome,matricula,salario_base,comissao);
                    } else {
                        System.out.println("Tipo invalido!");
                        break;
                    }
                    ct++;
                    break;
                case 2:
                    System.out.println("Salarios:");
                    for(int i=0;i<ct;i++) {
                        System.out.println("Funcionario "+i+") R$ "+f[i].calcula_salario());
                    }
                    break;
                case 3:
                    double mediaG=0, mediaA=0, mediaV=0;
                    for(int i=0;i<ct;i++) {
                        if(f[i] instanceof Gerente) {
                            mediaG = mediaG + f[i].calcula_salario();
                        } else if(f[i] instanceof Assistente) {
                            mediaA = mediaA + f[i].calcula_salario();
                        } else if(f[i] instanceof Vendedor) {
                            mediaV = mediaV + f[i].calcula_salario();
                        }
                    }
                    System.out.println("Media salarial de gerentes: "+mediaG);
                    System.out.println("Media salarial de assistentes: "+mediaA);
                    System.out.println("Media salarial de vendedores: "+mediaV);
                    break;
            }
        } while(op!=4);
    }
}
