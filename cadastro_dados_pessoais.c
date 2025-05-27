#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("Nome: %s\n", d->nome);
    printf("Telefone: %s\n", d->telefone);
    printf("Documento: %s\n", d->documento);
    printf("Email: %s\n", d->email);
    printf("Localização: %s\n", d->localizacao);
}

int main() {
    struct cadastro d;

    printf("Digite seu nome completo: ");
    scanf("%s", d.nome);  
    printf("Digite seu telefone: ");
    scanf("%s", d.telefone);
    printf("Digite seu documento: ");
    scanf("%s", d.documento);
    printf("Digite seu email: ");
    scanf("%s", d.email);
    printf("Digite sua localização em coordenadas: ");
    scanf("%s", d.localizacao);
                        
    RegistrarRelator(&d);
    return 0;
}
