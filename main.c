
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "equacoes.h"


int main() {
  bola *ptr_bola;
  robo *ptr_robo;
  double * posX_inicial_Robo;
  double * posY_inicial_Robo;
  double menor_distancia = 0; // distância entre o robô/bola
  double coeficiente_angular = 0;
  double teta_rad = 0;
  int opcao = 0;

  ptr_bola = (bola *)malloc(TAM * sizeof(bola)); // Aloca n structs da bola tal qual n é o num de linhas do arquivo

  ptr_robo = (robo *)malloc(TAM * sizeof(robo)); // Aloca n structs do robo tal qual n é o num de linhas do arquivo
  le_arquivo(ptr_bola);

  printf("Insira a posição inicial X do Robo: ");
  scanf("%lf", &ptr_robo[0].posX);
  printf("Insira a posição inicial Y do Robo: ");
  scanf("%lf", &ptr_robo[0].posY);
  
  ptr_robo[0].tempo = 0.00;
  
  if (ptr_robo[0].posX < 0.0 || ptr_robo[0].posX > 9.0 || ptr_robo[0].posY < 0.0 || ptr_robo[0].posY > 6.0){ // checa se o robô está nos limites do campo
    printf("Posição do robô fora dos limites do campo!!\n");
    exit('0');
    }
  menor_distancia = acha_menorDistancia(ptr_robo, ptr_bola);


  coeficiente_angular = (5.3-ptr_robo[0].posX)/(9-ptr_robo[0].posY);
  teta_rad = fabs(atan(coeficiente_angular)); // angulo entre a posição inicial e posição de interceptação
  montaStruct_robo(ptr_robo, teta_rad, menor_distancia, ptr_bola);
  montaVelocidades_bola(ptr_bola);
  
  if(ptr_bola[1000].posX-RAIO == ptr_robo[1000].posX && ptr_bola[1000].posY-RAIO == ptr_robo[1000].posY){
    printf("\nInterceptou!! :)\n");
    montaGraficos(ptr_robo, ptr_bola);
    menu(ptr_bola, ptr_robo, menor_distancia, teta_rad);
  }
  else{
    printf("ptr_bola[1000].posX - %lf\n", ptr_bola[1000].posX );
    printf("ptr_bola[1000].posY - %lf\n", ptr_bola[1000].posY );
    printf("ptr_robo[1000].posX - %lf\n", ptr_robo[1000].posX );
    printf("ptr_robo[1000].posY - %lf\n", ptr_robo[1000].posY );
    printf("Não interceptou :(\n");
  }

  
  free(ptr_bola);
  free(ptr_robo);
  
  return 0;
}
