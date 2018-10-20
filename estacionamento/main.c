/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: carlos
 *
 * Created on 5 de Dezembro de 2017, 14:50
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include "carro.h"

#define PISOS 3
#define FILAS 5
#define LUGARES 5
#define NUM_CARRO 15

/**
 * Função que permite ler os dados  do parque atraves de um ficheiro "Parque.dat"
 * @param carros Parque de estacionamento
 * @return 
 */
unsigned short readParque(Carro carros[][FILAS][LUGARES]) {
    FILE *pFicheiro;
    unsigned short cont;
    pFicheiro = fopen("Parque.dat", "rb");
    if (pFicheiro == (FILE*) NULL) {
        printf("\nImpossivel abrir ficheiro\n");
    } else {
        cont = fread(carros, sizeof (Carro), PISOS * FILAS*LUGARES, pFicheiro);
        fclose(pFicheiro);
    }
    return cont;
}

/**
 * Função que permite escrever os dados do Parque de estacionamento no ficheiro "Parque.dat".
 * @param carros Parque de estacionamento
 */
void writeParque(Carro carros[][FILAS][LUGARES]) {
    FILE *pFicheiro;
    pFicheiro = fopen("Parque.dat", "wb");
    if (pFicheiro == (FILE*) NULL) {
        printf("\nImpossivel abrir ficheiro\n");
    } else {
        fwrite(carros, sizeof (Carro), PISOS * FILAS *LUGARES, pFicheiro);
        fclose(pFicheiro);
    }
}

/**
 * Funçao main do projeto , onde é inciciado o programa e é lido do ficheiros os dados ja gravados
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {

    Carro parque[PISOS][FILAS][LUGARES];

    //verifica se existe o ficheiro , se existir lê , senao os lugares ficam todos livres
    if (readParque(parque) == NULL) {
        for (int a = 0; a < PISOS; a++) {
            for (int b = 0; b < FILAS; b++) {
                for (int c = 0; c < LUGARES; c++) {
                    parque[a][b][c].estado = 0;
                }
            }
        }
    } else {
        //lê de ficheiros
        readParque(parque);
    }

    menuInicial(parque);

    return 0;

}