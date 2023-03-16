package prova02;

public class PessoaClasse implements Pessoa {
    
    private String CPF, nome;

    public String CPF() {return CPF;}
    public String nome() {return nome;}

    public PessoaClasse(String CPF, String nome) {
        this.CPF = CPF;
        this.nome = nome;
    }
}
