package exA;

import java.util.Scanner;

public class Principal {

    public static void main(String a[]) {
        
        Forma f[] = new Forma[15];
        Scanner sc = new Scanner(System.in);
        int op = 0, ct = 0;
        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Criar circulo");
            System.out.println("2) Criar quadrado");
            System.out.println("3) Criar triangulo");
            System.out.println("4) Criar esfera");
            System.out.println("5) Criar cubo");
            System.out.println("6) Criar tetraedro");
            System.out.println("7) Descrever objetos");
            System.out.println("8) Mostrar area dos objetos");
            System.out.println("9) Verificar se circulos se interceptam");
            System.out.println("10) Sair");
            op = sc.nextInt();

            if(op>=1 && op<=6) { // criar forma
                System.out.print("ID: ");
                sc.nextLine(); //limpa buffer
                String id = sc.nextLine();
                System.out.print("Cor: ");
                String cor = sc.nextLine();

                System.out.print("Pos x: ");
                int x = sc.nextInt();
                System.out.print("Pos y: ");
                int y = sc.nextInt();
                int z = 0;
                if(op>=4 && op<=6) {
                    System.out.print("Pos z: ");
                    z = sc.nextInt();
                }

                if(op==1 || op==4) {
                    System.out.print("Raio: ");
                    float raio = sc.nextFloat();
                    if(op==1)
                        f[ct] = new Circulo(id,cor,x,y,raio);
                    else
                        f[ct] = new Esfera(id,cor,x,y,z,raio);
                }
                if(op==2 || op==5) {
                    System.out.print("Lado: ");
                    float lado = sc.nextFloat();
                    if(op==2)
                        f[ct] = new Quadrado(id,cor,x,y,lado);
                    else
                        f[ct] = new Cubo(id,cor,x,y,z,lado);
                }
                if(op==3 || op==6) {
                    System.out.print("Base: ");
                    float base = sc.nextFloat();
                    System.out.print("Altura: ");
                    float altura = sc.nextFloat();
                    if(op==3)
                        f[ct] = new Triangulo(id,cor,x,y,base,altura);
                    else {
                        System.out.print("Altura da base: ");
                        float alturaDaBase = sc.nextFloat();
                        f[ct] = new Tetraedro(id,cor,x,y,z,base,altura,alturaDaBase);
                    }
                }
                ct++;
            } else if(op==7) { // descrever objetos
                for(int i=0;i<ct;i++) {
                    System.out.println("Objeto "+i+")");
                    f[i].mostra();
                }
            } else if(op==8) { // mostrar area
                for(int i=0;i<ct;i++) {
                    if(f[i] instanceof FormaBidimensional)  {
                        System.out.println("Area "+i+" "+f[i].getID()+": "+f[i].obterArea());
                    } else {
                        System.out.println("Area "+i+" "+f[i].getID()+": "+f[i].obterVolume());
                    }
                }
            } else if(op==9) { //verificar se circulos/esferas interceptam
                System.out.print("Objeto 1: ");
                int x = sc.nextInt();
                System.out.print("Objeto 2: ");
                int y = sc.nextInt();
                if(f[x] instanceof Circulo && f[y] instanceof Circulo) {
                    if(((Circulo)f[x]).interceptam(f[y]))
                        System.out.println("Os circulos interceptam");
                    else
                        System.out.println("Os circulos nao interceptam");
                } else if(f[x] instanceof Esfera && f[y] instanceof Esfera) {
                    if(f[x].interceptam(f[y]))
                        System.out.println("As esferas interceptam");
                    else
                        System.out.println("As esferas nao interceptam");
                }
            }

        } while (op!=10);
    }
}
