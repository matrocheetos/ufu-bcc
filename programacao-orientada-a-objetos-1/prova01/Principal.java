// package prova01;

import java.util.Scanner;

public class Principal {

    public static void main(String a[]) {

        Grafo g = new Grafo(0);
        Scanner sc = new Scanner(System.in);
        int op = 0;
        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Criar grafo");
            System.out.println("2) Cadastrar vertice");
            System.out.println("3) Cadastrar aresta");
            System.out.println("4) Verificar se vertices sao vizinhos");
            System.out.println("5) Listar vizinhos de um vertice");
            System.out.println("6) Listar todos os vertices");
            System.out.println("7) Exibir matriz de adjacencia");
            System.out.println("8) Sair");
            System.out.print("OPCAO: ");
            op = sc.nextInt();

            // Observação: para melhor interatividade com o programa, o usuário informa
            // posições iniciando em 1 para o vetor de vértices, enquanto o programa
            // armazena as posições iniciando em 0 (ex: posição 1 = vertices[0]).

            switch (op) {
                case 1:
                    System.out.print("Quantidade de vertices: ");
                    int n = sc.nextInt();
                    g = new Grafo(n);
                    System.out.println("Grafo criado");
                    break;
                case 2:
                    System.out.print("Vertice a ser cadastrado: ");
                    int v = sc.nextInt();
                    g.cadastraVertice(v-1);
                    break;
                case 3:
                    System.out.print("Vertices a serem conectados pela aresta: ");
                    int a1 = sc.nextInt();
                    int a2 = sc.nextInt();
                    g.cadastraAresta(a1-1,a2-1);
                    break;
                case 4:
                    System.out.print("Vertices a serem verificados: ");
                    int v1 = sc.nextInt();
                    int v2 = sc.nextInt();
                    if(g.verificaVizinho(v1-1, v2-1))
                        System.out.println("Os vertices sao vizinhos");
                    else
                        System.out.println("Os vertices nao sao vizinhos");
                    break;
                case 5:
                    System.out.print("Vertice: ");
                    int l = sc.nextInt();
                    g.listaVizinhos(l-1);
                    break;
                case 6:
                    System.out.print("Lista de vertices cadastrados:");
                    g.listaVertices();
                    break;
                case 7:
                    g.exibeMatrizAdjacencia();
                    break;
            }
        } while (op!=8);
    }
}