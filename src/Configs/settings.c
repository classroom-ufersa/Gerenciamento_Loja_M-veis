<<<<<<< HEAD
#include "settings.h"
#define Max 50

void menu(void){
    printf("\n***************************\n");
    printf("\t\tCadastro de moveis/setores.\n");
    printf("1-Adicionar Movel\n");
    printf("2-Remover Movel\n");
    printf("3-Editar Movel\n");
    printf("4-Adicionar Setor\n");
    printf("5-Remover Setor\n");
    printf("6-Listar setores e moveis\n");
    printf("7-Buscar Movel\n");
    printf("8-Sair\n");
    printf("***************************\n");
}



void limpa_buffer(void){};

void listar(void){};

=======
#include "settings.h"

void menu(void){
    printf("\n***************************\n");
    printf("\t\tCadastro de moveis/setores.\n");
    printf("1-Adicionar Movel\n");
    printf("2-Remover Movel\n");
    printf("3-Editar Movel\n");
    printf("4-Adicionar Setor\n");
    printf("5-Remover Setor\n");
    printf("6-Listar setores e moveis\n");
    printf("7-Buscar Movel\n");
    printf("8-Sair\n");
    printf("***************************\n");
}
void limpa_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void listar(void){};

>>>>>>> c0172dd47f5c837269cb299655faa86a44e098e4
void upper(){};