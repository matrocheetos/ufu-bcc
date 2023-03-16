package principal;

import automato.Automato;

public class Principal {
    public static void main(String[] args) {
        Automato automato1 = new Automato("aaacdb");
        Automato automato2 = new Automato("ababacdaaac");
        Automato automato3 = new Automato("abcdb");
        Automato automato4 = new Automato("acda");
        Automato automato5 = new Automato("acdbdb");
    }
}
