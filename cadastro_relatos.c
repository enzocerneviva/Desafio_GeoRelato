# include <string.h>
# include <stdio.h>
# include <stdlib.h>

struct Relato{
  char catastrofe[50];
  char descricao[201];
  char data[20];
  int hora;
  float lat;
  float lon;
};

struct Relato relato[20];

void cadastro_relatos(struct Relato *relato, int *n){
  *n -= 1;
  
  printf("Insira o tipo de catástrofe ocorrida (ex: enchente, incêndio, deslizamento): ");
  scanf("%s", relato[*n].catastrofe);
  getchar(); // usado para limpar o buffer após o scanf, pois ficou gurdado no buffer o enter (\n) que faria com que encerrace o fgets assim que começasse
  
  printf("Insira uma descrição da catástrofe (até 200 caracteres): ");
  fgets(relato[*n].descricao, 201, stdin);
  relato[*n].descricao[strcspn(relato[*n].descricao, "\n")] = '\0'; // uso de '' para char
  // como o fgets lê o \n quando o enter é pressionado precisamos tira-lo e substituímos por \0 que indica o fim da string que antes estava depois do \n

  printf("Insira a data da catástrofe (00/00/0000): ");
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
}

int main(){
  int n = 1;
  cadastro_relatos(relato, &n);
}
