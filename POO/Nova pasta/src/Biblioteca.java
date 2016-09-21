import java.util.Scanner;

public class Biblioteca {

	private Aluno[] alunos = new Aluno[50];		// Array que contém os alunos
	private Livro[] livros = new Livro[50];		// Array que contém os livros 
	private Scanner input = new Scanner(System.in);
	private Tempo data = new Tempo();
	
	Aluno procuraAluno(int ra)
	{
		for(int i = 0; i < 50; i++)
		{
			if(alunos[i].getRa() == ra)
			{
				return alunos[i];
			}
		}
		return null;
	}
	
	Livro procuraLivro(String titulo)
	{
		for(int i = 0; i < 50; i++)
		{
			if(titulo.equals(livros[i].getTitulo()))
			{
				return livros[i];
			}
		}
		return null;
	}
	
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
				livros[j].setTotal(quantidade+livros[j].getTotal()); 	// Soma a quantidade anterior com a quantidade digitada
				return -1;												// caso o titulo já exista
			}
		}
		livros[indice] = new Livro(quantidade, titulo);
		return 1;
	}
	
	int emprestaLivro()
	{
		int ra;
		String titulos;
		System.out.println("Digite o RA do aluno: ");
		ra = input.nextInt();
		Aluno usuario = procuraAluno(ra);	// Procura um aluno com o ra digitado
		if(usuario == null)					// Se não for encontrado(retornar null), exibe mensagem de erro
		{
			return -1;
		}
		if(usuario.getQuantidadeEmprestimos() >= 3)	// Verifica se o aluno ainda pode emprestar mais algum livro
		{
			return -2;
		}
		System.out.println("Digite o título do livro: ");
		titulos = input.next();
		Livro emprestado = procuraLivro(titulos);	// Procura um livro com o nome digitado 
		if( emprestado == null)
		{
			return -3;
		}
		if(emprestado.getQuantidade() > 0)
		{
			usuario.associaLivro(titulos);
			emprestado.setQuantidade(emprestado.getQuantidade()-1);
			usuario.setQuantidadeEmprestimos(usuario.getQuantidadeEmprestimos()+1);
			return 1;
		}
		
		
		
		return 0;
	}
	
	int devolveLivro()
	{
		int ra;
		String titulo;
		System.out.println("Digite o RA do aluno que vai realizar a devolução: ");
		ra = input.nextInt();
		Aluno usuario = procuraAluno(ra);	// Procura um aluno com o ra digitado
		if(usuario == null)					// Se não for encontrado(retornar null), exibe mensagem de erro
		{
			return -1;
		}
		System.out.println("Digite o título do livro: ");
		titulo = input.next();
		Livro emprestado = procuraLivro(titulo);	// Procura um livro com o nome digitado 
		if( emprestado == null)
		{
			return -2;
		}
		return usuario.devolveLivro(titulo);
	}
	
	public void menu()
	{
		int escolha, contAluno = 0, contLivro = 0;
		boolean sair = false;		// Enquanto está falso, não sai
		
		
		System.out.println("Digite a data de hoje: ");
		System.out.println("Dia: ");
		data.setDia(input.nextInt());
		System.out.println("Mês: ");
		data.setMes(input.nextInt());
		System.out.println("Ano: ");
		data.setAno(input.nextInt());
		data.corrigeTempo();
		
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
		break;
		case 3:
			switch(emprestaLivro())
			{
			case -1: System.out.println("Usuário não encontrado.");
			break;
			case -2: System.out.println("Usuário já emprestou mais de 3 exemplares.");
			break;
			case -3: System.out.println("Livro não econtrado.");
			break;
			case 1: System.out.println("Livro emprestado com sucesso.");
			break;
			case 0: System.out.println("Exemplares esgotados.");
			break;
			}
		break;
		case 4:
			switch(devolveLivro())
			{
			case -2: System.out.println("Livro não encontrado.");
			break;
			case -1: System.out.println("Usuário não encontrado.");
			break;
			case 0: System.out.println("Usuário não emprestou o livro selecionado.");
			break;
			case 1: System.out.println("Livro devolvido com sucesso.");
			break;
			}
		break;
		case 0: sair = true;
		break;
		default : System.out.println("Opção inválida.");
		break;
		}
		
		
		}
		
		
		
		input.close();
	}
	
	
}
