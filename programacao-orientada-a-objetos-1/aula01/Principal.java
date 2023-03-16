public class Principal {
    public static void main(String a[]) {
        Pessoa p = new Pessoa();
        Pessoa p2 = new Pessoa();
        p.nome = "Joao";
        System.out.println(p.getCt()+"|"+p2.getCt());
        Pessoa.ct = 3;
        System.out.println(p.getCt()+"|"+p2.getCt());
        p.alteraCt();
        System.out.println(p.getCt()+"|"+p2.getCt());
        p2.ct = 44;
        System.out.println(p.getCt());
    }
}
// javac .\Principal.java
// java Principal