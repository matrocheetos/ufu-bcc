package principal;

import produto.Produto;

public class Principal {
    public static void main(String[] args) {
        Produto produto = new Produto();

        System.out.println(produto.dadosEstoque());
        produto.compra(20);
        System.out.println(produto.dadosEstoque());
        produto.venda(15);
        System.out.println(produto.dadosEstoque());
        produto.venda(50);
        System.out.println(produto.dadosEstoque());
    }
}
