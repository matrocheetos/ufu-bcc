package estoque;

import produto.Produto;

public abstract class Estoque {
    private Produto produto;
    private int limiteSuperior;
    private int limiteInferior;
    private String estadoEstoque;

    protected Estoque(Produto produto) {
        this.produto = produto;
        this.setLimites();
    }

    protected abstract void setLimites();
    protected abstract void alteraEstadoEstoque();

    public void repoeEstoque(int quantidade) {
        int nEstoque = this.produto.getQuantidade() + quantidade;
        this.produto.setQuantidade(nEstoque);
        this.alteraEstadoEstoque();
    }

    public void abateEstoque(int quantidade) {
        int nEstoque = this.produto.getQuantidade() - quantidade;
        if(nEstoque < 0) { nEstoque = 0; }
        this.produto.setQuantidade(nEstoque);
        this.alteraEstadoEstoque();
    }

    public int getLimiteSuperior() {
        return limiteSuperior;
    }

    public void setLimiteSuperior(int limiteSuperior) {
        this.limiteSuperior = limiteSuperior;
    }

    public int getLimiteInferior() {
        return limiteInferior;
    }

    public void setLimiteInferior(int limiteInferior) {
        this.limiteInferior = limiteInferior;
    }

    public Produto getProduto() {
        return produto;
    }

    public String getEstadoEstoque() {
        return estadoEstoque;
    }

    public void setEstadoEstoque(String estadoEstoque) {
        this.estadoEstoque = estadoEstoque;
    }
}
