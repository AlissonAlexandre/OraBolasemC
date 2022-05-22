#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct ball
{
    double tempo;
    double posX;
    double posY;
    double velX;
    double velY;
    double aX;  //Aceleração da bola no eixo X no instante de tempo
    double aY; //Aceleração da bola no eixo Y no instante de tempo
} bola;

typedef struct robot
{
    double tempo;
    double posX;
    double posY;
    double velX;
    double velY;
    double aX; //Aceleração da robo no eixo X no instante de tempo
    double aY; //Aceleração da robo no eixo Y no instante de tempo
} robo;



int main(){
    FILE *fp; //Ponteiro global de arquivo
    bola *ptr_bola;
    robo *ptr_robo;
    int tam_arquivo = 1001;
    // ponteiro da struct da bola
    ptr_bola = (bola*) malloc(tam_arquivo*sizeof(bola)); // Aloca n structs da bola tal qual n é o num de linhas do arquivo
    // ptr_bola->posX = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->posY = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->velX = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->velY = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->tempo = (double*) malloc(tam_arquivo*sizeof(double));

    //ponteiro da struct do robo
    ptr_robo = (robo*) malloc(tam_arquivo*sizeof(robo)); // Aloca n structs do robo tal qual n é o num de linhas do arquivo
    // ptr_bola->posX = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->posY = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->velX = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->velY = (double*) malloc(tam_arquivo*sizeof(double));
    // ptr_bola->tempo = (double*) malloc(tam_arquivo*sizeof(double));


    fp = fopen("data/trajetoria_bola.txt", "r");

    if(!fp){
        printf("Erro ao abrir arquivo!!\n");
        exit(1);
    }
    if(fp == NULL){
        printf("O arquivo não existe!!!\n");
        exit(1);
    }
    if(feof(fp)){
        printf("O arquivo está vazio!!!\n");
        exit(1);
    }
    
    double x = 0;
    double y = 0;
    double z = 0;
    char *valores;
    char string[25];
    for(int i = 0; i<tam_arquivo; i++){
        //printf("teste!!\n");
        if(feof(fp)) {
            printf("Fim do arquivo!");
            break;
        } 
    
        valores = fgets(string, 25, fp);
        
        sscanf(valores, "%lf %lf %lf\n", &ptr_bola[i].tempo, &ptr_bola[i].posX, &ptr_bola[i].posY);
        

        printf("Tempo = %lf  posX = %lf   poxY = %lf\n", ptr_bola[i].tempo, ptr_bola[i].posX, ptr_bola[i].posY);

    }

    fclose(fp);

    return 0;
}
