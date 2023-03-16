package composite;

public class ComandoSimples implements Component {
    private String comando;

    public ComandoSimples(String comando){
        this.comando = comando;
    }

    public void execute(){
        System.out.println(this.comando);
    }
}
