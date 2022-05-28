#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "utils.h"
#include <stdbool.h>

/* Especificações do Robo:
Tipo: Small Size
Velocidade máxima: 2.24m/s
Aceleração: 4m/s²
Raio: 0.21m*/
#define VMAX_ROBO 2.3
#define ACELERACAO_ROBO 4
#define RAIO_ROBO 0.021
#define RAIO_BOLA 0.09
#define RAIO RAIO_ROBO+RAIO_BOLA 
// RAIO TOTAL = 0.21m

double acha_menorDistancia (robo *ptr_robo, bola *ptr_bola){
  double posX_inicial_Robo = ptr_robo[0].posX;
  double posY_inicial_Robo = ptr_robo[0].posY;
  return sqrt((pow(ptr_bola[1000].posX-posX_inicial_Robo, 2) + pow(ptr_bola[1000].posY-posY_inicial_Robo, 2)));
}

double acha_menorTempo(){
  
}

double tempo_robo_bola(double distancia, double velocidade){
  double tempo = 0;
  tempo = distancia/velocidade;

  return tempo;
}
double dist_robo_bola( double xR, double yR, double xB, double yB){
/*  =========================================
    CALCULA A DISTÂNCIA ENTRE O ROBÔ E A BOLA
    =========================================
    
    xR: posição X do robô
    yR: posição Y do robô
    xB: posição X da bola
    yB: posição Y da bola
  
  return -> fórmula da distância (pitágoras)
   */  
    return sqrt(pow((xB-xR),2) + pow((yB-yR),2 ));
 }

double calcula_tempo_aceleracao(double teta){
    /*=========================================
    CALCULA O TEMPO DE ACELERAÇÃO Y DO ROBO
    tempo de aceleraçãoX = tempo de desaceleraçãoX
    tempo de aceleraçãoY = tempo de desaceleraçãoY
    tempo de aceleraçãoX = tempo de aceleraçãoY
    =========================================
    V = v0 * at
   */  
    double aceleracaoX = ACELERACAO_ROBO* cos(teta);
    double velocidade_max_X = VMAX_ROBO * cos(teta);
    return(VMAX_ROBO/ACELERACAO_ROBO);
}


double calcula_distancia_aceleracaoX(double teta){
  /*=========================================
    CALCULA A DISTANCIA DE DESACELERAÇÃO X DO ROBO
    distancia de aceleração = distancia de desaceleração
    =========================================

   */  
  double V_maxX = VMAX_ROBO * cos(teta);
  double aceleracaoX = ACELERACAO_ROBO* cos(teta);
  double V_maxX_quadrado = pow(V_maxX, 2);
  return(V_maxX_quadrado/(2*aceleracaoX));
}

double calcula_distancia_aceleracaoY(double teta){
  /*=========================================
    CALCULA A DISTANCIA DE DESACELERAÇÃO X DO ROBO
    distancia de aceleração = distancia de desaceleração
    =========================================

   */  
  double V_maxY = VMAX_ROBO * sin(teta);
  double aceleracaoY = ACELERACAO_ROBO* sin(teta);
  double V_maxY_quadrado = pow(V_maxY, 2);
  return(V_maxY_quadrado/(2*aceleracaoY));
}


double calcula_distancia_VconstanteY(double distancia_total, double teta){
  /*=======================================================
    CALCULA O TEMPO EM QUE A VELOCIDADE DO ROBO É CONSTANTE
    =======================================================
    distancia_Vconstante = distanciaTotal - distanciaAceleracao - distanciaDesaceleração
   */  
  double distancia_VconstanteY = distancia_total - calcula_distancia_aceleracaoY(teta);
  return distancia_VconstanteY;
}

double calcula_distancia_VconstanteX(double distancia_total, double teta){
  /*=======================================================
    CALCULA O TEMPO EM QUE A VELOCIDADE DO ROBO É CONSTANTE
    =======================================================
    distancia_Vconstante = distanciaTotal - distanciaAceleracao - distanciaDesaceleração
   */  
  double distancia_VconstanteX = distancia_total - calcula_distancia_aceleracaoX(teta);
  return distancia_VconstanteX;
}


