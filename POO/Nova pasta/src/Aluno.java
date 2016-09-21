
public class Aluno {
	
	private int ra; 		// Variável que guarda o RA do aluno
	private String nome;	// Variável que guarda o nome do aluno
	private String[] titulos = {"","",""};
	private int quantidadeEmprestimos;
	
	Aluno()
	{
		ra = 0;
		nome = "";
		quantidadeEmprestimos = 0;
	}
	
	Aluno(int ra, String nome)
	{
		this.ra = ra;
		this.nome = nome;
	}
	
	private int posicaoTitulo()
	{
		for(int i = 0; i < 3; i++)
		{
			if(titulos[i] == "") return i;
		}
		return -1;
	}
	
	public void associaLivro(String titulo)
	{
		int posicao = posicaoTitulo();
		if(posicao >=0)
		{
			this.titulos[posicao] = titulo;
		}
	}
	
	public int devolveLivro(String titulo)
	{
		for(int i = 0; i < 3; i++)
		{
			if(titulos[i].equals(titulo))
			{
				titulos[i] = "";
				quantidadeEmprestimos--;
				return 1;
			}
		}
		
		return 0;
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

	public String[] getTitulos() {
		return titulos;
	}

	public void setTitulos(String[] titulos) {
		this.titulos = titulos;
	}

	public int getQuantidadeEmprestimos() {
		return quantidadeEmprestimos;
	}

	public void setQuantidadeEmprestimos(int quantidadeEmprestimos) {
		this.quantidadeEmprestimos = quantidadeEmprestimos;
	}

	
	
	
}
