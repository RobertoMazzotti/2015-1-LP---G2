#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#define ALUNOS 5

//Bruno Fidelis
//Roberto Mazzotti
//Thomaz Pires
//Wagner Silveira
typedef struct aluno{
  int matricula,i;
  int idade;
  char nome[50];
  char endereco[100];
  float nota[3];
}t_aluno;

void print_aluno(FILE *dados){
    int i,matricula;
    t_aluno aluno;
    printf("Informe a matricula: ");
    scanf("%d",&matricula);
    dados=fopen("aluno.txt","rb");
    while(matricula!=aluno.matricula){
        //fseek(dados,sizeof(aluno),SEEK_SET);
        system("pause");
        fread(&aluno,sizeof(aluno),1,dados);
    }
    printf("%-3s %-15s %-6s %-6s %-6s %-6s %-3s\n\n","Matricula", "Nome", "Idade","Nota1","Nota2","Nota3","Endereco");
     printf("%-9d %-15s %-6d %-6.2f %-6.2f %-6.2f %-10s\n",aluno.matricula,aluno.nome, aluno.idade,aluno.nota[0],aluno.nota[1],aluno.nota[2], aluno.endereco,aluno.nota[0],aluno.nota[1],aluno.nota[2]);
    system("pause");
    system("cls");
}
void print_alunos(FILE *dados){
    int i;
    t_aluno a1;
     if(dados != NULL){
       dados = fopen("Aluno.txt", "rb");
        printf("%-3s %-15s %-6s %-6s %-6s %-6s %-3s\n\n","Matricula", "Nome", "Idade","Nota1","Nota2","Nota3","Endereco");
       fflush(stdin);
       while(fread(&a1,sizeof (a1),1,dados)){

       printf("%-9d %-15s %-6d %-6.2f %-6.2f %-6.2f %-10s\n",a1.matricula,a1.nome, a1.idade,a1.nota[0],a1.nota[1],a1.nota[2], a1.endereco,a1.nota[0],a1.nota[1],a1.nota[2]);
       }
       fclose(dados);
     }else
    printf("Nao foi possivel abrir o arquivo.");
}

int menu(){
    int opcao;
    printf("----- MENU -----\n");
    printf("| 1 - Cadastrar Aluno \n");
    printf("| 2 - Pesquisar Aluno \n");
    printf("| 3 - Listar todos os alunos \n");
    printf("| 4 - Excluir aluno (NAO IMPLEMENTADO)\n");
    printf("| 6 - Listar aluno ordenado (NAO IMPLEMENTADO) \n");
    printf("| 7 - Estatisticas da Turma (NAO IMPLEMENTADO) \n");
    printf("| 0 - Sair\n\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    system("cls");
    return (int)opcao;
}


void cadastra_aluno (FILE * dados){
    int i;
    t_aluno aluno;
    dados=fopen("aluno.txt","ab");
    printf("----- CADASTRO DE ALUNOS -----\n");
    printf("Informe a matricula do aluno: ");
    scanf("%d", &aluno.matricula);
    fflush(stdin);
    printf("Informe o nome do aluno: ");
    gets(aluno.nome);
    fflush(stdin);
    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno.idade);
    fflush(stdin);
    printf("Informe o endereco do aluno: ");
    gets(aluno.endereco);
    for (i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &aluno.nota[i]);
    }
    fwrite(&aluno, sizeof(aluno),1,dados);
    fclose(dados);
}

int main(){
    char caminho[] = "aluno.txt";
    FILE * dados;
    int sair = 0,count=0;

    do{

        switch(menu()){
            case 1:
                cadastra_aluno(dados);

                break;
            case 2:
                print_aluno(dados);
                break;
            case 3:
                print_alunos(dados);
                break;
            case 4:
                //excluir_aluno(alunos, &cadastrados, encontrados);
                break;
            case 6:
               // listar_ordenado(alunos, cadastrados, encontrados);
            case 0:
                sair = 1;
                break;
        }
    }while(sair == 0);
}
