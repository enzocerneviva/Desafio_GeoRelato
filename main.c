#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EARTH_RADIUS_KM 6371.0
#define PI 3.141592653589793

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
  double localizacao_lat;
  double localizacao_lon;
};

void cadastro_relator(struct Cadastro *relatores, int *n) {

  printf("\nCadastro do Relator\n\n");
  *n -= 1;

  printf("Digite seu nome completo: ");
  fgets(relatores[*n].nome, 100, stdin);
  relatores[*n].nome[strcspn(relatores[*n].nome, "\n")] = '\0';

  printf("Digite seu telefone: ");
  fgets(relatores[*n].telefone, 100, stdin);

  printf("Digite seu documento: ");
  fgets(relatores[*n].documento, 100, stdin);

  printf("Digite seu email: ");
  fgets(relatores[*n].email, 100, stdin);

  printf("Digite sua localização (latitude): ");
  scanf("%lf", &(relatores[*n].localizacao_lat));
  getchar();

  printf("Digite sua localização (longitude): ");
  scanf("%lf", &(relatores[*n].localizacao_lon));
  getchar();

  *n += 2;
}

void cadastro_relatos(struct Relato *relatos, int *n) {
  *n -= 1;

  printf("\nCadastro do Relato %d (máx: 50)\n", *n);
  printf("\n--- Preencha as Informações Abaixo ---\n");
  
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

void exibir_relator(struct Cadastro *relatores) {

  printf("\n--> %s <--\n\n", relatores->nome);

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

double deg2rad(double deg){
  return deg * (PI / 180);
}

double haversine(double lat1, double lon1, double lat2, double lon2){
  // converte graus para radianos
  lat1 = deg2rad(lat1);
  lon1 = deg2rad(lon1);
  lat2 = deg2rad(lat2);
  lon2 = deg2rad(lon2);

  // diferença entre as coordenadas 

  double dlat = lat2 - lat1;
  double dlon = lon2 - lon1;

  // fórmula de haversine

  double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  // retorna a distância
  return EARTH_RADIUS_KM * c;
}

void menu(int *opcao) {
  printf("\n \n---------------------------- MENU ----------------------------\n \n");

  printf("O que deseja fazer?\n");
  printf("1. Cadastrar Relato\n");
  printf("2. Listar Todos os Relatos\n");
  printf("3. Buscar por Tipo de Catástrofe\n");
  printf("4. Buscar por Localização (até 10 km de você)\n");
  printf("5. Buscar por Período\n");
  printf("6. Sair\n");

  printf("Escolha uma das opções: ");
  scanf("%d", opcao);
}

int main() {
  struct Relato relatos[50];
  struct Cadastro relatores[20];
  int n_relato = 1;
  int n_relator = 1;
  int opcao;

  printf("\n--------------------------- Bem vindo(a) ao GeoRelato! ---------------------------\n\n --> Para fazer os relatos, por medidas de segurança, precisamos que você faça um cadastro em nosso sistema... \n");
  cadastro_relator(relatores, &n_relato);
  printf("\nCadastro realizado com sucesso!...\n");
  printf("\nInformações: \n");
  exibir_relator(relatores);

  do {
    menu(&opcao);

    if(opcao < 1 || opcao > 6){
      printf("\nOpção Inválida...\n");
      continue;
    }

    switch(opcao){
      case 1:
        cadastro_relatos(relatos, &n_relator);
        printf("\n Relato Cadastrado com sucesso! \n");
      break;
      case 2:
        // listagem dos relatos
      break;
      case 3:
        // busca por catástrofe
      break;
      case 4:
        // busca por localização
      break;
      case 5:
        // buscar por período
      break;
      case 6:

      break;
    };
  }while(opcao != 6);

  printf("\nPrograma encerrado.\n");
  return 0;
}

