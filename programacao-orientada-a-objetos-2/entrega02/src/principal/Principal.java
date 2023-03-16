package principal;

import mvc_visao.Game;

import javax.swing.*;

public class Principal {
    static int x = Constantes.coordX;
    static int y = Constantes.coordY;

    public static void main(String[] args) throws InterruptedException {


        JFrame frame = new JFrame("Jogo");
        Game game = new Game();

        game.setLayout(null);
        frame.add(game);
        frame.setSize(x+35,y+60);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        game.setFocusable(true);
        game.setDoubleBuffered(true);

        while (true) {
            game.repaint();
        }

        /*
        SimpleMedievalFactory f= SimpleMedievalFactory.getInstance();
        Personagem inimigo1 = f.createPersonagem();
        Personagem inimigo2 = f.createPersonagem();
        Personagem inimigo3 = f.createPersonagem();

        Fase labirinto =
                new Sala(
                    new Sala(
                        new Folha02(),
                        new Sala(
                                new Folha01(), new Folha02(), inimigo1),
                        inimigo2),
                    new Folha02(), inimigo3);

        Personagem p1 = new PersonagemMedieval05("Jogador 1");
        Personagem p2 = new PersonagemMedieval05("Jogador 2");
        Personagem p3 = new PersonagemMedieval05("Jogador 3");

        ThreadLabirinto tl1 = new ThreadLabirinto(labirinto, p1);
        ThreadLabirinto tl2 = new ThreadLabirinto(labirinto, p2);
        ThreadLabirinto tl3 = new ThreadLabirinto(labirinto, p3);

        Thread t1 = new Thread(tl1);
        Thread t2 = new Thread(tl2);
        Thread t3 = new Thread(tl3);

        t1.start();
        t2.start();
        t3.start();
        //labirinto.jogar(p);

        /*
        MedievalFactory f = SimpleMedievalFactory.getInstance();
        Personagem personagem = null;
        for (int i = 0; i < 20 ; i++){
            personagem = f.createPersonagem();
        }
        
        Escudo escudo1 = new Escudo(5);
        Escudo escudo2 = new Escudo(2);
        Escudo escudo3 = new Escudo(3);

        personagem.setEscudo(escudo1);

        personagem.atacar();

        Ataque poder = new PoderEletrico(personagem.getAtaque());
        personagem.setAtaque(poder);

        poder = new PoderFogo(personagem.getAtaque());
        personagem.setAtaque(poder);

        personagem.atacar();
        personagem.correr();
        personagem.pular();

        personagem.ganharVida(10);
        personagem.perderVida(50);
        personagem.ganharVida(45);

        escudo1.setSucessor(escudo2);
        escudo2.setSucessor(escudo3);

        personagem.perderVida(50);

        personagem.perderVida(20);
        personagem.perderVida(1000);
    */
    }
}
