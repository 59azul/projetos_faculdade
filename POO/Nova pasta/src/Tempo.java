
public class Tempo {
	private int dia, mes, ano;

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
	
	
	
	
}
