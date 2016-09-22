
public class Tempo {
	private int dia, mes, ano;
	private int total;
	
	Tempo()
	{
		total = -1;
	}
	
	Tempo(int dia, int mes, int ano)
	{
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

	public void print()
	{
		System.out.println("Dia: " + dia);
		System.out.println("Mes: " + mes);
		System.out.println("Ano: " + ano);
	}
	
	public void corrigeTempo()
	{
		if(dia > 30)
		{
			mes++;
			dia = dia - 30;
		}
		if(mes > 12)
		{
			ano++;
			mes = mes - 12;
		}
		/*
		ano = total / 365;
		mes = (total % 365)/30;
		dia = (total % 365) % 30;*/
		
		total = ano * 365;
		total = total + (mes * 30);
		total = total + dia;
	}
	
	public int getDia() {
		return dia;
	}

	public void setDia(int dia) {
		this.dia = dia;
	}

	public int getMes() {
		return mes;
	}

	public void setMes(int mes) {
		this.mes = mes;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public int getTotal() {
		return total;
	}

	public void setTotal(int total) {
		this.total = total;
	}
	
	
	
	
}
