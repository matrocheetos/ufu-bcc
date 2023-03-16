package exA;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Principal {
    
    public static void main(String a[]) {

        ArrayList<Empregado> e = new ArrayList<Empregado>();
        Scanner sc = new Scanner(System.in);
        int op = 0;

        do {
            System.out.println("--- MENU ---");
            System.out.println("1) Instanciar lista de 5 empregados");
            System.out.println("2) Registrar empregados");
            System.out.println("3) Buscar funcionário por CPF");
            System.out.println("4) Listar salarios maiores que do empregado");
            System.out.println("5) Ordenar vetor em ordem crescente");
            System.out.println("6) Sair");
            System.out.print("OPCAO: ");
            op = sc.nextInt();

            switch(op) {
                case 1:
                    if(e.size()!=0)
                        e.trimToSize();
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
                        e.add(em);
                    }
                    break;
                case 3:
                    System.out.print("CPF do empregado: ");
                    sc.nextLine(); //limpa buffer
                    String CPF = sc.nextLine();

                    for(int i=0;i<e.size();i++){
                        if(e.get(i).getCPF() == CPF) {
                            System.out.println("Idade: "+e.get(i).getIdade());
                            System.out.println("Salario: "+e.get(i).getSalario());
                            break;
                        }
                    }
                    System.out.println("Empregado nao encontrado");
                    break;
                case 4:
                    System.out.print("Empregado (1 a 5): ");
                    int emp = sc.nextInt()-1;
                    for(int i=0;i<e.size();i++){
                        if(e.get(i).getSalario() > e.get(emp).getSalario()) {
                            System.out.println("Empregado "+(i+1)+")");
                            System.out.println("Salario: "+e.get(i).getSalario());
                            break;
                        }
                    }
                    break;
                case 5:
                    Collections.sort(e);
                    System.out.println("Ordenado de acordo com a idade");
                    break;
            }
        } while(op!=6);

    }
}
