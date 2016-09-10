
public class Livro {
	
	private int quantidade;
	private String titulo;
	
	Livro(int quantidade, String titulo)
	{
		this.quantidade = quantidade;
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
	
}
