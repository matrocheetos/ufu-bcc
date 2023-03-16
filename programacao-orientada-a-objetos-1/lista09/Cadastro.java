package lista09;

public class Cadastro {
    
    private String nome, cpf, data_nasc, numero_conta, senha, email;
    private int sexo;
    private boolean noticias;

    public Cadastro(String nome, String cpf, String data_nasc, String numero_conta, String senha, String email, int sexo, boolean noticias) {
        this.nome = nome;
        this.cpf = cpf;
        this.data_nasc = data_nasc;
        this.numero_conta = numero_conta;
        this.senha = senha;
        this.email = email;
        this.sexo = sexo;
        this.noticias = noticias;
    }

    public String getNome() {
        return nome;
    }

    public String getCpf() {
        return cpf;
    }

    public String getData_nasc() {
        return data_nasc;
    }

    public String getNumero_conta() {
        return numero_conta;
    }

    public String getSenha() {
        return senha;
    }

    public String getEmail() {
        return email;
    }

    public int getSexo() {
        return sexo;
    }

    public boolean isNoticias() {
        return noticias;
    }
    
}
