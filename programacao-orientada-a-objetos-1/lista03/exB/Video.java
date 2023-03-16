package exB;

public class Video extends Midia {
    
    private String[] atores;
    private String diretor;
    private int duracao; //em minutos
    private int classificacaoEtaria;

    public Video(String nome, String genero, int tipo, int ano, int nroDeCopias, double preco,
                    String[] atores, String diretor, int duracao, int classificacaoEtaria) {
        
        super(nome,genero,tipo,ano,nroDeCopias,preco);
        this.atores = atores;
        this.diretor = diretor;
        this.duracao = duracao;
        this.classificacaoEtaria = classificacaoEtaria;
    }

    public void mostra() {
        super.mostra();
        System.out.print("Atores: [");
        for(String a: atores) System.out.print(" "+a+" "); //for(int i=0;i<atores.lenght;i++)
        System.out.println("]");
        System.out.println("Diretor: "+diretor);
        System.out.println("Duracao (em minutos): "+duracao);
        System.out.println("Classificacao etaria: "+classificacaoEtaria);
    }
}