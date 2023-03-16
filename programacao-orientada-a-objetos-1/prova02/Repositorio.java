package prova02;

public interface Repositorio {
    
    void armazenarPessoa(String CPF,String nome);
    void recuperarPorCPF(String CPF);
    void recuperarPrimeira();
    void recuperarProxima();

}
