package exB;

import java.util.Scanner;

public class Principal {
    
    public static void main(String z[]) {

        Audio a[] = new Audio[5];
        Video v[] = new Video[5];
        VHS vhs[] = new VHS[5];
        Scanner sc = new Scanner(System.in);
        int op = 0;
        int cta=0, ctv=0, ctvhs=0;
        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Adicionar midia");
            System.out.println("2) Mostrar registros");
            System.out.println("3) Sair");
            System.out.print("OPCAO: ");
            op = sc.nextInt();

            switch (op) {
                case 1:
                    System.out.print("Nome: ");
                    sc.nextLine(); //limpa buffer
                    String nome = sc.nextLine();
                    System.out.print("Genero: ");
                    String genero = sc.nextLine();
                    System.out.print("Tipo [(1)audio, (2)video]: ");
                    int tipo = sc.nextInt();
                    System.out.print("Ano: ");
                    int ano = sc.nextInt();
                    System.out.print("Numero de copias: ");
                    int nroDeCopias = sc.nextInt();
                    System.out.print("Preco de locacao: ");
                    double preco = sc.nextDouble();
                    
                    if(tipo==1) { //audio
                        System.out.print("Cantor: ");
                        sc.nextLine(); //limpa buffer
                        String cantor = sc.nextLine();
                        System.out.print("Numero de faixas: ");
                        int nroDeFaixas = sc.nextInt();

                        Audio x = new Audio(nome,genero,tipo,ano,nroDeCopias,preco,cantor,nroDeFaixas);
                        a[cta] = x;
                        cta++;
                    } else if(tipo==2) { //video
                        System.out.print("Numero de atores: ");
                        int totalAtores = sc.nextInt();
                        String atores[] = new String[totalAtores];
                        System.out.print("Nomes dos atores: ");
                        sc.nextLine(); //limpa buffer
                        for(int i=0;i<totalAtores;i++)
                            atores[i] = sc.nextLine();
                        System.out.print("Diretor: ");
                        String diretor = sc.nextLine();
                        System.out.print("Duracao (em minutos): ");
                        int duracao = sc.nextInt();
                        System.out.print("Classificacao etaria: ");
                        int classificacaoEtaria = sc.nextInt();

                        System.out.print("Eh VHS? ");
                        if(sc.nextBoolean()) {
                            System.out.print("Esta rebobinada? ");
                            boolean rebobinada = sc.nextBoolean();
                            
                            VHS x = new VHS(nome,genero,tipo,ano,nroDeCopias,preco,atores,diretor,duracao,classificacaoEtaria,rebobinada);
                            vhs[ctvhs] = x;
                            ctvhs++;
                        } else {
                            Video x = new Video(nome,genero,tipo,ano,nroDeCopias,preco,atores,diretor,duracao,classificacaoEtaria);
                            v[ctv] = x;
                            ctv++;
                        }
                    }
                    break;
                case 2:
                    System.out.println("CDs:");
                    for(int i=0;i<cta;i++) { //audio
                        System.out.println("---- "+i+" ----");
                        a[i].mostra();
                    }
                    System.out.println("DVDs:");
                    for(int i=0;i<ctv;i++) { //video
                        System.out.println("---- "+i+" ----");
                        v[i].mostra();
                    }
                    System.out.println("VHS:");
                    for(int i=0;i<ctvhs;i++) { //vhs
                        System.out.println("---- "+i+" ----");
                        vhs[i].mostra();
                    }
                    break;
            }
        } while (op!=3);
    }
}