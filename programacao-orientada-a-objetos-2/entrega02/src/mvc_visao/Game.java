package mvc_visao;

import composite_fase.*;
import fabricas.SimpleMedievalFactory;
import mvc_controle.*;
import mvc_modelo.InimigoGrafico;
import mvc_modelo.PersonagemGrafico;
import personagem.*;
import principal.Constantes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Game extends JPanel {
    private static Personagem p;
    private static PersonagemGrafico jogador;

    private static Controle c;
    private static Atacar a;
    private static Fase labirinto;
    private static InimigoGrafico[] inimigos;
    private static int qntInimigo;
    boolean moveCima, moveBaixo, moveDireita, moveEsquerda;

    public Game(){
        KeyListener listener = new MyKeyListener();
        addKeyListener(listener);
        setFocusable(true);

        JLabel vida = new JLabel("Vida: 70");
        this.add(vida);
        vida.setVisible(true);
        vida.setHorizontalTextPosition(0);
        vida.setVerticalTextPosition(0);

        p = new PersonagemMedieval05("Jogador 1");
        jogador = new PersonagemGrafico(p, (Constantes.coordX)/2, (Constantes.coordY)/2);

        moveCima = false;
        moveBaixo = false;
        moveDireita = false;
        moveEsquerda = false;

        c = new Controle();
        c.setCommand(new MoverEsquerda(jogador), 0);
        c.setCommand(new MoverDireita(jogador), 1);
        c.setCommand(new MoverCima(jogador), 2);
        c.setCommand(new MoverBaixo(jogador), 3);

        a = new Atacar(jogador);

        SimpleMedievalFactory f = SimpleMedievalFactory.getInstance();
        Personagem inimigo1 = f.createPersonagem();
        Personagem inimigo2 = f.createPersonagem();
        Personagem inimigo3 = f.createPersonagem();

        labirinto =
                new Sala(
                        new Sala(
                                new Folha02(),
                                new Sala(
                                        new Folha01(), new Folha02(), inimigo1),
                                inimigo2),
                        new Folha02(), inimigo3);

        //labirinto = labirinto.getCaminho(1);
        //labirinto.isSala();

        inimigos = new InimigoGrafico[Constantes.maxInimigos];
        int x = Constantes.coordX/Constantes.maxInimigos;
        int y = Constantes.coordY / 4;
        Personagem ini = labirinto.getInimigo();

        for(int i =0; i < Constantes.maxInimigos; i++){
            inimigos[i] = new InimigoGrafico(ini, x*i, y);
            jogador.addObserver(inimigos[i]);
        }

        qntInimigo = Constantes.maxInimigos;


    }

    public class MyKeyListener implements KeyListener {

        @Override
        public void keyTyped(KeyEvent e) {

        }

        @Override
        public void keyPressed(KeyEvent e) {
            if (e.getKeyCode() == KeyEvent.VK_LEFT)
                moveEsquerda = true;

            if (e.getKeyCode() == KeyEvent.VK_RIGHT)
                moveDireita = true;

            if (e.getKeyCode() == KeyEvent.VK_UP)
                moveCima = true;

            if (e.getKeyCode() == KeyEvent.VK_DOWN)
                moveBaixo = true;

            if (e.getKeyCode() == KeyEvent.VK_SPACE)
                a.execute(inimigos);
        }

        @Override
        public void keyReleased(KeyEvent e) {
            if (e.getKeyCode() == KeyEvent.VK_LEFT)
                moveEsquerda = false;

            if (e.getKeyCode() == KeyEvent.VK_RIGHT)
                moveDireita = false;

            if (e.getKeyCode() == KeyEvent.VK_UP)
                moveCima = false;

            if (e.getKeyCode() == KeyEvent.VK_DOWN)
                moveBaixo = false;

        }
    }

        public void paint(Graphics g) {
            super.paint(g); //The call to "super.paint(g)", cleans the screen

            Graphics2D g2d = (Graphics2D) g;
            //The instruction; "g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON)" makes the borders of the figures smoother

            //g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            jogador.show();

            if(qntInimigo == 0) {
                g2d.setBackground(Color.CYAN);
                g2d.drawString("VOCE GANHOU!", 300, Constantes.coordY / 2);
            }

            if(jogador.getP().getLife() == 0){
                g2d.setBackground(Color.RED);
                g2d.drawString("VOCE PERDEU!", 300, Constantes.coordY / 2);
            }else{
                g2d.setColor(Color.ORANGE);
                g2d.fillOval(jogador.getX(), jogador.getY(), 20, 20);
            }

            if(qntInimigo != 0){
                g2d.setColor(Color.BLACK);
                qntInimigo=0;
                for(int i =0; i<Constantes.maxInimigos; i++){
                    if(inimigos[i].getP().getLife()!=0) {
                        g2d.fillOval(inimigos[i].getX(), inimigos[i].getY(), 20, 20);
                        qntInimigo++;
                    }else{
                        jogador.deleteObserver(inimigos[i]);
                    }

                }

            }

            if(moveEsquerda == true)
                c.pressionar(0);
            if(moveDireita == true)
                c.pressionar(1);
            if(moveCima == true)
                c.pressionar(2);
            if(moveBaixo == true)
                c.pressionar(3);


            g2d.setColor(Color.BLACK);
            g2d.drawString("Vida: " + jogador.getP().getLife(), 50, 50);
            g2d.drawString("Qtd inimigos: " + qntInimigo, 50, 70);


        }

}


