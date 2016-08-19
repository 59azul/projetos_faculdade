import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Conta con1 = new Conta();
		Conta con2 = new Conta();
		Conta con3 = new Conta();
		Scanner input = new Scanner(System.in);
		
		con1.setLimite(input.nextFloat());
		con1.setNomeCorrentista(input.next());
		con1.setNumConta(input.nextInt());
		con1.setSaldo(input.nextFloat());
		
		con2.setLimite(input.nextFloat());
		con2.setNomeCorrentista(input.nextLine());
		con2.setNumConta(input.nextInt());
		con2.setSaldo(input.nextFloat());
		
		con3.setLimite(input.nextFloat());
		con3.setNomeCorrentista(input.nextLine());
		con3.setNumConta(input.nextInt());
		con3.setSaldo(input.nextFloat());
		
		con1.print();
		con2.print();
		con3.print();
		
		
	}

}
