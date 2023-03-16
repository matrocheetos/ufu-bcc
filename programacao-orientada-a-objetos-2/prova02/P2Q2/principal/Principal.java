package principal;

import fabricas.*;
import objetos.Copo;
import objetos.Garrafa;
import objetos.Prato;

public class Principal {
    public static void main(String[] args) {
        ObjetoAbstractFactory fabrica = obterFabrica(args[0]); // fabrica recebida em tempo de execucao ("2d" ou outro(3d))

        Copo copo = fabrica.fabricarCopo();
        Garrafa garrafa = fabrica.fabricarGarrafa();
        Prato prato = fabrica.fabricarPrato();

        copo.desenhar();
        garrafa.desenhar();
        prato.desenhar();
    }

    public static ObjetoAbstractFactory obterFabrica(String s){
        if(s.equals("2d")){
            return new Objeto2DFactory();
        }else{
            return new Objeto3DFactory();
        }
    }
}
