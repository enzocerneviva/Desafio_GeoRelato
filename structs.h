#ifndef STRUCTS_H
#define STRUCTS_H

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

#endif