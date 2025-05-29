#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constantes para o cálculo de distância com Haversine
#define EARTH_RADIUS_KM 6371.0
#define PI 3.141592653589793

// Estrutura que representa um relato de desastre natural
struct Relato {
  char catastrofe[50];
  char descricao[201];
  char data[20];
  char hora[8];
  float lat;
  float lon;
};

// Estrutura que representa o cadastro de um relator
struct Cadastro {
  char nome[100];
  char telefone[100];
  char documento[100];
  char email[100];
  double localizacao_lat;
  double localizacao_lon;
};

// Função para cadastrar um relator no sistema
// Utiliza ponteiro para estrutura e manipulação de índice por referência
void cadastro_relator(struct Cadastro *relatores, int *n) {
  printf("\nCadastro do Relator\n\n");

  *n -= 1; // Ajuste temporário para usar o índice correto do vetor (trabalha com n-1)

  printf("Digite seu nome completo: ");
  fgets(relatores[*n].nome, 100, stdin);
  relatores[*n].nome[strcspn(relatores[*n].nome, "\n")] = '\0'; // Remove o '\n' do final

  printf("Digite seu telefone: ");
  fgets(relatores[*n].telefone, 100, stdin);

  printf("Digite seu documento: ");
  fgets(relatores[*n].documento, 100, stdin);

  printf("Digite seu email: ");
  fgets(relatores[*n].email, 100, stdin);

  // Leitura da localização geográfica do relator
  printf("Digite sua localização (latitude): ");
  scanf("%lf", &(relatores[*n].localizacao_lat));
  getchar();

  printf("Digite sua localização (longitude): ");
  scanf("%lf", &(relatores[*n].localizacao_lon));
  getchar();

  *n += 2; // Corrige o índice para novos cadastros
}

// Função para cadastrar um novo relato
void cadastro_relatos(struct Relato *relatos, int *n) {
  printf("\nCadastro do Relato %d (máx: 50)\n", *n);
  printf("\n--- Preencha as Informações Abaixo ---\n");

  *n -= 1; // Ajuste para o índice correto do vetor

  getchar();
  printf("\nInsira o tipo de desastre natural ocorrido: ");
  fgets(relatos[*n].catastrofe, 50, stdin);
  relatos[*n].catastrofe[strcspn(relatos[*n].catastrofe, "\n")] = '\0'; // Remove \n

  printf("Insira uma descrição do desastre natural(até 200 caracteres): ");
  fgets(relatos[*n].descricao, 201, stdin);
  relatos[*n].descricao[strcspn(relatos[*n].descricao, "\n")] = '\0'; 

  printf("Insira a data do desastre natural (DD/MM/AAAA): ");
  scanf("%s", relatos[*n].data);
  getchar();

  printf("Insira a hora do dia em que ocorreu o desastre natural (ex: 19:00): ");
  scanf("%s", relatos[*n].hora);
  getchar();

  printf("Insira a localização do acontecimento (latitude): ");
  scanf("%f", &(relatos[*n].lat));
  getchar();

  printf("Insira a localização do acontecimento (longitude): ");
  scanf("%f", &(relatos[*n].lon));
  getchar();

  *n += 2; // Corrige o índice novamente
}

// Função para exibir os dados do relator
void exibir_relator(struct Cadastro *relatores) {
  printf("\n%s\n\n", relatores->nome);
  printf("Telefone: %s", relatores->telefone);
  printf("Documento: %s", relatores->documento);
  printf("Email: %s", relatores->email);
  printf("Latitude e Longitude: %.2f, %.2f\n", relatores->localizacao_lat, relatores->localizacao_lon);
}

// Função para exibir um relato específico
void exibir_relatos(struct Relato *relatos, int n) {
  printf("\n--> Relato %d <--\n\n", n);
  printf("Desastre Natural: %s\n", relatos->catastrofe);
  printf("Descrição: %s\n", relatos->descricao);
  printf("Data: %s\n", relatos->data);
  printf("Hora: %s\n", relatos->hora);
  printf("Localização: %.2f, %.2f \n", relatos->lat, relatos->lon);
  printf("\n");
}

// Função auxiliar para converter graus em radianos
double deg2rad(double deg){
  return deg * (PI / 180);
}

// Implementação da fórmula de Haversine para calcular a distância entre dois pontos geográficos
double haversine(double lat1, double lon1, double lat2, double lon2){
  lat1 = deg2rad(lat1);
  lon1 = deg2rad(lon1);
  lat2 = deg2rad(lat2);
  lon2 = deg2rad(lon2);

  double dlat = lat2 - lat1;
  double dlon = lon2 - lon1;

  double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  return EARTH_RADIUS_KM * c;
}

