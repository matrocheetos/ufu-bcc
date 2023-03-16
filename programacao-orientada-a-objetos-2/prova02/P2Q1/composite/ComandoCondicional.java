package composite;

public class ComandoCondicional implements Component {
    private Component csimples;
    private Component ccomposto;

    public ComandoCondicional(Component c){
        if(c.getClass().getName() == "composite.ComandoSimples"){
            this.csimples = c;
        }else{
            this.ccomposto = c;
        }
    }

    public void execute(){
        double aleatorio = Math.random();
        if(aleatorio<0.5){
            System.out.println("if executado");
            if(this.csimples!=null)
                this.csimples.execute();
            else
                System.out.println("comando eh composto");
        }else{
            System.out.println("else executado");
            if(ccomposto!=null)
                this.ccomposto.execute();
            else
                System.out.println("comando eh simples");
        }
    }
}
