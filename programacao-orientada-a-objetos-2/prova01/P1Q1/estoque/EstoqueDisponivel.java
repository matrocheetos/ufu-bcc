package estoque;

import produto.Produto;

public class EstoqueDisponivel extends Estoque {
    public EstoqueDisponivel(Produto produto) {
        super(produto);
        this.setEstadoEstoque("disponivel");
    }

    @Override
    protected void setLimites() {
        setLimiteSuperior(999); // sem limite
        setLimiteInferior(11);
    }

    @Override
    protected void alteraEstadoEstoque() {
        if(this.getProduto().getQuantidade() < this.getLimiteInferior()) {
            this.getProduto().setEstoque(new EstoqueCritico(this.getProduto()));
            this.getProduto().getEstoque().alteraEstadoEstoque();
        }
    }
}
