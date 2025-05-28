#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cadastro{
    char nome[100];
    char telefone[100];
    char documento[100];
    char email[100];
    float localizacao_lat;
    float localizacao_lon;
};

void CadastrarRelator(struct Cadastro *relatores, int *n){
    printf("\nRelator %d:\n", *n);
    printf("\n");

    *n -= 1;

    printf("Digite seu nome completo: ");
    fgets(relatores[*n].nome, 100, stdin);

    printf("Digite seu telefone: ");
    fgets(relatores[*n].telefone, 100, stdin);

    printf("Digite seu documento: ");
    fgets(relatores[*n].documento, 100, stdin);

    printf("Digite seu email: ");
    fgets(relatores[*n].email, 100, stdin);

    printf("Digite sua localização (latitude): ");
    scanf("%f", &(relatores[*n].localizacao_lat));

    printf("Digite sua localização (longitude): ");
    scanf("%f", &(relatores[*n].localizacao_lon));

    n += 2;
}

void ExibirRelator(struct Cadastro *relatores) {
    printf("\n");
    printf("\n- Dados Cadastrados -\n");
    printf("\n");
    printf("Nome: %s", relatores->nome);
    printf("Telefone: %s", relatores->telefone);
    printf("Documento: %s", relatores->documento);
    printf("Email: %s", relatores->email);
    printf("Latitude e Longitude: %.2f, %.2f \n", relatores->localizacao_lat, relatores->localizacao_lon);
}

int main() {
    struct Cadastro relatores[20];
    int n = 1;

    CadastrarRelator(relatores, &n);
    ExibirRelator(&relatores[n]);
    
    return 0;
}
