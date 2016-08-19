
public class Conta {
	
	private int numConta;
	private float limite, saldo;
	private String nomeCorrentista;
	
	public int getNumConta(){
		return numConta;
	}
	
	public void setNumConta(int num){
		numConta = num;
	}
	
	public float getLimite(){
		return limite;
	}
	
	public void setLimite(float num){
		limite = num;
	}
	
	public float getSaldo(){
		return saldo;
	}
	
	public void setSaldo(float num){
		saldo = num;
	}
	
	public String getNomeCorrentista(){
		return nomeCorrentista;
	}
	
	public void setNomeCorrentista(String nome){
		nomeCorrentista = nome;
	}
	
	public void print(){
		System.out.println("Nome do correntista: "+nomeCorrentista);
		System.out.println("Saldo: "+saldo);
		System.out.println("Limite: " + limite);
		System.out.println("Número da conta: "+ numConta);
	}
	
	
	
}
