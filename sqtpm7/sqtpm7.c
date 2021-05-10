#include <stdio.h>
#include <string.h>

struct lista_contatos {
    char nome[51];
    char endereco[101];
    char telefone[15];
    char nascimento[11];
    char token;
};

int main(void) {

    char operacao;
    struct lista_contatos contatos[1000];

    for (int i = 0; i < 1000; i++) {
        contatos[i].token = 'N';
    }

    scanf("%c", &operacao);

    while (operacao != 'f') {
        if (operacao == 'i') {
            insercao(contatos);
        }
        else if (operacao == 'r') {
            remover(contatos);
        }
        else if (operacao == 'b') {
            buscar(contatos);
        }
        else if (operacao == 'p') {
            imprimir(contatos);
        }

        scanf("%c", &operacao);
    }
}

void insercao(struct lista_contatos contatos[1000]) {
    char nome[51], endereco[101], telefone[15], nascimento[11];
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token == 'N') {
            count++;
            scanf(" %[^\n]", contatos[i].nome);
            scanf(" %[^\n]", contatos[i].endereco);
            scanf(" %[^\n]", contatos[i].telefone);
            scanf(" %[^\n]", contatos[i].nascimento);
            contatos[i].token = 'S';
            printf("Contato para %s inserido.\n", contatos[i].nome);
            printf("\n");
            break;
        }
    }
    if (count == 0) {
        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", endereco);
        scanf(" %[^\n]", telefone);
        scanf(" %[^\n]", nascimento);
        printf("O contato nao foi inserido.\n\n");
    }
}

void imprimir(struct lista_contatos contatos[1000]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token == 'N') {
            count++;
        }
    }
    printf("Listagem:\n");
    if (count == 1000) {
        printf("Nenhum contato.\n");
    }
    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token == 'S') {
            printf("(%d) %s\t%s\t%s\t%s\n", i+1, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].nascimento);
        }
    }
    printf("\n");
}

void remover(struct lista_contatos contatos[1000]) {

    char nomeRemover[51];
    int count = 0;
    scanf(" %[^\n]", nomeRemover);
    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token == 'S') {
            if (strcmp(contatos[i].nome, nomeRemover) == 0) {
                count++;
                for (int j = i; j < 1000; j++) {
                    contatos[j] = contatos[j+1];
                }
            }
        }
    }
    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token == 'S') {
            if (strcmp(contatos[i].nome, nomeRemover) == 0) {
                count++;
                for (int j = i; j < 1000; j++) {
                    contatos[j] = contatos[j+1];
                }
            }
        }
    }

    printf("Contatos de %s removidos: %d.\n\n", nomeRemover, count);

    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token != 'S') {
            contatos[i].token = 'N';
        }
    }
}

void buscar(struct lista_contatos contatos[1000]) {
    char nomeBuscado[51];
    int count = 0;
    scanf(" %[^\n]", nomeBuscado);
    printf("Resultado da busca:\n");
    for (int i = 0; i < 1000; i++) {
        if (contatos[i].token == 'S') {
            if (strstr(contatos[i].nome, nomeBuscado) != NULL) {
                count++;
                printf("(%d) %s\t%s\t%s\t%s\n", i+1, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].nascimento);
            }
        }     
    }

    if (count == 0) {
        printf("Nenhum contato.\n");
    }
    printf("\n");
}