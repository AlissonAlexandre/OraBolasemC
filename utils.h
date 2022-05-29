#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#define TAM 1001
#define PI 3.14
#define RAIO_ROBO 0.21
#define RAIO_BOLA 0.09
#define RAIO (RAIO_BOLA+RAIO_ROBO) 

typedef struct {
  double tempo;
  double posX; // Posição da bola no eixo X no instante de tempo
  double posY; // Posição da bola no eixo Y no instante de tempo
  double velX; // Velocidade da bola no eixo X no instante de tempo
  double velY; // Velocidade da bola no eixo Y no instante de tempo
} bola;

typedef struct {
  double tempo; 
  double posX; //Posição do robo no eixo X no instante de tempo
  double posY; //Posição do robo no eixo Y no instante de tempo
  double velX; // Velocidade do robo no eixo X no instante de tempo
  double velY; // Velocidade do robo no eixo X no instante de tempo
  double vel; // Velocidade do robo na diagonal no instante de tempo
  double aX; // Aceleração do robo no eixo X no instante de tempo
  double aY; // Aceleração do robo no eixo Y no instante de tempo
  double aceleracao; // Aceleração do robo na diagonal no instante de tempo
  
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
    if (feof(fp)) {
      printf("Fim do arquivo!");
      break;
    }

    variaveis = fgets(string, 25, fp);

    sscanf(variaveis, "%lf %lf %lf\n", &ptr_bola[i].tempo, &ptr_bola[i].posX, &ptr_bola[i].posY);
    
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
    printf("\tPressione 6 para mostrar os gráficos\n\n"); 
    printf("\t***********************************\n\n\n"); 
    scanf("%d", &opcao);
    switch(opcao){
      case 0:
        return;
      case 1:
        printf("Menor distancia entre a posição inicial do robo e a final da bola: %lfm\n", menor_distancia);
        break;
      case 2:
        printf("Posição de interceptação X: %lfm\n", ptr_robo[1000].posX);
        printf("Posição de interceptação Y: %lfm\n", ptr_robo[1000].posY);
        break;
      case 3:
        printf("Angulo entre a posição inicial e a final: %lf°\n", converter_radToDeg(teta));
        break;
      case 4:
        printf("Raio de interceptação da bola: %lfm\n", RAIO_BOLA);
        printf("Raio de interceptação do robo: %lfm\n", RAIO_ROBO);
        printf("Raio de interceptação total: %lfm\n", RAIO);
        break;
      case 5:
        printf("=== INTEGRANTES DO GRUPO ===\n");
        printf("Alisson Alexandre B Barros - R.A. 22.221.009-8\n");
        printf("Carlos Massato H. Chinen - R.A. 22.221.010-6\n");
        printf("Matheus T. da Silva Arcanjo - R.A. 22.221.020-5\n");
        printf("Pedro Henrique Leite - R.A. 22.221.003-1\n");
        break;
      case 6:
        system("gnuplot ./gnuplot/posX_posY_robo.p");
        system("gnuplot ./gnuplot/velX_velY_robo.p");
        system("gnuplot ./gnuplot/aX_aY_robo.p");
        system("gnuplot ./gnuplot/distancia_relativa.p");
        break;
      default:
        printf("Por favor, insira uma opção válida!!!\n");
      
      
    }
  }
}

void montaGraficos(robo *ptr_robo, bola *ptr_bola){
  FILE *arquivo;
  arquivo = fopen("gnuplot/data/dados_robo.txt", "w");
  double posicao_relativaX = 0;
  double posicao_relativaY = 0;
  if(arquivo == NULL)
    {
        printf("Não foi possível criar o arquivo.\n");
        exit(1);
    }
  double dis_relativa, xB, xR, yB, yR;
  fprintf(arquivo, "tempo, posX_robo, posY_robo, velX, velY, aX, aY, vel, dis_relativa, posX_bola, posY_robo");
  for(int i = 0; i <= 1000; i++){
    xB = ptr_bola[i].posX;
    yB = ptr_bola[i].posY;
    xR = ptr_robo[i].posX;
    yR = ptr_robo[i].posY;
    dis_relativa = sqrt(pow((xB-xR),2) + pow((yB-yR),2 ));
    fprintf(arquivo, "\n%.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf, %.3lf, %.3lf", ptr_robo[i].tempo, ptr_robo[i].posX, ptr_robo[i].posY, ptr_robo[i].velX, ptr_robo[i].velY, ptr_robo[i].aX, ptr_robo[i].aY, ptr_robo[i].vel, dis_relativa, ptr_bola[i].posX, ptr_bola[i].posY);
  }
  fclose(arquivo);
}