
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "utils.h"
#include "equacoes.h"


/*
typedef struct {
  double tempo;
  double posX;
  double posY;
  double velX;
  double velY;
  double aX; // Aceleração da bola no eixo X no instante de tempo
  double aY; // Aceleração da bola no eixo Y no instante de tempo
} bola;
*/


int main() {
  bola *ptr_bola;
  robo *ptr_robo;
  double * posX_inicial_Robo;
  double * posY_inicial_Robo;
  double menor_distancia = 0; // distância entre o robô/bola

  // ponteiro da struct da bola
  ptr_bola = (bola *)malloc(TAM * sizeof(bola)); // Aloca n structs da bola tal qual n é o num de linhas do arquivo

  ptr_robo = (robo *)malloc(TAM * sizeof(robo)); // Aloca n structs do robo tal qual n é o num de linhas do arquivo
  le_arquivo(ptr_bola);
  printf("Insira a posição inicial X do Robo: ");
  scanf("%lf", &ptr_robo[0].posX);
  printf("Insira a posição inicial Y do Robo: ");
  scanf("%lf", &ptr_robo[0].posY);
  ptr_robo[0].tempo = 0.00;
  if (ptr_robo[0].posX < 0.0 || ptr_robo[0].posX > 9.0 || ptr_robo[0].posY < 0.0 || ptr_robo[0].posY > 6.0){
    printf("Posição do robô fora dos limites do campo!!\n");
    exit('0');
    }
  menor_distancia = acha_menorDistancia(ptr_robo[0].posX,ptr_robo[0].posY, &ptr_bola[1000]);
  printf("Menor distância entre os pontos: %lf", menor_distancia);
  
  
  return 0;
}
