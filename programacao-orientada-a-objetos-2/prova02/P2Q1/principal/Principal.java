package principal;

import composite.*;

import java.util.ArrayList;
import java.util.List;

public class Principal {
    public static void main(String[] args) {

        Component c1 = new ComandoSimples("ls -la");

        List<Component> bloco1 = new ArrayList<>();
        bloco1.add(c1);
        bloco1.add(new ComandoSimples("cat arquivo.txt"));
        bloco1.add(new ComandoSimples("rm -r ./"));
        Component c2 = new ComandoComposto(bloco1);

        Component c3 = new ComandoCondicional(c1);

        Component c4 = new ComandoCondicional(c2);

        System.out.println("c1:");
        c1.execute();
        System.out.println("\nc2:");
        c2.execute();
        System.out.println("\nc3:");
        c3.execute();
        System.out.println("\nc4:");
        c4.execute();
    }
}
