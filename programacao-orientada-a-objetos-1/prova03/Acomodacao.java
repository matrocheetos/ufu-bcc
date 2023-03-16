package prova03;

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;

public class Acomodacao {
    
    private String numero;
    private double preco;
    private int capacidade, categoria;
    private boolean status; //ocupado ou nao
    
    public Acomodacao(String numero, int capacidade, double preco, int categoria, boolean status) {
        this.categoria = categoria;
        this.numero = numero;
        this.capacidade = capacidade;
        this.preco = preco;
        this.status = status;
    }
    
    public boolean salvarArquivo() {
        BufferedWriter escritor = null;
        try {
            escritor = new BufferedWriter(new FileWriter(new File("Acomodacoes.txt"), true));
            escritor.write("Numero: "+numero+"; Preço: "+preco+"; Capacidade:"+capacidade+
                            "; Categoria: "+categoria+"\n");
            escritor.flush();
            escritor.close();
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
    
    public double valorTotal(boolean desconto) {
        if(desconto)
            return (preco*0.8);
        else
            return preco;
    }
    
    public String getNumero() {
        return numero;
    }

    public int getCapacidade() {
        return capacidade;
    }

    public double getPreco() {
        return preco;
    }
    
    public int getCategoria() {
        return categoria;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

}
