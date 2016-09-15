
public class Livro {
	
	private int quantidade;	// Quantidade disponível de exemplares de um livro
	private int total;		// Quantidade total de exemplares
	private String titulo;
	
	Livro(int total, String titulo)
	{
		this.total = total;
		this.titulo = titulo;
	}
	
	// Getters e setters
	public int getQuantidade() {
		return quantidade;
	}
	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public int getTotal() {
		return total;
	}

	public void setTotal(int total) {
		this.total = total;
	}
	
}
