// CODIGO DO PROFESSOR NO TEAMS

public class Triangulo {
    
    private static int ct = 0;
    private int l1;
    private int l2;
    private int l3;

    public int getCt() {
        return ct;
    }

    public void cadastraTriangulo(int la, int lb, int lc) {
        setL1(la);
        setL2(lb);
        setL3(lc);
        ct++;
    }

    // getters
    public int getL1() {
        return l1;
    }

    public int getL2() {
        return l2;
    }

    public int getL3() {
        return l3;
    }
    // setters
    public void setL1(int l){
        l1 = l;
    }

    public void setL2(int l){
        l2 = l;
    }

    public void setL3(int l){
        l3 = l;
    }
    // ===

    public int calculaPerimetro() {
        return l1+l2+l3;
    }

    public String verificaTipo() {
        if((l1==l2) && (l2==l3))
            return "equilatero";
        else if((l1!=l2) && (l2!=l3) && (l1!=l3))
            return "escaleno";
        else
            return "isosceles";
    }

    public String mostraDados() {
        return l1+" - "+l2+" - "+l3;
    }
}
