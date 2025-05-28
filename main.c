#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Cadastro{
    char nome[100];
    char telefone[100];
    char documento[100];
    char email[100];
    float localizacao_lat;
    float localizacao_lon;
};

struct Relato{
  char catastrofe[50];
  char descricao[201];
  char data[20];
  int hora;
  float lat;
  float lon;
};


void menu() {
    printf("\n--- MENU ---\n");
    printf("1. Cadastrar relato\n");
    printf("2. Listar todos os relatos\n");
    printf("3. Buscar por tipo\n");
    printf("4. Buscar por localização\n");
    printf("5. Buscar por período\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

int main() {
    struct Relato relatos[50];
    struct Cadastro relatores[20];
    int n_relato = 0;
    int n_relator = 0;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            CadastrarRelator(relatores, &n_relator);
            cadastro_relatos(relatos, &n_relato);
            ExibirRelator(&relatores[n_relator - 1]);
            exibircatastrofe(&relatos[n_relato - 1]);
        } 
        else if (opcao == 2) {
            for (int i = 0; i < n_relato; i++) {
                ExibirRelator(&relatores[i]);
                exibircatastrofe(&relatos[i]);
            }
        } 
} while (opcao != 0);

    printf("Programa encerrado.\n");
    return 0;
}
