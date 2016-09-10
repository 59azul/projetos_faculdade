import java.util.Scanner;

public class Biblioteca {

	private Aluno[] alunos = new Aluno[50];		// Array que contém os alunos
	private Livro[] livros = new Livro[50];		// Array que contém os livros 
	private Scanner input = new Scanner(System.in);
	

	
	int cadastraAluno(int indice)
	{
		int ra;
		String nome;
		
		System.out.print("Digite o ra do aluno: ");
		ra = input.nextInt();
		System.out.print("Digite o nome do aluno: ");
		nome = input.next();
		
		if(indice >=50)					// Verifica se o array está cheio
		{
			return 0;
		}
		
		for(int j = 0;j<indice;j++)		// Verifica se o Ra digitado pelo usuário já foi cadastrado
		{
			if(alunos[j].getRa() == ra)
			{
				return -1;
			}
		}
		alunos[indice] = new Aluno(ra, nome);
		return 1;
	}
	
	int cadastraLivro(int indice)
	{
		System.out.println("Digite a quantidade de exemplares: ");
		int quantidade = input.nextInt();
		System.out.println("Digite o título do livro: ");
		String titulo = input.next();
		
		if(indice >=50)					// Verifica se o array está cheio
		{
			return 0;
		}
		
		for(int j = 0;j<indice;j++)		// Verifica se o titulo digitado pelo usuário já existe
		{
			if(livros[j].getTitulo() == titulo)
			{
				livros[j].setQuantidade(quantidade+livros[j].getQuantidade()); 	// Soma a quantidade anterior com a quantidade digitada
				return -1;														// caso o titulo já exista
			}
		}
		livros[indice] = new Livro(quantidade, titulo);
		return 1;
	}
	
	public void menu()
	{
		int escolha, contAluno = 0, contLivro = 0;
		boolean sair = false;		// Enquanto está falso, não sai
		
		
		while(!sair)
		{
			System.out.println("1. Cadastrar um aluno.");
			System.out.println("2. Cadastar um livro.");
			System.out.println("3. Emprestar um livro para um aluno.");
			System.out.println("4. Devolver um livro.");
			System.out.println("5. Consultar livros por título.");
			System.out.println("6. Consultar alunos por nome.");
			System.out.println("7. Verificar alunos com devoluções atrasadas.");
			System.out.println("8. Consultar lista de alunos.");
			System.out.println("0. Sair do programa.");
			escolha = input.nextInt();	// Opção escolhida pelo usuário é armazenada na variável escolha
			
		switch (escolha)
		{
		case 1: 
			switch (cadastraAluno(contAluno))
			{
			case -1: System.out.println("RA já cadastrado anteriormente.");
			break;
			case 0: System.out.println("Sistema de cadastro cheio.");
			break;
			case 1: System.out.println("Cadastro feito com sucesso.");
			contAluno++;
			break;
			}
		break;
		case 2:
			switch (cadastraLivro(contLivro))
			{
			case -1: System.out.println("Quantidade de livros incrementada(Título escolhido já existente).");
			break;
			case 0: System.out.println("Sistema de cadastro cheio.");
			break;
			case 1: System.out.println("Cadastro feito com sucesso.");
			contLivro++;
			break;
			}
		case 0: sair = true;
		break;
		default : System.out.println("Opção inválida.");
		break;
		}
		
		
		}
		
		
		
		input.close();
	}
	
	
}
