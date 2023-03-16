package principal;

import efeito.*;
import forma.*;

public class Principal {
    public static void main(String[] args) {
        Forma quadrado = new Quadrado();
        quadrado = new Textura(quadrado);
        quadrado = new Wireframe(quadrado);

        System.out.println(quadrado.desenhar());
    }
}
