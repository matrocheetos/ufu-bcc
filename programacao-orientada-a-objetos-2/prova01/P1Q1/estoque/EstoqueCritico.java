package estoque;

import produto.Produto;

public class EstoqueCritico extends Estoque {
    public EstoqueCritico(Produto produto) {
        super(produto);
        this.setEstadoEstoque("critico");
    }

    @Override
    protected void setLimites() {
        setLimiteSuperior(10);
        setLimiteInferior(1);
    }

    @Override
    protected void alteraEstadoEstoque() {
        if(this.getProduto().getQuantidade() < this.getLimiteInferior()) {
            this.getProduto().setEstoque(new EstoqueIndisponivel(this.getProduto()));
            this.getProduto().getEstoque().alteraEstadoEstoque();
        } else if(this.getProduto().getQuantidade() > this.getLimiteSuperior()) {
            this.getProduto().setEstoque(new EstoqueDisponivel(this.getProduto()));
            this.getProduto().getEstoque().alteraEstadoEstoque();
        } else {
            System.out.println("Estoque em estado critico! Repor estoque!");
        }
    }
}
