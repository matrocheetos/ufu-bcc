package mvc_controle;

public class Controle {
    private Command[] c = new Command[5];

    public void setCommand(Command c, int i){
        this.c[i] = c;
    }

    public void pressionar(int i){
        this.c[i].execute();
    }

    public void executa(Command c){
        c.execute();
    }

}
