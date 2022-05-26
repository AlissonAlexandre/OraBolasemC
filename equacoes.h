#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "utils.h"
/*
typedef struct {
  double tempo;
  double posX;
  double posY;
  double velX;
  double velY;
  double aX; // Aceleração da bola no eixo X no instante de tempo
  double aY; // Aceleração da bola no eixo Y no instante de tempo
} bola2;
*/
double acha_menorDistancia (double posX_inicial_Robo, double posY_inicial_Robo, bola *ptr_bola){
  return sqrt((pow(ptr_bola->posX-posX_inicial_Robo, 2) + pow(ptr_bola->posY-posY_inicial_Robo, 2)));
}

double tempo_robo_bola(double distancia, double velocidade){
  double tempo = 0;
  tempo = distancia/velocidade;

  return tempo;
}