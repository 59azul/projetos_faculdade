
public class Aluno {
	
	private int ra; 		// Variável que guarda o RA do aluno
	private String nome;	// Variável que guarda o nome do aluno
	
	
	Aluno()
	{
		ra = 0;
		nome = "";
	}
	
	Aluno(int ra, String nome)
	{
		this.ra = ra;
		this.nome = nome;
	}
	
	// Getters e setters
	public int getRa() {
		return ra;
	}
	public void setRa(int ra) {
		this.ra = ra;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	
}
