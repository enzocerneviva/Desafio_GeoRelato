# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct Relato[20]{
  char catastrofe[50];
  char descricao[200];
  char data[20];
  int hora;
  int lat;
  int lon;
}

void cadastro_relatos(struct Relato *relato){
  int n = 0;
  for (int i = 0; i <= n + 1; i++){
      printf("esse é o i: %i \ne esse é o n: %i", i, n);
    }
    n += 1;
}
