package exA;

import java.util.Scanner;
import java.util.HashMap;
import java.util.Collections;

public class Principal {
    
    public static void main(String a[]) {

        HashMap<Integer,Empregado> e = new HashMap<Integer,Empregado>();
        Scanner sc = new Scanner(System.in);
        int op = 0;

        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Instanciar hashmap de 5 empregados");
            System.out.println("2) Registrar empregados");
            System.out.println("3) Buscar funcionario por CPF");
            System.out.println("4) Listar maior e menor salario");
            System.out.println("5) Sair");
            System.out.print("OPCAO: ");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    for(int i=0;i<5;i++){
                        e.put(i,new Empregado(0,0,0));
                    }
                    break;
                case 2:
                    for(int i=0;i<5;i++) {
                        System.out.println("Empregado "+(i+1)+")");
                        System.out.print("CPF: ");
                        sc.nextLine(); //limpa buffer
                        String CPF = sc.nextLine();
                        System.out.print("Idade: ");
                        int idade = sc.nextInt();
                        System.out.print("Salario: ");
                        double salario = sc.nextDouble();

                        Empregado em = new Empregado(CPF,idade,salario);
                        e.put(i,em);
                    }
                    break;
                case 3:
                    System.out.print("CPF do empregado: ");
                    sc.nextLine(); //limpa buffer
                    String CPF = sc.nextLine();

                        if(e.containsValue(CPF)) {
                            System.out.println("Idade: "+e.get(i).getIdade());
                            System.out.println("Salario: "+e.get(i).getIdade());
                            break;
                        }
                    }
                    System.out.println("Empregado nao encontrado");
                    break;
                case 4:
                    double maior=e.get(0).getSalario(),menor=e.get(0).getSalario();
                    for(int i=1;i<e.size();i++) {
                        if(e.get(i).getSalario()>maior)
                            maior = e.get(i).getSalario();
                        else if(e.get(i).getSalario()<menor)
                            menor = e.get(i).getSalario();
                    }
                    break;
            }
        } while(op!=5);

    }
}
