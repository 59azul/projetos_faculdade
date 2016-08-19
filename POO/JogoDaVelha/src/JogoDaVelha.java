
public class JogoDaVelha {

	
	public static void tabela(int[][] v){
		int i =0;
		for(i=0; i<3; i++){
			System.out.printf("[ %d ]\t[ %d ]\t[ %d ]\n", v[i][0], v[i][1], v[i][2]);
		}
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [][] v = new int[3][3];
		v[0][0] = 0;
		v[0][1] = 0;
		v[0][2] = 0;
		v[1][0] = 0;
		v[1][1] = 0;
		v[1][2] = 0;
		v[2][0] = 0;
		v[2][1] = 0;
		v[2][2] = 0;
		
		tabela(v);
		
		
		
		
	}

}
