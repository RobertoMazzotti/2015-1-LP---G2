#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno{
  int matricula;
  int idade;
  char nome[50];
  char endereco[100];
}t_aluno;

int deleta_aluno(t_aluno a1[], int ctd){
    int i,controle;
    controle=buscar_matricula(a1,ctd);
    if (controle!=21){
    for(i=controle;i<ctd;i++){
        strcpy(a1[i].nome,a1[i+1].nome);
        a1[i].idade=a1[i+1].idade;
        strcpy(a1[i].endereco,a1[i+1].endereco);
        a1[i].matricula=a1[i+1].matricula;
    }
ctd--;
    }
printf("ctd: %d\n",ctd);
return ctd;
}

void print_aluno( t_aluno a1[] , int ctd){
    int i;
    if(ctd==NULL){
        printf("Nenhuma matricula cadastrada!!!\n");

    }else{
        for(i=0;i<ctd;i++){
            printf("Matricula: %d \n", a1[i].matricula);
            printf("Nome: %s", a1[i].nome);
            printf("Idade: %d \n", a1[i].idade);
            printf("Endereco: %s \n", a1[i].endereco);
            printf("--------------------------------\n");
        }
    }
}


int cadastra_aluno (t_aluno aluno[] , int ctd, int ctd2){
    int matricula,i;
    if(ctd2 ==1){
    printf("Informe a matricula do aluno: \n");
    scanf("%d", &matricula);
        for(i=0;i<ctd;i++){
            if (matricula==aluno[i].matricula){
                printf("Matricula ja cadastrado\n");
                return ctd;
            }
        }
    }
    fflush(stdin);
    printf("Informe o nome do aluno: \n");
    fgets(aluno[ctd].nome,50, stdin);
    aluno[ctd].matricula=matricula;
    fflush(stdin);
    printf("Informe a idade do aluno: \n");
    scanf("%d", &aluno[ctd].idade);
    fflush(stdin);
    printf("Informe o endereco do aluno: \n");
    fgets(aluno[ctd].endereco,100, stdin);
    ctd++;
    return ctd;
}

int menu_ordenar(){
    int opt;
    printf("Selecione qual campo deseja ordenar:\n");
    printf("1-Matricula\n");
    printf("2-Nome\n");
    printf("3-Idade\n");
    printf("4-Endereco\n");
    scanf("%d",&opt);
    return opt;
}
int menu (){
    int opt;
        printf("##MENU##\n\n1-Cadastrar aluno\n");
           printf("2-Procurar por matricula\n");
           printf("3-Listar todos alunos cadastrados\n");
           printf("4-Editar dados do aluno\n");
           printf("5-Excluir aluno \n");
           printf("6-Listar alunos de forma ordenada INCOMPLETO\n");
           printf("0-para sair\n\n## ##\n->");
    scanf("%d",&opt);
    return opt;
}

int buscar_matricula (t_aluno a1[], int ctd){
    int matricula,i,controlador= 21;

    printf("Informe a matricula: ");
    scanf("%d",&matricula);
    for (i=0;i<ctd;i++){
        if (matricula==a1[i].matricula){
            controlador=i;
        }
    }
    if(controlador==21){
        printf("Matricula nao cadastrada!!!!\n");
        return controlador;
    }else{
        printf("Nome: %s \n", a1[controlador].nome);
        printf("Idade: %d \n", a1[controlador].idade);
        printf("Matricula: %d \n", a1[controlador].matricula);
        printf("Endereco: %s \n", a1[controlador].endereco);
        printf("--------------------------------\n");
    }
    return controlador;
}

