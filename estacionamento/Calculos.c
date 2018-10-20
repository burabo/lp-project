/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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
 * Função que permite calcular o custo do parque para um dado carro em funçao do tempo de permanencia.
 * Existem multas para permanencia acima de 2 meses e outras acima de 2 anos
 * @param parque Parque onde estao estacionados os carros
 * @param piso piso onde se encontra o carro a calcular o custo
 * @param fila fila onde se encontra o carro a calcular o custo
 * @param lugar lugar se encontra o carro a calcular o custo
 * @return 
 */
int calcularCusto(Carro parque[][FILAS][LUGARES], int piso, int fila, int lugar) {

    int min = 0;
    int custo = 0;
    int multas=0;
    if (parque[piso][fila][lugar].DataFinal.min > parque[piso][fila][lugar].DataInicial.min) {
        min = min + ((parque[piso][fila][lugar].DataFinal.min - parque[piso][fila][lugar].DataInicial.min));
    } else {
        min = min + ((60-parque[piso][fila][lugar].DataInicial.min) - parque[piso][fila][lugar].DataFinal.min);
    }
    min = min + (60*(parque[piso][fila][lugar].DataFinal.hora - parque[piso][fila][lugar].DataInicial.hora));
    
    min = min + ((60*24) * (parque[piso][fila][lugar].DataFinal.dia - parque[piso][fila][lugar].DataInicial.dia));
    
    if((parque[piso][fila][lugar].DataFinal.mes - parque[piso][fila][lugar].DataInicial.mes>2)){
        multas =50;
    }
   
    if((parque[piso][fila][lugar].DataFinal.ano - parque[piso][fila][lugar].DataInicial.ano)>2){
        multas=1000;
        
    }

    custo = 1 * min;
    
    multas =custo + multas;

    return custo;
}

