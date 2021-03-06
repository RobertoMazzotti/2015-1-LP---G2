//ROBERTO MAZZOTTI DE SOUZA, THOMAZ PIRES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

typedef struct media
{
    int ind_baixa;
    int ind_alta;
    float nota_alta;
    float nota_baixa;
    float media_turma;
} t_media;
typedef struct aluno
{
    int matricula;
    int idade;
    char nome[50];
    char endereco[100];
    float nota[4];
} t_aluno;

void mostrar_aluno(t_aluno a1[],int ctd)
{
    int i;
    for(i=0; i<ctd; i++)
    {

        print_aluno(a1,i);
    }
}
int deleta_aluno(t_aluno a1[], int ctd)
{
    int i,controle;
    controle=buscar_matricula(a1,ctd);
    if (controle!=21)
    {
        for(i=controle; i<ctd; i++)
        {
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

void print_aluno( t_aluno a1[] , int ctd)
{
    int i,j;

    printf("Matricula: %d \n", a1[ctd].matricula);
    printf("Nome: %s", a1[ctd].nome);
    printf("Idade: %d \n", a1[ctd].idade);
    printf("Endereco: %s \n", a1[ctd].endereco);
    for(j=0; j<3; j++)
    {
        printf("Nota %d: %.1f\n",j+1,a1[ctd].nota[j]);
    }
    printf("--------------------------------\n");


}

void cadastra_aluno (t_aluno aluno[] , int ctd, int verif_matricula)
{   float nota;
    int matricula,i,j;
    if(verif_matricula ==1)
    {
        printf("Informe a matricula do aluno: \n");
        scanf("%d", &matricula);
        for(i=0; i<ctd; i++)
        {
            if (matricula==aluno[i].matricula)
            {
                printf("Matricula ja cadastrada\n");
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
    for(j=0; j<3; j++)
    {
        printf("Informe a nota %d: ",j+1);
        scanf("%f",&nota);
        if(nota<0 || nota >10){
            printf("Nota invalida!!!!!\n");
            return 0;
        }else{
        aluno[ctd].nota[j]=nota;
        }
    }



}

int menu_ordenar()
{
    int opt;
    printf("Selecione qual campo deseja ordenar:\n");
    printf("1-Matricula\n");
    printf("2-Nome\n");
    printf("3-Idade\n");
    printf("4-Endereco\n");
    scanf("%d",&opt);
    return opt;
}
int menu ()
{
    int opt;
    printf("##MENU##\n\n1-Cadastrar aluno\n");
    printf("2-Listar todos alunos cadastrados\n");
    printf("3-Editar dados do aluno\n");
    printf("4-Excluir aluno \n");
    printf("5-Listar alunos de forma ordenada \n");
    printf("6-Calcular estatistica da turma\n");
    printf("0-para sair\n\n## ##\n->");
    scanf("%d",&opt);
    return opt;
}

int buscar_matricula (t_aluno a1[], int ctd, int matricula)
{
    int i;


    for (i=0; i<ctd; i++)
    {
        if (matricula==a1[i].matricula)
        {
            print_aluno(a1,i);
            return i;
        }
    }


    return -1;
}

void media_aluno(t_aluno a1[],int ctd,float media[]){
int i,j;
    for(i=0;i<ctd;i++){
        for(j=0;j<MAX;j++){
             media[i]=media[i]+a1[i].nota[j];
        }
        media[i]=media[i]/MAX;
    }

}

int Calc_estat_turma (t_aluno a1[], int ctd)
{
    t_media media;
    float media2[ctd];
    int i,f,g,h;
    media.nota_alta=0;
    media.nota_baixa=10;
    float cont1=0,cont2=0,cont3=0;
    for(i=0;i<ctd;i++){
    media2[i]= 0;
    }
    media_aluno(a1,ctd,media2);

        for(f=0;f<ctd;f++){
            if(media.nota_alta<media2[f])
            {
             media.nota_alta=media2[f];
             media.ind_alta=f;
            }
        }

    for(g=0; g<ctd; g++)
    {
        if(media.nota_baixa>media2[g])
        {
            media.nota_baixa=media2[g];
            media.ind_baixa=g;
        }
    }

    for(i=0; i<ctd; i++)
    {
        if(media2[i]<=5)
        {
            cont1++;
        }
        else  if(media2[i]<=8)
        {
            cont2++;
        }
        else  if(media2[i]<=10)
        {
            cont3++;
        }
    }

    cont1=(cont1*100)/ctd;
    cont2=(cont2*100)/ctd;
    cont3=(cont3*100)/ctd;

    printf("Media mais alta:%.1f \n",media.nota_alta);
    print_aluno(a1,media.ind_alta);
    printf("Media mais baixa:%.1f \n",media.nota_baixa);
    print_aluno(a1,media.ind_baixa);
    printf("0,0-5,0-> %.2f %%\n\n\n",cont1);

    printf("5,1-8,0-> %.2f %%\n\n\n",cont2);

    printf("8,1-10 -> %.2f %%\n\n\n",cont3);
}

int editar_matricula (t_aluno a1[], int ctd)
{
    int i,idade,matricula,indice;
    t_aluno aux[20];
    char escolha;
    printf("Informe a matricula: ");
    scanf("%d",&matricula);
    indice=buscar_matricula(a1,ctd,matricula);
    if (indice == -1)
    {
        printf("Matricula nao cadastrada!!!!!\n");
        return 0;
    }
    else
    {
        cadastra_aluno(aux,ctd,0);
        printf("Voce deseja confirmar a alteracao? (s=sim - n=nao) ");
        scanf("%s",&escolha);
        printf("indice: %d",indice);
        puts(aux[indice].endereco);
        if(escolha=='s' || escolha== 'S')
        {
            strcpy(a1[indice].nome,aux[indice+1].nome);
            a1[indice].idade=aux[indice+1].idade;
            strcpy(a1[indice].endereco,aux[indice+1].endereco);
            for(i=0;i<MAX;i++){
                a1[indice].nota[i]=aux[indice+1].nota[i];
            }
            printf("Operacao concluida!!!!!\n");

        }
        else
        {
            printf("Operacao cancelada!!!!!!\n");

        }

    }
}

void BubbleSort_idade(t_aluno vetor[], int tamanho)
{
    int aux, i,l;
    int vet[20];
    for(i=0; i<tamanho; i++)
    {
        vet[i]=vetor[i].idade;
    }
    for(l=tamanho-1; l>=1; l--)
    {
        for(i=0; i<l; i++)
        {

            if(vet[i]>vet[i+1])
            {
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
            }
        }
    }
    for(i=0; i<tamanho; i++)
    {
        printf("Idade:%d\n",vet[i]);
    }

}

void BubbleSort_matricula(t_aluno vetor[], int tamanho)
{
    int aux, i,l;
    int vet[20];
    for(i=0; i<tamanho; i++)
    {
        vet[i]=vetor[i].matricula;
    }
    for(l=tamanho-1; l>=1; l--)
    {
        for(i=0; i<l; i++)
        {
            if(vet[i]>vet[i+1])
            {
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
            }
        }
    }
    for(i=0; i<tamanho; i++)
    {
        printf("Matricula:%d\n",vet[i]);
    }

}

void BubbleSort_nome(t_aluno vetor[], int tamanho)
{
    int i,j;
    t_aluno aux[20];
    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho-1; j++)
        {
            if(strcmp(vetor[i].nome, vetor[i+1].nome) > 0)
            {
                //swap the two array elements
                strcpy(aux, vetor[j].nome);
                strcpy(vetor[j].nome, vetor[j+1].nome);
                strcpy(vetor[j+1].nome, aux);
            }
        }
    }
    for(i=0; i<tamanho; i++)
    {
        printf("Nome:");
        puts(vetor[i].nome);
    }
}

void BubbleSort_endereco(t_aluno vetor[], int tamanho)
{
    int i,j;
    t_aluno aux[20];



    for(i = 0; i < tamanho; i++)
    {

        for(j = 0; j < tamanho-1; j++)
        {
            if(strcmp(vetor[i].endereco, vetor[i+1].endereco) > 0)
            {
                //swap the two array elements

                strcpy(aux, vetor[j].endereco);
                strcpy(vetor[j].endereco, vetor[j+1].endereco);
                strcpy(vetor[j+1].endereco, aux);

            }
        }
    }
    for(i=0; i<tamanho; i++)
    {
        printf("Endereco:");
        puts(vetor[i].endereco);
    }
}

int main()
{
    int ctd = 0;
    t_aluno a1[20];
    int opt,opt_ordenar;

    do
    {
        opt=menu();
        switch (opt)
        {
        case 1:
            cadastra_aluno(a1,ctd,1);
            ctd++;
            system("pause");
            system("cls");
            break;


        case 2:

            mostrar_aluno(a1,ctd);
            system("pause");
            system("cls");
            break;
        case 3:
            editar_matricula(a1,ctd);
            system("pause");
            system("cls");
            break;
        case 4:
            ctd=deleta_aluno(a1,ctd);
            system("pause");
            system("cls");
            break;
        case 5:
            opt_ordenar=menu_ordenar();

            switch(opt_ordenar)
            {
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
        case 6:
            Calc_estat_turma(a1,ctd);
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
    }
    while(1);


}