int editar_matricula (t_aluno a1[], int ctd){
int idade,opt,i=1,controlador,controlador2,ctd2=0;
t_aluno aux[20];
char escolha;
    controlador=buscar_matricula(a1,ctd);
    if (controlador == 21){
        return 0;
    }else{
        cadastra_aluno(aux,controlador,ctd2);
        printf("Voce deseja confirmar a alteracao? (s=sim - n=nao)");
        scanf("%c",&escolha);
           if(escolha=='s'){
                strcpy(a1[controlador].nome,aux[controlador].nome);
                a1[controlador].idade=aux[controlador].idade;
                strcpy(a1[controlador].endereco,aux[controlador].endereco);
                printf("Operacao concluida!!!!!\n");

            }else{
                printf("Operacao cancelada!!!!!!\n");

            }

    }
}
void BubbleSort_idade(t_aluno vetor[], int tamanho){
int aux, i,l;
int vet[20];
for(i=0;i<tamanho;i++){
vet[i]=vetor[i].idade;}
    for(l=tamanho-1; l>=1; l--) {
        for(i=0; i<l; i++)  {

                if(vet[i]>vet[i+1]){
                    aux=vet[i];
                    vet[i]=vet[i+1];
                    vet[i+1]=aux;
                }
        }
  }
for(i=0;i<tamanho;i++){
printf("Idade:%d\n",vet[i]);
}

}
void BubbleSort_matricula(t_aluno vetor[], int tamanho){
int aux, i,l;
int vet[20];
for(i=0;i<tamanho;i++){
vet[i]=vetor[i].matricula;}
    for(l=tamanho-1; l>=1; l--) {
        for(i=0; i<l; i++)  {
                if(vet[i]>vet[i+1]){
                    aux=vet[i];
                    vet[i]=vet[i+1];
                    vet[i+1]=aux;
                }
        }
  }
for(i=0;i<tamanho;i++){
printf("Matricula:%d\n",vet[i]);
}

}
void BubbleSort_nome(t_aluno vetor[], int tamanho){
    int i,j;
    t_aluno aux[20];
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho-1; j++){
            if(strcmp(vetor[i].nome, vetor[i+1].nome) > 0){
                //swap the two array elements
                strcpy(aux, vetor[j].nome);
                strcpy(vetor[j].nome, vetor[j+1].nome);
                strcpy(vetor[j+1].nome, aux);
            }
        }
    }
    for(i=0;i<tamanho;i++){
        printf("Nome:");
        puts(vetor[i].nome);
    }
}
void BubbleSort_endereco(t_aluno vetor[], int tamanho){
    int i,j;
    t_aluno aux[20];



    for(i = 0; i < tamanho; i++){

        for(j = 0; j < tamanho-1; j++){
            if(strcmp(vetor[i].endereco, vetor[i+1].endereco) > 0){
                //swap the two array elements

                strcpy(aux, vetor[j].endereco);
                strcpy(vetor[j].endereco, vetor[j+1].endereco);
                strcpy(vetor[j+1].endereco, aux);

            }
        }
    }
    for(i=0;i<tamanho;i++){
        printf("Endereco:");
        puts(vetor[i].endereco);
    }
}
int main(){
    int ctd2= 1;
    int ctd = 0;
    t_aluno a1[20];
    int opt,opt_ordenar;

    do{
        opt=menu();
    switch (opt){
        case 1:
            ctd=cadastra_aluno(a1,ctd,ctd2);
            system("pause");
            system("cls");
        break;
        case 2:
            buscar_matricula(a1,ctd);
            system("pause");
            system("cls");
        break;
        case 3:

            print_aluno(a1,ctd);
            system("pause");
            system("cls");
            break;
        case 4:
            editar_matricula(a1,ctd);
            system("pause");
            system("cls");
            break;
        case 5:
            ctd=deleta_aluno(a1,ctd);
            system("pause");
            system("cls");
            break;
        case 6:
            opt_ordenar=menu_ordenar();

            switch(opt_ordenar){
            case 1:
                BubbleSort_matricula(a1,ctd);
                break;


            case 2:
                BubbleSort_nome(a1,ctd);
                break;


            case 3:
                BubbleSort_idade(a1,ctd);
                break;


            case 4:
                BubbleSort_endereco(a1,ctd);
                break;

            case 0:
                printf("SAIR!!!!!!!!!\n");
                return 0;
                break;
            default:
                printf("Opcao invalida!!!!!\n");
                break;
            }
            system("pause");
            system("cls");
            break;
        case 0:
            printf("SAIR!!!!!!!!!\n");
            return 0;
        default:
            printf("Opcao invalida!!!!!\n");
            system("pause");
            system("cls");
            break;
    }
    }while(1);


    }
