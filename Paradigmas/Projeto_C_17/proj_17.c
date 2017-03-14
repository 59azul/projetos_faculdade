#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Projeto de cadastro de alunos, disciplinas e professores.
*   Tarefas:
*   - Cadastro de alunos [v]
*   - Cadastro de disciplinas [v]
*   - Cadastro de professores [v]
*   - Matricular um conjunto de alunos em um conjunto de disciplinas []
*   - Cancelar a matricula de um conjunto de alunos em um conjunto de disciplinas []
*   - Vincular um conjunto de professores à um conjunto de disciplinas []
*   - Imprimir lista de todos os alunos [v]
*   - Imprimir lista de todas as disciplinas [v]
*   - Imprimir lista de todos os professores [v]
*   - Imprimir lista de alunos matriculados em uma disciplina []
*   - Imprimir lista de disciplinas que um aluno está matriculado []
*   - Imprimir lista de professores vinculados à uma disciplina []
*   - Imprimir lista de disciplinas ministradas por um professor []
*/

typedef struct alunos talu;
typedef struct disciplinas tdisc;
typedef struct professores tprof;

struct alunos
{
    int ra;
    char nome[50];
};

struct disciplinas
{
    int cod;
    char nome[50];
    int cod_alunos[50];
    int aluMatri;
    int cod_prof[50];
    int profMatri;
};

struct professores
{
    int cod;
    char nome[50];
};

void imprimeAlunos(talu alunos[50]){
    int contador=0;
    
    while(contador<50){
        if(alunos[contador].ra==0){
            break;
        }
        printf("RA: %d\n", alunos[contador].ra);
        printf("Nome: %s\n", alunos[contador].nome);
        contador++;
    }
}

void imprimeDisciplinas(tdisc disciplinas[50]){
    int contador=0;
    
    while(contador<50){
        if(disciplinas[contador].cod==0){
            break;
        }
        printf("Codigo: %d\n", disciplinas[contador].cod);
        printf("Nome: %s\n", disciplinas[contador].nome);
        contador++;
    }
}

void imprimeProfessores(tprof professores[50]){
    int contador=0;
    
    while(contador<50){
        if(professores[contador].cod==0){
            break;
        }
        printf("Codigo: %d\n", professores[contador].cod);
        printf("Nome: %s\n", professores[contador].nome);
        contador++;
    }
}

int procuraAluno(talu alunos[50], int ra) // Função procura se o ra inserido já existe, se sim, a função retorna 0, se não, retorna 1
{
    int i;
    for(i = 0; i < 50; i++)
    {
        if(alunos[i].ra == 0) return 1;
        if(alunos[i].ra == ra)
        {
            return 0;
        }
    }
    
    return 1;
}

void cadastro_aluno(talu alunos[50], int contador)
{
    int ra, verifica=0;
    char nome[50];
    do{
    
        printf("Digite o RA do aluno que quer cadastrar: ");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &ra);
        
        verifica = procuraAluno(alunos, ra);
        
        if(verifica)
        {
            printf("Digite o nome do aluno a ser cadastrado: ");
            __fpurge(stdin);
            //fflush(stdin);
            fgets(nome, 50, stdin);
            
            alunos[contador].ra = ra;
            strcpy(alunos[contador].nome, nome);
            
            printf("Aluno cadastrado com sucesso.\n");
        }
        else
        {
            printf("O ra digitado já existe, por favor digite outro ra.\n");
        }
    
    }while(verifica == 0);
    
}

int procuraDisc(tdisc disciplinas[50], int cod) // Função procura se o código inserido já existe, se sim retorna 0, se não retorna 1
{
    int i;
    for (i = 0; i < 50; i++) 
    {
        if(disciplinas[i].cod == 0) return 1;
        if(disciplinas[i].cod == cod) return 0;
    }
    return 1;
}

void cadastro_disc(tdisc disciplinas[50], int contador)
{
    int cod, verifica = 0;
    char nome[50];
    
    do{
        printf("Digite o codigo da disciplina que quer cadastrar: ");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &cod);
        
        verifica = procuraDisc(disciplinas, cod);
        
        if(verifica)
        {
            printf("Digite o nome da disciplina a ser cadastrada: ");
            __fpurge(stdin);
            //fflush(stdin);
            fgets(nome, 50, stdin);
            
            disciplinas[contador].cod = cod;
            strcpy(disciplinas[contador].nome, nome);
            
            disciplinas[contador].aluMatri = 0;
            disciplinas[contador].profMatri = 0;
            
            printf("Disciplina cadastrada com sucesso.\n");
        }
        else
        {
            printf("O codigo digitado ja existe, por favor digite outro codigo.\n");
        }
        
        
    }while(verifica==0);
    
    
    
}

int procuraProf(tprof professores[50], int cod) // Função procura se o código já existe, se sim retorna 0, se não retorna 1
{
    int i;
    for (i = 0; i < 50; i++) 
    {
        if(professores[i].cod == 0) return 1;
        if(professores[i].cod == cod) return 0;
    }
    return 1;
}

