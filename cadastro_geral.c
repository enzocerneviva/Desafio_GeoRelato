#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Relato {
    char catastrofe[50];
    char descricao[201];
    char data[20];
    int hora;
    float lat;
    float lon;
};


struct Cadastro {
    char nome[100];
    char telefone[100];
    char documento[100];
    char email[100];
    float localizacao_lat;
    float localizacao_lon;
};


void cadastro_relator(struct Cadastro *relatores, int *n) {

    printf("\nCadastro Relator %d:\n\n", *n);
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
    getchar();

    printf("Digite sua localização (longitude): ");
    scanf("%f", &(relatores[*n].localizacao_lon));
    getchar();

    *n += 2;
}

void cadastro_relatos(struct Relato *relatos, int *n) {
    *n -= 1;

    printf("\n--> Cadastro do Relato (máx: 50) <--\n");
    
    printf("\nInsira o tipo de catástrofe ocorrida (ex: enchente, incêndio, deslizamento): ");
    scanf("%s", relatos[*n].catastrofe);
    getchar(); 
    // usado para limpar o buffer após o scanf, pois ficou gurdado no buffer o enter (\n) que faria com que encerrace o fgets assim que começasse

    printf("Insira uma descrição da catástrofe (até 200 caracteres): ");
    fgets(relatos[*n].descricao, 201, stdin);
    relatos[*n].descricao[strcspn(relatos[*n].descricao, "\n")] = '\0';  // como o fgets lê o \n quando o enter é pressionado precisamos tira-lo e substituímos por \0 que indica o fim da string que antes estava depois do \n


    printf("Insira a data da catástrofe (DD/MM/AAAA): ");
    scanf("%s", relatos[*n].data);
    getchar();

    printf("Insira a hora do dia em que ocorreu a catástrofe (ex: 19): ");
    scanf("%i", &(relatos[*n].hora));
    getchar();

    printf("Insira a localização do acontecimento (latitude): ");
    scanf("%f", &(relatos[*n].lat));
    getchar();

    printf("Insira a localização do acontecimento (longitude): ");
    scanf("%f", &(relatos[*n].lon));
    getchar();

    *n += 2;
}

void exibir_relator(struct Cadastro *relatores, int n) {

    printf("\n--> Relator %d <--\n\n", n);

    printf("Nome: %s", relatores->nome);
    printf("Telefone: %s", relatores->telefone);
    printf("Documento: %s", relatores->documento);
    printf("Email: %s", relatores->email);
    printf("Latitude e Longitude: %.2f, %.2f\n", relatores->localizacao_lat, relatores->localizacao_lon);
}

void exibir_relatos(struct Relato *relatos, int n) {

    printf("\n--> Exibição do Relato %d <--\n\n", n);

    printf("Catástrofe: %s\n", relatos->catastrofe);
    printf("Descrição: %s\n", relatos->descricao);
    printf("Data: %s\n", relatos->data);
    printf("Hora: %02d:00\n", relatos->hora);
    printf("Localização: %.2f, %.2f \n", relatos->lat, relatos->lon);
    printf("\n");
}


int main() {

    // Criação Variáveis Struct
    struct Relato relatos[50]; // 50 relatos possíveis
    struct Cadastro relatores[20]; // 20 relatores possíveis

    // Criação de variáveis para administrar o número de relatos e relatores já cadastrados
    int n_relato = 1;
    int n_relator = 1;

    // Cadastros
    cadastro_relator(relatores, &n_relato);
    cadastro_relatos(relatos, &n_relator);

    // Exibições
    exibir_relator(relatores, n_relator);
    exibir_relatos(relatos, n_relato);

    return 0;
}
