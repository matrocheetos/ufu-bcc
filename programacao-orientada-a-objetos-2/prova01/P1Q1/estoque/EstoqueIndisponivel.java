package estoque;

import produto.Produto;

public class EstoqueIndisponivel extends Estoque {
    public EstoqueIndisponivel(Produto produto) {
        super(produto);
        this.setEstadoEstoque("indisponivel");
    }

    @Override
    protected void setLimites() {
        setLimiteSuperior(0);
        setLimiteInferior(0);
    }

    @Override
    protected void alteraEstadoEstoque() {
        if(this.getProduto().getQuantidade() > this.getLimiteSuperior()) {
            this.getProduto().setEstoque(new EstoqueCritico(this.getProduto()));
            this.getProduto().getEstoque().alteraEstadoEstoque();
        }
    }
}
