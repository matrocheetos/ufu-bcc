// package prova01;

public class Grafo {
    
    private int vertices[];
    private int numeroDeVertices;
    private int arestas[][]; //representa a matriz de adjacencia

    //O número de vértices é sempre fixo, informado quando o objeto é criado.
    public Grafo(int n) {
        if(n>0) {
            numeroDeVertices = n;
            vertices = new int[n];
            arestas = new int[n][n];
        } else { //para valores inválidos
            numeroDeVertices = 0;
            vertices = new int[0];
            arestas = new int[0][0];
        }
    }

    public void cadastraVertice(int v) {
        if(v<numeroDeVertices && vertices[v]!=1) {
            vertices[v] = 1;
            System.out.println("Vertice cadastrado");
        } else if(vertices[v]==1)
            System.out.println("Vertice ja cadastrado");
        else
            System.out.println("Vertice nao pode ser cadastrado");
    }

    public void cadastraAresta(int v1, int v2) {
        if(v1>=0 && v1<numeroDeVertices && v2>=0 && v2<numeroDeVertices) {
            if(vertices[v1]==1 && vertices[v2]==1) {
                arestas[v1][v2] = 1;
                arestas[v2][v1] = 1;
                System.out.println("Aresta cadastrada");
            } else //vertices[v1] ou vertices[v2] não foi cadastrado
                System.out.println("Aresta nao pode ser cadastrada");
        } else { //v1 ou v2 é inválido
            System.out.println("Aresta nao pode ser cadastrada");
        }
    }

    public boolean verificaVizinho(int v1, int v2) {
        if(arestas[v1][v2] == 1)
            return true;
        else
            return false;
    }

    public void listaVizinhos(int v) {
        System.out.print("Vizinhos de "+(v+1)+":");
        for(int i=0; i<numeroDeVertices; i++) {
            if(arestas[v][i]==1) 
                System.out.print(" "+(i+1));
        }
        System.out.println();
    }

    public void listaVertices() {
        for(int i=0; i<numeroDeVertices; i++) {
            if(vertices[i]==1)
                System.out.print(" "+(i+1));
        }
        System.out.println();
    }

    public void exibeMatrizAdjacencia() {
        for(int i=0; i<numeroDeVertices; i++) {
            
            if(i==0) {
                System.out.print("  ");
                for(int k=1; k<=numeroDeVertices; k++)
                    System.out.print(" "+k);
                System.out.println();
            }

            System.out.print((i+1)+" ");

            for(int j=0; j<numeroDeVertices; j++) {
                System.out.print(" "+arestas[i][j]);
            }
            System.out.println();
        }
    }
}
