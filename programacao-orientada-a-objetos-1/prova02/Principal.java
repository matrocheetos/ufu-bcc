package prova02;

import java.util.Scanner;

public class Principal {
    
    public static void main(String z[]) {

        RepositorioClasse r[] = new RepositorioClasse[4];
        for(int ir=0;ir<r.length;ir++)
            r[ir] = new RepositorioClasse(); //inicializa todos os repositorios
        Scanner sc = new Scanner(System.in);
        int op = 0;

        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Inserir uma pessoa em um repositorio");
            System.out.println("2) Exibir todas as pessoas em todos os repositorios");
            System.out.println("3) Pesquisar uma pessoa em todos os repositorios");
            System.out.println("4) Duplicar um repositorio");
            System.out.println("5) Repositorio diferenca");
            System.out.println("6) Sair");
            System.out.print("Opcao: ");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.print("CPF: ");
                    sc.nextLine(); //limpa buffer
                    String CPF = sc.nextLine();
                    System.out.print("Nome: ");
                    String nome = sc.nextLine();
                    System.out.print("Repositorio (1 a 4): ");
                    int rep = sc.nextInt()-1;
                    r[rep].armazenarPessoa(CPF,nome);
                    break;
                case 2:
                    for(int i=0;i<r.length;i++) {
                        System.out.println("===========");
                        System.out.println("Repositorio "+(i+1)+")");
                        for(int j=0;j<=r[i].getCtPessoas();j++) {
                            r[i].recuperarProxima();
                        }
                    }
                    break;
                case 3:
                    System.out.print("CPF: ");
                    sc.nextLine(); //limpa buffer
                    String pesquisa = sc.nextLine();

                    for(int i=0;i<r.length;i++) {
                        System.out.println("Repositorio "+(i+1)+")");
                        r[i].recuperarPorCPF(pesquisa);
                    }
                    break;
                case 4:
                    System.out.print("Repositorio a ser duplicado (1 a 4): ");
                    int original = sc.nextInt()-1;
                    System.out.print("Repositorio que recebera os dados (1 a 4): ");
                    int duplicado = sc.nextInt()-1;
                    r[duplicado] = r[original];
                    break;
                case 5:
                    System.out.print("Repositorio A (1 a 4): ");
                    int A = sc.nextInt()-1;
                    System.out.print("Repositorio B (1 a 4): ");
                    int B = sc.nextInt()-1;
                    System.out.print("Repositorio C (1 a 4): ");
                    int C = sc.nextInt()-1;

                    r[C].repositorioDiferenca(r[A],r[B]);
                    break;
            }
        } while (op!=6);
        sc.close(); //fecha o Scanner
    }
}
