#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TAM 1001

typedef struct {
  double tempo;
  double posX;
  double posY;
  double velX;
  double velY;
  double aX; // Aceleração da bola no eixo X no instante de tempo
  double aY; // Aceleração da bola no eixo Y no instante de tempo
} bola;

typedef struct {
  double tempo;
  double posX;
  double posY;
  double velX;
  double velY;
  double vel;
  double aX;
  double aY;
  double aceleracao; // Aceleração da robo no eixo X no instante de tempo
  
} robo;

void le_arquivo(bola *ptr_bola) {
  FILE *fp; // Ponteiro de arquivo
  fp = fopen("data/trajetoria_bola.txt", "r");

  if (!fp) {
    printf("Erro ao abrir arquivo!!\n");
    exit(1);
  }
  if (fp == NULL) {
    printf("O arquivo não existe!!!\n");
    exit(1);
  }
  if (feof(fp)) {
    printf("O arquivo está vazio!!!\n");
    exit(1);
  }

  char *variaveis;
  char string[25];
  for (int i = 0; i < TAM; i++) {
    // printf("teste!!\n");
    if (feof(fp)) {
      printf("Fim do arquivo!");
      break;
    }

    variaveis = fgets(string, 25, fp);

    sscanf(variaveis, "%lf %lf %lf\n", &ptr_bola[i].tempo, &ptr_bola[i].posX, &ptr_bola[i].posY);
     //printf("Tempo = %lf  posX = %lf   poxY = %lf\n", ptr_bola[i].tempo, ptr_bola[i].posX, ptr_bola[i].posY);
    
  }
  fclose(fp);
  }

