package prova03;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Reserva {
    
    private String cpf_hospede, numero_acomodacao, data_entrada, data_saida;
    private boolean tem_cadastro;

    public Reserva(String cpf_hospede, String numero_acomodacao, String data_entrada, String data_saida, boolean tem_cadastro) {
        this.cpf_hospede = cpf_hospede;
        this.numero_acomodacao = numero_acomodacao;
        this.data_entrada = data_entrada;
        this.data_saida = data_saida;
        this.tem_cadastro = tem_cadastro;
    }
    
    public boolean salvarArquivo() {
        BufferedWriter escritor = null;
        try {
            escritor = new BufferedWriter(new FileWriter(new File("Reservas.txt"), true));
            escritor.write("CPF: "+cpf_hospede+"; Nro acomodacao: "+numero_acomodacao+
                            "; Data de entrada: "+data_entrada+"; Data de saída: "+data_saida+
                            "; É cadastrado: "+tem_cadastro+"\n");
            escritor.flush();
            escritor.close();
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public String getCpf_hospede() {
        return cpf_hospede;
    }

    public String getNumero_acomodacao() {
        return numero_acomodacao;
    }
    
}
