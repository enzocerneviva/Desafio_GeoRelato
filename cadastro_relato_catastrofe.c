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


void CadastrarRelator(struct Cadastro *relatores, int *n) {
    printf("\nRelator %d:\n\n", *n);
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



void cadastro_relatos(struct Relato *relato, int *n) {
    *n -= 1;

    printf("\nInsira o tipo de catástrofe ocorrida (ex: enchente, incêndio, deslizamento): ");
    scanf("%s", relato[*n].catastrofe);
    getchar(); // usado para limpar o buffer após o scanf, pois ficou gurdado no buffer o enter (\n) que faria com que encerrace o fgets assim que começasse


    printf("Insira uma descrição da catástrofe (até 200 caracteres): ");
    fgets(relato[*n].descricao, 201, stdin);
    relato[*n].descricao[strcspn(relato[*n].descricao, "\n")] = '\0';  // como o fgets lê o \n quando o enter é pressionado precisamos tira-lo e substituímos por \0 que indica o fim da string que antes estava depois do \n


    printf("Insira a data da catástrofe (DD/MM/AAAA): ");
    scanf("%s", relato[*n].data);
    getchar();

    printf("Insira a hora do dia em que ocorreu a catástrofe (ex: 19): ");
    scanf("%i", &(relato[*n].hora));
    getchar();

    printf("Insira a localização do acontecimento (latitude): ");
    scanf("%f", &(relato[*n].lat));
    getchar();

    printf("Insira a localização do acontecimento (longitude): ");
    scanf("%f", &(relato[*n].lon));
    getchar();

    *n += 2;
}

void ExibirRelator(struct Cadastro *relatores, int n) {
    printf("\n- Dados Cadastrados -\n\n");
    printf("Nome: %s", relatores->nome);
    printf("Telefone: %s", relatores->telefone);
    printf("Documento: %s", relatores->documento);
    printf("Email: %s", relatores->email);
    printf("Latitude e Longitude: %.2f, %.2f\n", relatores->localizacao_lat, relatores->localizacao_lon);
}

void exibircatastrofe(struct Relato *relato, int n) {
        printf("Catástrofe: %s\n", relato->catastrofe);
        printf("Descrição: %s\n", relato->descricao);
        printf("Data: %s\n", relato->data);
        printf("Hora: %02d:00\n", relato->hora);
        printf("Localização: %.2f, %.2f \n", relato->lat, relato->lon);
        printf("\n");
    }


int main() {
    struct Relato relatos[50];
    struct Cadastro relatores[20];
    int n_relato = 1;
    int n_relator = 1;

    // Cadastros
    CadastrarRelator(relatores, &n_relator);
    cadastro_relatos(relatos, &n_relato);

    // Exibições
    ExibirRelator(relatores, n_relator);
    exibircatastrofe(relatos, n_relato);

    return 0;
}
