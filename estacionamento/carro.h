/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   carro.h
 * Author: carlos
 *
 * Created on 14 de Novembro de 2017, 15:47
 */

#ifndef CARRO_H
#define CARRO_H
#define TAM_MATRICULA 9
#define TAM_MARCA 10

typedef struct dataParque {
    int ano;
    int mes;
    int dia;
    int min;
    int hora;

} Data_Parque;

/**
 */
typedef struct carro {
    char marca[TAM_MARCA];
    char matricula[TAM_MATRICULA];
    int estado;
    Data_Parque DataInicial;
    Data_Parque DataFinal;


} Carro;



#endif /* CARRO_H */


