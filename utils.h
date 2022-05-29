#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TAM 1001
#define PI 3.14
#define RAIO_ROBO 0.21
#define RAIO_BOLA 0.09
#define RAIO (RAIO_BOLA+RAIO_ROBO)

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

double converter_radToDeg(double radiano){
    return(radiano * (180/PI));
}
      
void menu(bola *ptr_bola, robo *ptr_robo, double menor_distancia, double teta){
  int opcao = 0;
  while(1){
    printf("\n");
    printf("\t***********************************\n"); 
    printf("\t\tPROJETO ORA BOLAS\n"); 
    printf("\t***********************************\n"); 
    printf("\t\tMENU\n"); 
    printf("\t***********************************\n\n"); 
    printf("\tPressione 0 para Sair\n\n"); 
    printf("\tPressione 1 para mostrar a menor distância entre a posição inicial do robô e a posição final da bola\n\n"); 
    printf("\tPressione 2 para mostrar o ponto de interceptação\n\n"); 
    printf("\tPressione 3 para mostrar o ângulo entre a posição inicial e a final\n\n"); 
    printf("\tPressione 4 para mostrar o raio de interceptação\n\n"); 
    printf("\tPressione 5 para mostrar os integrantes do grupo\n\n"); 
    printf("\t***********************************\n\n\n"); 
    scanf("%d", &opcao);
    switch(opcao){
      case 0:
        return;
      case 1:
        printf("Menor distancia entre a posição inicial do robo e a final da bola: %lf\n", menor_distancia);
        break;
      case 2:
        printf("Posição de interceptação X: %lf\n", ptr_robo[1000].posX);
        printf("Posição de interceptação Y: %lf\n", ptr_robo[1000].posY);
        break;
      case 3:
        printf("Angulo entre a posição inicial e a final: %lf°\n", converter_radToDeg(teta));
        break;
      case 4:
        printf("Raio de interceptação da bola: %lf\n", RAIO_BOLA);
        printf("Raio de interceptação do robo: %lf\n", RAIO_ROBO);
        printf("Raio de interceptação total: %lf\n", RAIO);
        break;
      case 5:
        printf("=== INTEGRANTES DO GRUPO ===\n");
        printf("Alisson Alexandre B Barros - R.A. 22.221.009-8\n");
        printf("Carlos Massato H. Chinen - R.A. 22.221.010-6\n");
        printf("Matheus T. da Silva Arcanjo - R.A. 22.221.020-5\n");
        printf("Pedro Henrique Leite - R.A. 22.221.003-1\n");
        break;
      default:
        printf("Por favor, insira uma opção válida!!!\n");
      
    }
  }
}

