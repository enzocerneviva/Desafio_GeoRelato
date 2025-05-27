#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RELATEDORES 10

struct cadastro {
    char nome[100];
    char telefone[100];
    char documento[100];
    char email[100];
    char localizacao[100];
};

void RegistrarRelator(struct cadastro *d) {
    printf("\n");
    printf("\n- Dados Cadastrados -\n");
    printf("\n");
    printf("Nome: %s", d->nome);
    printf("Telefone: %s", d->telefone);
    printf("Documento: %s", d->documento);
    printf("Email: %s", d->email);
    printf("Localização: %s\n", d->localizacao);
}

int main() {
    struct cadastro relatores[MAX_RELATEDORES];
    int quantidade;

    printf("Quantos relatores deseja cadastrar (máx 10)? ");
    scanf("%d", &quantidade);
    fgets(relatores, 100, stdin);  

    if (quantidade < 1 || quantidade > MAX_RELATEDORES) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nRelator %d:\n", i + 1);
        printf("\n");
        
        printf("Digite seu nome completo: ");
        fgets(relatores[i].nome, 100, stdin);
        printf("Digite seu telefone: ");
        fgets(relatores[i].telefone, 100, stdin);
        printf("Digite seu documento: ");
        fgets(relatores[i].documento, 100, stdin);
        printf("Digite seu email: ");
        fgets(relatores[i].email, 100, stdin);
        printf("Digite sua localização em coordenadas: ");
        fgets(relatores[i].localizacao, 100, stdin);

    RegistrarRelator(&relatores[i]);
    }

    return 0;
}
