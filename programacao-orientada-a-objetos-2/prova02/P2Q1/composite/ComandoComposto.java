package composite;

import java.util.List;

public class ComandoComposto implements Component {
    private List<Component> comando;

    public ComandoComposto(List<Component> comando){
        this.comando = comando;
    }

    public void execute(){
        for(int i=0; i<this.comando.size(); i++)
            this.comando.get(i).execute();
    }
}
