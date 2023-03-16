package prova02;

public class RepositorioClasse implements Repositorio {

    private int ctPessoas;
    private static int ctProxima = 0;
    private PessoaClasse p[] = new PessoaClasse[20];

    public int getCtPessoas() {return ctPessoas;}

    public RepositorioClasse() {
        this.ctPessoas = 0;
    }

    @Override
    public void armazenarPessoa(String CPF, String nome) {
        this.p[ctPessoas] = new PessoaClasse(CPF,nome);
        this.ctPessoas++;
    }

    @Override
    public void recuperarPorCPF(String CPF) {
        for(int i=0;i<ctPessoas;i++) {
            if(p[i].CPF().equals(CPF)) {
                System.out.println("Nome: "+p[i].nome());
                return;
            }
        }
        System.out.println("CPF nao encontrado");
    }

    @Override
    public void recuperarPrimeira() {
        if(ctPessoas>0) {
            System.out.println("CPF: "+p[0].CPF());
            System.out.println("Nome: "+p[0].nome());
        } else
            System.out.println("Nenhuma pessoa registrada nesse repositorio");
    }

    @Override
    public void recuperarProxima() {
        if(ctProxima<ctPessoas) {
            System.out.println("CPF: "+p[ctProxima].CPF());
            System.out.println("Nome: "+p[ctProxima].nome());
            ctProxima++;
        } else
            ctProxima = 0;
    }

    // usuário informa três repositórios: A, B, C, e o programa insere em C todas as pessoas de A que não estiverem em B
    public void repositorioDiferenca(RepositorioClasse A, RepositorioClasse B) {
        int dadosInseridos=0;
        for(int i=0;i<A.getCtPessoas();i++) { //percorre repositorio A
            for(int j=0;j<B.getCtPessoas();j++) { //percorre repositorio B
                if( A.p[i].CPF().equals(B.p[j].CPF()) ){ //encontra pessoa em A e B
                    break;
                } else if(j+1 == B.getCtPessoas()) { //termina de percorrer B e não encontra alguém de A
                    this.armazenarPessoa(A.p[i].CPF(),A.p[i].nome());
                    dadosInseridos++;
                }
            }
        }
        System.out.println("Foram inseridas "+dadosInseridos+" pessoas em C");
    }
}