void montaStruct_robo(robo *ptr_robo, double teta_rad, double distancia_total, bola *ptr_bola){
  double tempo = 0.02;
  double velocidade = 0;
  double posX = ptr_robo[0].posX;
  double posY = ptr_robo[0].posY;
  bool posX_interceptou = false;
  bool posY_interceptou = false;
  double posicao_interceptacao_x = ptr_bola[1000].posX + RAIO;
  double posicao_interceptacao_y = ptr_bola[1000].posY + RAIO;
  double tempo_aceleracao = calcula_tempo_aceleracao(teta_rad);

  double maior_tempo_aceleracao = 0;
  int i = 1;

  while(tempo <= tempo_aceleracao + 0.02){
     velocidade += ACELERACAO_ROBO*0.02;
    if(velocidade > VMAX_ROBO){
      velocidade = VMAX_ROBO;
    }
    ptr_robo[i].vel = velocidade;
    ptr_robo[i].tempo = tempo;
    ptr_robo[i].aceleracao = 4;
    if(ptr_robo[i].posX < posicao_interceptacao_x){
      ptr_robo[i].velX = velocidade*cos(teta_rad);
      ptr_robo[i].posX = ptr_robo[i-1].posX + velocidade*cos(teta_rad)*0.02;
      ptr_robo[i].aX = ACELERACAO_ROBO*cos(teta_rad);
    } else{
      ptr_robo[i].velX = 0;
      ptr_robo[i].posX = posicao_interceptacao_x;
      ptr_robo[i].aX = 0;
    }

    if(ptr_robo[i].posY < posicao_interceptacao_y){
      ptr_robo[i].velY = velocidade*sin(teta_rad);
      ptr_robo[i].posY = ptr_robo[i-1].posY + velocidade*sin(teta_rad)*0.02;
      ptr_robo[i].aY = ACELERACAO_ROBO*sin(teta_rad);
    } else{
      ptr_robo[i].velY = 0;
      ptr_robo[i].posY = posicao_interceptacao_y;
      ptr_robo[i].aY = 0;
    }
    if(ptr_robo[i].aY == 0 & ptr_robo[i].aX == 0){
      ptr_robo[i].aceleracao = 0;
    }
    i++;
    tempo += 0.02;
  }

  while(ptr_robo[i-1].posX <= posicao_interceptacao_x  || ptr_robo[i-1].posY <= posicao_interceptacao_y){
    ptr_robo[i].vel = velocidade;
    ptr_robo[i].tempo = tempo;
    ptr_robo[i].aceleracao = 0;
    if(ptr_robo[i-1].posX < posicao_interceptacao_x){
      ptr_robo[i].velX = velocidade*cos(teta_rad);
      ptr_robo[i].posX = ptr_robo[i-1].posX + velocidade*cos(teta_rad)*0.02;
    } else{
      ptr_robo[i].velX = 0;
      ptr_robo[i].posX = ptr_robo[i-1].posX;
    }
    
    if(ptr_robo[i-1].posY < posicao_interceptacao_y){
      ptr_robo[i].velY = velocidade*sin(teta_rad);
      ptr_robo[i].posY = ptr_robo[i-1].posY + velocidade*sin(teta_rad)*0.02;
    } else{
      ptr_robo[i].velY = 0;
      ptr_robo[i].posY = ptr_robo[i-1].posY;
    }
    ptr_robo[i].aX = 0;
    ptr_robo[i].aY = 0;
   // printf("\nPosY Robo %d: %lf\n", i, ptr_robo[i].posY);
    //printf("\nPosX Robo %d: %lf\n", i, ptr_robo[i].posX);
   //printf("\nDistY intercept : %lf\n", posicao_interceptacao_y);
    //printf("\nDistX intercept : %lf\n", posicao_interceptacao_x);
    //printf("\nDistX intercept : %lf\n", posicao_interceptacao_x);
    //printf("\nDistY intercept : %lf\n", posicao_interceptacao_y);
    i++;
    tempo += 0.02;
  }
  
  while(i < 1001){
    ptr_robo[i].vel = 0;
    ptr_robo[i].velX = 0;
    ptr_robo[i].velY = 0;
    ptr_robo[i].posX = posicao_interceptacao_x;
    ptr_robo[i].posY = posicao_interceptacao_y;
    ptr_robo[i].aceleracao = 0;
    ptr_robo[i].aX = 0;
    ptr_robo[i].aY = 0;
    ptr_robo[i].tempo = tempo;
    tempo += 0.02;
    i++;
  }
}