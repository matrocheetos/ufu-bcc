import java.util.Scanner;

public class Principal {

    public static void main(String a[]) {

        Triangulo v[] = new Triangulo[10];
        Scanner sc = new Scanner(System.in);
        int op = 0;
        do{
            System.out.println("--- MENU ---");
            System.out.println("1) Cadastrar triangulo");
            System.out.println("2) Mostrar triangulos cadastrados");
            System.out.println("3) Mostrar numero de triangulos equilateros");
            System.out.println("4) Mostrar o triangulo cadastrado com o maior perimetro");
            System.out.println("5) Sair");
            System.out.println("OPCAO: ");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    System.out.println("Lado 1: ");
                    int l1 = sc.nextInt();
                    System.out.println("Lado 2: ");
                    int l2 = sc.nextInt();
                    System.out.println("Lado 3: ");
                    int l3 = sc.nextInt();
                    Triangulo t = new Triangulo();
                    v[Triangulo.getCt()] = t;
                    t.cadastraTriangulo(l1,l2,l3);
                    break;
                case 2:
                    for(int i=0; i<Triangulo.getCt();i++) {
                        //System.out.println(v[i].getL1()+" - "+v[i].getL2+" - "+v[i].getL3);
                        System.out.println("Triangulo "+i+": "+v[i].mostraDados());
                    }
                    break;
                case 3:
                    int c=0;
                    for(int i=0;i<Triangulo.getCt();i++) {
                        if(v[i].verificaTipo().equals("equilatero"))
                            c++;
                    }
                    System.out.println("Numero de triangulos equilateros: "+c);
                    break;
                case 4:
                    Triangulo maior = v[0];
                    for(int i=1;i<Triangulo.getCt();i++) {
                        if(v[i].calculaPerimetro() > maior.calculaPerimetro)
                            maior = v[i];
                    }
                    System.out.println("Triangulo com maior perimetro:");
                    System.out.println(maior.mostraDados());
                    break;
            }

        } while (op!=5);
    }
}
