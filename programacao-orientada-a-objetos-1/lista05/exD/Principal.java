package exD;

import java.util.Scanner;

public class Principal {
    
    public static void main(String z[]) {

        Produto p[] = new Produto[10];
        Scanner sc = new Scanner(System.in);
        int op = 0, ct = 0;

        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Registrar produto");
            System.out.println("2) Calcular preco total de uma categoria");
            System.out.println("3) Calcular preco total dos produtos registrados");
            System.out.println("4) Sair");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.print("ID: ");
                    int id = sc.nextInt();
                    System.out.print("Ano de producao: ");
                    int ano = sc.nextInt();
                    System.out.print("Unidade de venda: ");
                    sc.nextLine(); //limpa buffer
                    String unidade = sc.nextLine();
                    System.out.print("Categoria: ");
                    String categoria = sc.nextLine();
                    System.out.print("Preco: ");
                    double preco = sc.nextDouble();

                    System.out.print("Tipo de produto (1)Eletrodomestico, (2)Vinho ou (3)Cafe: ");
                    int tipo = sc.nextInt();
                    if(tipo == 1) {
                        p[ct] = new Eletrodomestico(id,ano,unidade,categoria,preco);
                    } else if(tipo == 2) {
                        p[ct] = new Vinho(id,ano,unidade,categoria,preco);
                    } else if(tipo == 3) {
                        p[ct] = new Cafe(id,ano,unidade,categoria,preco);
                    } else {
                        System.out.println("Tipo invalido!");
                    }
                    ct++;
                    break;
                case 2:
                    if(ct>0) {
                        double total = 0;
                        System.out.print("Categoria escolhida: ");
                        sc.nextLine(); //limpa buffer
                        String categoriaEscolhida = sc.nextLine();
                        for(int i=0;i<ct;i++) {
                            if(p[i].categoria().equals(categoriaEscolhida)) {
                                total = total + p[i].preco();
                            }
                        }
                        System.out.println("Preco total da categoria '"+categoriaEscolhida+"': R$ "+total);
                    } else {
                        System.out.println("Nenhum produto registrado!");
                    }
                    break;
                case 3:
                    if(ct>0) {
                        double total = 0;
                        for(int i=0;i<ct;i++) {
                            total = total + p[i].preco();
                        }
                        System.out.println("Preco total dos produtos: R$ "+total);
                    } else {
                        System.out.println("Nenhum produto registrado!");
                    }
                    break;
            }
        } while(op!=4);
    }
}
