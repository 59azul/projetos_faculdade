
public class Aluno {
	
	private int ra; 		// Variável que guarda o RA do aluno
	private String nome;	// Variável que guarda o nome do aluno
	private String[] titulos = {"","",""};
	private Tempo[] dataEmprestimos = {new Tempo(), new Tempo(), new Tempo()};
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
	
	public void associaLivro(String titulo, Tempo data)
	{
		int posicao = posicaoTitulo();
		if(posicao >=0)
		{
			this.titulos[posicao] = titulo;
			dataEmprestimos[posicao] = new Tempo(data.getDia(), data.getAno(), data.getMes());
			dataEmprestimos[posicao].corrigeTempo();
		}
	}
	
	public int devolveLivro(String titulo, Tempo data)
	{
		for(int i = 0; i < 3; i++)
		{
			if(titulos[i].equals(titulo))
			{
				if((data.getTotal() - dataEmprestimos[i].getTotal()) > 7)
				{
					titulos[i] = "";
					quantidadeEmprestimos--;
					dataEmprestimos[i] = new Tempo();
					return -1;
				}
				
				titulos[i] = "";
				quantidadeEmprestimos--;
				dataEmprestimos[i] = new Tempo();
				return 1;
			}
		}
		
		return 0;
	}
	
	public void print()
	{
		System.out.println("Nome: " + nome);
		System.out.println("RA: " + ra);
		System.out.println("Quantidade de livros emprestados: " + quantidadeEmprestimos);
		System.out.println("Livros emprestados: ");
		for(int i = 0; i < 3; i++)
		{
			if(!titulos[i].equals(""))
				{
					System.out.println(titulos[i]);
					System.out.println("Emprestado em: ");
					dataEmprestimos[i].print();
				}
		}
	}
	
	boolean atraso(Tempo data)
	{
		for(int i = 0; i < 3; i++)
		{
			if(dataEmprestimos[i].getTotal() != -1) // Verifica se o elemento sendo percorrido tem uma data válida
			{
				if((data.getTotal() - dataEmprestimos[i].getTotal()) > 7)
				{
					return true;
				}
			}
		}
		
		return false;
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
