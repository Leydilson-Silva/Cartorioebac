#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;                 // cria arquivo no BD
    file = fopen(arquivo, "w"); // cria arquivo no BD
    fprintf(file, cpf);         // salva valor da variavel
    fclose(file);               // fecha o arquivo

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, ",");         // colocando virgula
    fclose(file);               // fechando o arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, nome);        // adicionando nome
    fclose(file);               // fechando o arquivo

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, ",");         // colocando virgula
    fclose(file);               // fechando o arquivo

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, sobrenome);   // adicionando sobrenome
    fclose(file);               // fechando o arquivo

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, ",");         // colocando virgula
    fclose(file);               // fechando o arquivo

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, cargo);       // adicionando cargo
    fclose(file);               // fechando o arquivo

    file = fopen(arquivo, "a"); // atualizando o arquivo
    fprintf(file, ",");         // colocando virgula
    fclose(file);               // fechando o arquivo
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O usuário não se encontra no sistema.\n");
    }
    else
    {
        remove(cpf);
        printf("O usuário deletado com sucesso.\n");
    }

    system("pause");
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 0;
    for (laco = 1; laco = 1;)
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

        printf("### Cartório EBAC ###\n\n"); // Inicio menu
        printf("Escolha a opção desejada:\n\n");
        printf("\t1 - Registrar nomes.\n");
        printf("\t2 - Consultar nomes.\n");
        printf("\t3 - Deletar nomes.\n\n");
        printf("Opção: "); // fim menu

        scanf("%d", &opcao); // armazenando a escolha do usuário

        system("cls");

        switch (opcao)
        {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        default:
            printf("Esta opção não esta dísponivel.");
            system("pause");
            break;
        }
    }

    printf("\n\nEste software é de uso livre dos alunos.\n");
}
