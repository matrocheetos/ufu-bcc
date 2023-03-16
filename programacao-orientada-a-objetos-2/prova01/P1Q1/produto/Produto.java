package produto;

import estoque.Estoque;
import estoque.EstoqueIndisponivel;

public class Produto {
    private int quantidade;
    private Estoque estoque;

    public Produto() {
        this.setQuantidade(0);
        this.setEstoque(new EstoqueIndisponivel(this));
    }

    // reposição de estoque
    public void compra(int quantidade) {
        this.getEstoque().repoeEstoque(quantidade);
    }

    // abate de estoque
    public void venda(int quantidade) {
        this.getEstoque().abateEstoque(quantidade);
    }

    public String dadosEstoque() {
        return ("estoque [" + this.getEstoque().getEstadoEstoque() + "]: " + this.getQuantidade());
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public Estoque getEstoque() {
        return estoque;
    }

    public void setEstoque(Estoque estoque) {
        this.estoque = estoque;
    }
}
