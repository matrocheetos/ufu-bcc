package prova03;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Hospede {
    
    private String nome, CPF, idade;

    public Hospede(String nome, String CPF, String idade) {
        this.nome = nome;
        this.CPF = CPF;
        this.idade = idade;
    }
    
    public boolean salvarArquivo() {
        BufferedWriter escritor = null;
        try {
            escritor = new BufferedWriter(new FileWriter(new File("Hospedes.txt"), true));
            escritor.write("Nome: "+nome+"; CPF: "+CPF+"; Idade: "+idade+"\n");
            escritor.flush();
            escritor.close();
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public String getCPF() {
        return CPF;
    }
    
    
}
