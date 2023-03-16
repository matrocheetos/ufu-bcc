public class Tempo {

    private int hora;
    private int minuto;
    private int segundo;

    public int getHH() {
        return hora;
    }
    public int getMM() {
        return minuto;
    }
    public int getSS() {
        return segundo;
    }

    public void setHH(int h) {
        if(h>=0 && h<=23)
            hora = h;
        else
            hora = 0;
    }
    public void setMM(int m) {
        if(m>=0 && m<=59)
            minuto = m;
        else
            minuto = 0;
    }
    public void setSS(int s) {
        if(s>=0 && s<=59)
            segundo = s;
        else
            segundo = 0;
    }

    public Tempo(int h, int m, int s) {
        setHH(h);
        setMM(m);
        setSS(s);
    }

    public String mostraTempo24() {
        return hora+":"+minuto+":"+segundo;
    }
    public String mostraTempo12() {
        if(hora<=12 && hora>0)
            return hora+":"+minuto+":"+segundo+"AM";
        else if(hora==0)
            return "12:"+minuto+":"+segundo+"AM";
        else
            return (hora-12)+":"+minuto+":"+segundo+"PM";
    }

    public void ajustaTempoAdd() {
        if(minuto<59)
            setMM(minuto+1);
        else{
            setHH(hora+1);
            setMM(0);
        }
    }
    public void ajustaTempoSub() {
        if(minuto>0)
            setMM(minuto-1);
        else{
            if(hora>0){
                setHH(hora-1);
                setMM(59);
            }else{
                setHH(23);
                setMM(59);
            }
        }
    }
}
