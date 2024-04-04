#include "setor.h"

struct setor{
    char nome[50];
    char descricao[50];
    Movel* moveis;
    struct setor *proximo;
};

Setor* lista_setor_cria(void) {
    return NULL;
}

Setor* lista_setor_adiciona_ordenado(Setor* Lista, char nome[], char descricao[]){
    Setor* novo;
    Setor* anterior = NULL;
    Setor* p = Lista;
    while(p != NULL && strcmp(nome, p->nome) > 0){
        anterior = p;
        p = p->proximo;
    }
    novo = (Setor*) malloc(sizeof(Setor));
    if (novo == NULL){
        printf("Erro de alocacao");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->descricao, descricao);
    novo->moveis = NULL;
    if(anterior == NULL){
        novo->proximo = Lista;
        Lista = novo;
    }
    else {
        novo->proximo = anterior-> proximo;
        anterior->proximo = novo;
    }
    return Lista;
}

Setor* lista_setor_busca(char nome[], Setor* l){
    Setor *p;
    for(p = l; p != NULL; p = p->proximo){
        if(strcmp(nome, p->nome) == 0){
            return p;
        }
    }
    return NULL;
}

int lista_setor_vazia(Setor* a){
	return (a==NULL);
}

void lista_setor_libera(Setor* l){
    Setor* p = l;
    Setor* t;
    while (p != NULL) {
        t = p->proximo;
        free(p);
        p = t;
    }
}

Setor* lista_setor_remove(Setor*a, char nome[]){
	Setor *anterior = NULL; 
    Setor *p = a;
    while(strcmp(p->nome, nome) !=0){
    	if (p==NULL)
        	return a;
        anterior = p;
        p = p->proximo;
    }
    if (anterior==NULL)
        a = p->proximo;
    else
        anterior->proximo = p->proximo;
    free(p);
    return a;
}

void lista_setor_imprime(Setor*a){
	Setor*p;
	for(p = a; p != NULL; p = p->proximo){
		printf("Nome: %s\t\t Descricao: %s\n", p->nome, p->descricao);
	}
}

void imprime_moveis_setor(Setor*a){
    Setor*p;
	for(p = a; p != NULL; p = p->proximo){
		printf("Setor: %s\t\t Descricao: %s\n", p->nome, p->descricao);
        lista_movel_imprime(p->moveis);
	}
}

//teste de funções para o arquivo
void lista_salvar_no_arquivo(Setor* a, char nome[]) {
    FILE* file = fopen(nome, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (a != NULL) {
        fprintf(file, "%s%s%s%s%f%d\n", a->nome, a->descricao, a->moveis->nome, a->moveis->tipo, a->moveis->preco, a->moveis->qtd_estoque);
        a = a->proximo;
    }

    fclose(file);
}