void cadastro_prof(tprof professores[50], int contador)
{
    int cod, verifica = 0;
    char nome[50];
    
    do{
        printf("Digite o codigo do professor que quer cadastrar: ");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &cod);
        
        verifica = procuraProf(professores, cod);
        
        if(verifica)
        {
            printf("Digite o nome do professor a ser cadastrado: ");
            __fpurge(stdin);
            //fflush(stdin);
            fgets(nome, 50, stdin);
            
            professores[contador].cod = cod;
            strcpy(professores[contador].nome, nome);
            
            printf("Professor cadastrado com sucesso.\n");
        }
        else
        {
            printf("O codigo digitado ja existe, por favor digite outro codigo.\n");
        }
        
        
    }while(verifica==0);
    
    
    
}

int encontrarAlu(talu alunos[50], int codigo) // Função retorna a posição no vetor do aluno com o ra inserido
{
    int i = 0;
    
    for (i = 0; i < 50; i++) 
    {
        if(alunos[i].ra == codigo) return i;
    }
    return -1;
}

int encontrarDisc(tdisc disciplinas[50], int codigo)
{
    int i = 0;
    
    for (i = 0; i < 50; i++) 
    {
        if(disciplinas[i].cod == codigo) return i;
    }
    return -1;
}

void matriculaAlunos(tdisc disciplinas[50], talu alunos[50], int contAlu, int contDisc) // Função vincula alunos a disciplinas, através do vetor de ras que disciplinas possuem
{
    int numAlunos = 0, numDisc = 0, posDisc = 0, aux = 0;
    int vetAlu[50];
    int verifica=1;
    
    while(verifica && (contAlu > numAlunos))
    {
        printf("Se quiser matricular um aluno, digite seu ra, se nao digite 0 para prosseguir.\n");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &verifica);
        if(verifica)
        {
            if(!procuraAluno(alunos, verifica)) 
            {
                vetAlu[numAlunos] = verifica;
                numAlunos++;
            }
            else
            {
                printf("Nao existe um aluno com esse ra.");
            }
        }
    }
    
    verifica = 1;
    
    while(verifica && (contDisc > numDisc))
    {
        printf("Digite o codigo da disciplina em que os alunos serao cadastrados, ou digite 0 quando finalizar.\n");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &verifica);
        if(verifica)
        {
            if(!procuraDisc(disciplinas, verifica))             // Verifica se existe uma disciplina com o código digitado
            {
                posDisc = encontrarDisc(disciplinas, verifica); // posDisc guarda a posição no vetor da disciplina com o código digitado
                for(aux = 0; aux < numAlunos; aux++)
                {
                    disciplinas[posDisc].cod_alunos[disciplinas[posDisc].aluMatri] = vetAlu[aux];   
                                                                // Insere o ra de um aluno do vetor de alunos selecionados no vetor de ras de uma disciplina
                    disciplinas[posDisc].aluMatri++;            // Utiliza a variável aluMatri da estrutura de disciplinas para controlar 
                                                                // o número de alunos matriculados em uma disciplina
                }
            }
            else
            {
                printf("Nao existe uma disciplina com esse codigo.\n");
            }
        }
    }
    printf("Alunos matriculados com sucesso!\n");
    
}

void imprimeAluEmDisc(tdisc disciplinas[50], talu alunos[50])
{
    int cod = 0, i= 0, posDisc = 0;
    
    printf("Digite o codigo da disciplina da qual quer ver as matriculas: ");
    __fpurge(stdin);
    //fflush(stdin);
    scanf("%d", &cod);
    
    
    
    if(!procuraDisc(disciplinas, cod))
    {
        posDisc = encontrarDisc(disciplinas, cod);
        
        printf("Nome da disciplina: %s\n", disciplinas[posDisc].nome);
        for(i = 0; i < disciplinas[posDisc].aluMatri; i++)
        {
            printf("RA: %d\n", alunos[encontrarAlu(alunos, disciplinas[posDisc].cod_alunos[i])].ra);
            printf("Nome: %s\n", alunos[encontrarAlu(alunos, disciplinas[posDisc].cod_alunos[i])].nome);
        }
    }
    
    
    
}

int main()
{
    talu alunos[50];
    tdisc disciplinas[50];
    tprof professores[50];
    int opcao = 1;
    int contAlunos = 0, contDisc = 0, contProf = 0;

    while(opcao)
    {
        printf("O que deseja fazer? \n");
        printf("1-  Cadastro de alunos\n");
        printf("2-  Cadstro de disciplinas\n");
        printf("3-  Cadastro de professores\n");
        printf("4-  Matricular grupo de alunos em um grupo de disciplinas\n");
        printf("7-  Imprimir lista de alunos\n");
        printf("8-  Imprimir lista de disciplinas\n");
        printf("9-  Imprimir lista de professores\n");
        printf("10- Imprimir lista de alunos matriculados em uma disciplina\n");
        printf("0-  Sair\n");
        __fpurge(stdin);
        //fflush(stdin);
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1: cadastro_aluno(alunos, contAlunos);
            contAlunos++;
            break;
            case 2: cadastro_disc(disciplinas, contDisc);
            contDisc++;
            break;
            case 3: cadastro_prof(professores, contProf);
            contProf++;
            break;
            case 4: matriculaAlunos(disciplinas, alunos, contAlunos, contDisc);
            break;
            case 7: imprimeAlunos(alunos);
            break;
            case 8: imprimeDisciplinas(disciplinas);
            break;
            case 9: imprimeProfessores(professores);
            break;
            case 10: imprimeAluEmDisc(disciplinas, alunos);
            break;
            default: break;
        }
        
        
        
    }



    return 0;
}