// Função para comparar se data1 >= data2
int busca_por_data(char *data1, char *data2){
  int d1, m1, a1;
  int d2, m2, a2;

  sscanf(data1, "%d/%d/%d", &d1, &m1, &a1);
  sscanf(data2, "%d/%d/%d", &d2, &m2, &a2);

  if (a1 > a2) return 1;
  else if (a1 == a2) {
    if (m1 > m2) return 1;
    else if (m1 == m2) {
      if (d1 >= d2) return 1;
    }
  }

  return 0;
}

// Menu principal do programa
void menu(int *opcao) {
  printf("\n \n---------------------------- MENU ----------------------------\n \n");

  printf("O que deseja fazer?\n");
  printf("1. Cadastrar Relato\n");
  printf("2. Listar Todos os Relatos\n");
  printf("3. Buscar por Tipo de Desastre Natural\n");
  printf("4. Buscar por Localização (até 10 km de você)\n");
  printf("5. Buscar por Período\n");
  printf("6. Sair\n");

  printf("Escolha uma das opções: ");
  scanf("%d", opcao);
}

// Função principal - Ponto de entrada do programa
int main() {
  struct Relato relatos[50];           // Vetor para armazenar até 50 relatos
  struct Cadastro relatores[20];       // Vetor para armazenar até 20 relatores
  char data_busca[20];
  int n_relato = 1;                    // Controla quantos relatos foram cadastrados
  int n_relator = 1;                   // Controla os relatores cadastrados
  int opcao;

  printf("\n--------------------------- Bem vindo(a) ao GeoRelato! ---------------------------\n\n"); 
  printf("Esse é um sistema de cadastro e busca de relatos de desastres naturais com localização!\n");
  printf("\nPara fazer e procurar relatos, por medidas de segurança, precisamos que você faça um cadastro em nosso sistema.\n");

  cadastro_relator(relatores, &n_relator); // Cadastro obrigatório do usuário ao iniciar o sistema
  printf("\nCadastro realizado com sucesso!\n");
  printf("\nInformações: \n");
  exibir_relator(relatores); // Exibe os dados do relator

  do {
    menu(&opcao); // Exibe o menu e coleta a opção do usuário

    if(opcao < 1 || opcao > 6){
      printf("\nOpção Inválida...\n");
      continue;
    }

    switch(opcao){
      case 1:
        cadastro_relatos(relatos, &n_relato);
        printf("\n Relato Cadastrado com Sucesso! \n");
      break;

      case 2:
        for(int i = 0; i < n_relato - 1; i++){
          exibir_relatos(&relatos[i], i+1);
        }
        printf("\nRelatos Listados com Sucesso! \n");
      break;

      case 3:
        // Busca relatos por tipo de desastre natural
        printf("\n<--------------- BUSCA POR TIPO DE DESASTRE NATURAL --------------->\n");
        char busca[50];
        int encontrados = 0;

        printf("\nDigite o tipo de desastre natural que deseja buscar: ");
        scanf("%s", busca);
        getchar();

        for(int i = 0; i < n_relato; i++) {
          if(strcmp(relatos[i].catastrofe, busca) == 0) {
            exibir_relatos(&relatos[i], i+1);
            encontrados++;
          }
        }

        if (encontrados == 0)
          printf("\nNenhum desastre natural do tipo \"%s\" foi encontrado.\n", busca);
        else
          printf("\n%d relato(s) do tipo \"%s\" encontrado(s).\n", encontrados, busca);
      break;

      case 4:
        // Busca relatos a até 10km da localização do usuário
        printf("\n\n<--------------- BUSCA POR LOCALIZAÇÃO (ATÉ 10 KM DE VOCÊ) --------------->\n");

        for(int i = 0; i < (n_relato - 1); i++){
          double distancia = haversine(relatores[0].localizacao_lat, relatores[0].localizacao_lon, relatos[i].lat, relatos[i].lon);

          if(distancia <= 10){
            exibir_relatos(&relatos[i], i + 1);
            printf("\nDistância de você em KM: %.2f \n", distancia);
          }
        }
      break;

      case 5:
        // Busca relatos por data mínima
        printf("\n<--------------- BUSCA POR PERÍODO --------------->\n");
        printf("\nEscolha uma data para buscar relatos cadastrados posteriormente: ");
        scanf("%s", data_busca);
        printf("\nRelatos encontrados... \n");

        for(int i = 0; i < (n_relato - 1); i++){
          if(busca_por_data(relatos[i].data, data_busca) == 1){
            exibir_relatos(&relatos[i], i + 1);
          }
        }
      break;

      case 6:
        // Encerrar o programa
      break;
    }
  } while(opcao != 6);

  printf("\nPrograma encerrado.\n");
  return 0;
}
