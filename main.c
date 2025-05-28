#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "funcoes.h"

int main(){
  struct Cadastro relatores[20];
  struct Relato relato[50];
  int n_relatores = 1, n_relato = 1;
  
  CadastrarRelator(relatores, &n_relatores);
  ExibirRelator(&relatores[n_relatores]);
  cadastro_relatos(relato, &n_relato);

  return 0;
};
