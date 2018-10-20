/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "LP_Leitura.h"
#include "LP_Utils.h"
#include <regex.h>
#include <stdbool.h>



#include "carro.h"
#define PISOS 3
#define FILAS 5
#define LUGARES 5
#define NUM_CARRO 15
//#include "LP_Leitura.c"
//#include "LP_Utils.c"

/*
 * 
 */

void menuInicial(Carro arrayCarros[][FILAS][LUGARES]);
void procurarCarro(Carro parque[][FILAS][LUGARES]);
void informacoes();
void estadoLugar(Carro parque[][FILAS][LUGARES]);
void imprimirLugares(Carro parque[][FILAS][LUGARES]);
void imprimirOcupados(Carro parque[][FILAS][LUGARES]);
void imprimirLivres(Carro parque[][FILAS][LUGARES]);
void estacionar(Carro parque[][FILAS][LUGARES]);
void removerCarro(Carro parque[][FILAS][LUGARES]);
void administrarParque(Carro parque[][FILAS][LUGARES]);
void estacionarAutomaticamente(Carro parque[][FILAS][LUGARES]);
void desenhar(Carro parque[][FILAS][LUGARES]);

/**
 * Esta função imprime as regras do programa para o utilizador ser esclarecido sobre o mesmo
 */
void informacoes(Carro parque[][FILAS][LUGARES]) {
    
    int x=0, y=0, z=0, i=0;
    
    x = PISOS;
    y = FILAS;
    z = LUGARES;

    printf("\n*********************************************Regras*******************************************************\n\n");
    printf("\n1-A matricula só pode ter 8 caracteres do tipo 00-00-AA .\n");
    printf("\n2-O Parque é composto por %d piso(s); %d fila(s); %d lugares.\n", x, y, z);
    printf("\n3-Se perder o carro pode encontra-lo na opção '7-Pesquisar do lugar' |Deve saber a matrícula!|\n");
    printf("\n4-Para remover o carro basta introduzir o piso, fila e lugar na opção '6-Remover carro'.\n");
    printf("\n5-Se usar a opção '2-Imprimir Lugares' só vão aparecer os lugares livres |"
            "\nSe faltar um lugar é porque esse lugar esta ocupado !|\n");
    printf("\n6-Se escolher a opção '8-Pesquisar carro' permite saber se o carro existe no parque.\n");
    printf("\n********************************************************************************************************\n");
    printf("Intoduza 0 e prima ENTER para regressar ao Menu Inicial.\n");
    readInt(&i, 0, 0, "--> ");

    if (i == 0) {
        menuInicial(parque);
    }

}

/**
 * Esta função permite ao utilizador verificar se existe um carro no parque atraves da matricula, 
 * a função vai percorrer a matriz tridimensional , verificar se esta estacionado e imprimir o local
ver se existe na estrutura.
 * @param parque Parque de estacionamento
 */
void procurarCarro(Carro parque[][FILAS][LUGARES]) {
    int i = 1, a = 0;

    char matriculaTemporaria[10];

    readString(matriculaTemporaria, 10, "Introduza a matricula do carro que pretende procurar:");


    for (int u = 0; u < PISOS; u++) {
        for (int o = 0; o < FILAS; o++) {
            for (int m = 0; m < LUGARES; m++) {
                i = strcmp(parque[u][o][m].matricula, matriculaTemporaria);
                if (i == 0 && parque[u][o][m].estado == 1) {
                    printf("\nO carro encontrasse no lugar : ");
                    printf("Piso:%d  ", u);
                    printf("Fila:%d  ", o);
                    printf("Lugar:%d  \n", m);
                    a = 1;

                } else {

                }
            }
        }
    }
    if (a == 0) {
        printf("\nO carro nao existe!!!\n");
    }
}

/**
  * Função que permite verificar o estado de um determinado lugar atraves da introduçao 
 * do piso , fila e lugar , se estiver ocupado ,  é imprimida a marca e a martricula do respectivo carro
 * @param parque Parque de estacionamento
 */

void estadoLugar(Carro parque[][FILAS][LUGARES]) {
    int aa, bb, cc;


    readInt(&aa, 0, PISOS - 1, "Introduza o piso : ");

    readInt(&bb, 0, FILAS - 1, "Introduza a fila : ");

    readInt(&cc, 0, LUGARES - 1, "Introduza o lugar : ");

    if (parque[aa][bb][cc].estado == 1) {

        printf("\n******************************\n");
        printf("O lugar esta ocupado!\n");
        printf("A marca é: %s\n", parque[aa][bb][cc].marca);
        printf("A matricula é: %s\n", parque[aa][bb][cc].matricula);
    } else {
        printf("\n******************************\n");
        printf("O lugar esta vazio!!!");

    }
}

/**
 * Função que imprime todos os lugares do parque , dizendo se o mesmo esta ocupado ou livre
 * @param parque Parque de estacionamento
 */
void imprimirLugares(Carro parque[][FILAS][LUGARES]) {

    for (int a = 0; a < PISOS; a++) {
        printf("\n*******************************");
        printf("\n********** PISO %d *************\n", a);
        printf("*******************************\n");
        for (int b = 0; b < FILAS; b++) {
            printf("\n********** FILA %d *************\n", b);
            for (int c = 0; c < LUGARES; c++) {
                printf("Piso:%d ", a);
                printf("Fila:%d ", b);
                printf("Lugar:%d --->", c);
                if (parque[a][b][c].estado == 0) {
                    printf("Livre\n");
                } else {
                    printf("Ocupado\n");
                }
            }
        }
    }
}

/**
 * Função que percorrer a matriz tridimensional e se o lugar estiver ocupado , é imprimido
 * @param parque Parque de estacionamento
 */
void imprimirOcupados(Carro parque[][FILAS][LUGARES]) {
    int i = 0;

    for (int u = 0; u < PISOS; u++) {
        for (int o = 0; o < FILAS; o++) {
            for (int m = 0; m < LUGARES; m++) {
                if (parque[u][o][m].estado == 1) {
                    printf("Ocupado--->");
                    printf("Piso:%d ", u);
                    printf("Fila:%d ", o);
                    printf("Lugar:%d \n", m);
                    i = 1;

                }
            }
        }
    }

    if (i == 0) {
        printf("\nNao existe nenhum lugar ocupado!!!\n");
    }
}

/**
 * Função que percorre a matriz tridimensional e imprime os lugares livres
 * @param parque Parque de estacionamento
 */
void imprimirLivres(Carro parque[][FILAS][LUGARES]) {

    for (int u = 0; u < PISOS; u++) {
        printf("\n*******************************\n");
        printf("********** PISO %d *************\n", u);
        printf("*******************************\n");
        for (int o = 0; o < FILAS; o++) {
            printf("\n********** FILA %d *************\n", o);
            for (int m = 0; m < LUGARES; m++) {
                if (parque[u][o][m].estado == 0) {
                    printf("Livre--> ");
                    printf("Piso:%d ", u);
                    printf("Fila:%d ", o);
                    printf("Lugar:%d \n", m);

                }
            }
        }
    }

}

/**
 * Funçao que imprime um "desenho" do parque , representando o lugar ocupado com um asterisco
 * e deixando o lugar livre vazio
 * @param parque Parque de estacionamento
 */
void desenhar(Carro parque[][FILAS][LUGARES]) {
    int i, j, k = 0;
    char v2[PISOS][FILAS][LUGARES];

    for (int u = 0; u < PISOS; u++) {
        for (int o = 0; o < FILAS; o++) {
            for (int m = 0; m < LUGARES; m++) {
                if (parque[u][o][m].estado == 0) {
                    //Código ASCII do espaço
                    v2[u][o][m] = 32;
                } else {
                    //Código ASCII do asterisco
                    v2[u][o][m] = 42;
                }
            }
        }
    }

    for (i = 0; i < PISOS; i++) {

        printf("        Piso %d         \n", i);

        for (j = 0; j < FILAS; j++) {
            printf(" ____ ____ ____ ____ ____\n");
            printf("|    |    |    |    |    |\n");
            printf("| %c  | %c  | %c  | %c  | %c  | %d\n", v2[i][j][0], v2[i][j][1], v2[i][j][2], v2[i][j][3], v2[i][j][4], j);
            printf("|____|____|____|____|____|\n");

        }
        printf("   0    1    2    3    4\n");
        printf("\n");
    }
}

/**
 * Funçao que permite ao utilizador estacionar automaticamente o carro
 * fazendo com que o programa procure o lugar vazio mais perto desde o inicio do parque
 * @param parque Parque de estacionamento
 */
void estacionarAutomaticamente(Carro parque[][FILAS][LUGARES]) {

    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);
    char * matriculaTemporaria;
    int i = 0;
    int x1, x2, x3, c = 0;
    int piso = 0, fila = 0, lugar = 0;

    if (i == 0) {
        for (int u = 0; u < PISOS; u++) {
            for (int o = 0; o < FILAS; o++) {
                for (int m = 0; m < LUGARES; m++) {
                    if (parque[u][o][m].estado == 0 && i == 0) {

                        printf("Introduza a marca do carro: ");
                        scanf("%s", &parque[u][o][m].marca);

                        printf("Introduza a matricula do carro: ");
                        scanf("%s", &parque[u][o][m].matricula);

                        //Apenas funciona para esta forma! => 00-00-AA
                        //Consultar tabela ASCII!

                        for (x1 = 0; x1 < 2; x1++) {
                            if (parque[u][o][m].matricula[x1] < 48 ||
                                    parque[u][o][m].matricula[x1] > 57) {
                                c++;
                            }
                        }

                        for (x2 = 3; x2 < 5; x2++) {
                            if (parque[u][o][m].matricula[x2] < 48 ||
                                    parque[u][o][m].matricula[x2] > 57) {
                                c++;
                            }
                        }

                        for (x3 = 6; x3 < 8; x3++) {
                            if (parque[u][o][m].matricula[x3] < 65 ||
                                    parque[u][o][m].matricula[x3] > 90) {
                                c++;
                            }
                        }

                        if (parque[u][o][m].matricula[2] != 45 ||
                                parque[u][o][m].matricula[5] != 45) {
                            c++;
                        }

                        if (c == 0) {
                            parque[u][o][m].estado = 1;
                            piso = u;
                            fila = o;
                            lugar = m;
                            printf("Carro introduzido com sucesso.");
                        } else {
                            printf("Matrícula Inválida. Carro não introduzido.");
                        }

                        i = 1;

                    }
                }
            }
        }
    } else {

    }
    //armazena a data e horas em que o carro foi estacionado
    parque[piso][fila][lugar].DataInicial.ano = (ptr->tm_year + 1900);
    parque[piso][fila][lugar].DataInicial.dia = ptr->tm_mday;
    parque[piso][fila][lugar].DataInicial.mes = (ptr->tm_mon + 1);
    parque[piso][fila][lugar].DataInicial.hora = ptr->tm_hour;
    parque[piso][fila][lugar].DataInicial.min = ptr->tm_min;

    //escreve em ficheiros
    writeParque(parque);

}

/**
 * Função que permite ao utilizador estacionar um carro num lugar que esteja livre
 * 
 * @param parque Parque de estacionamento
 */

void estacionar(Carro parque[][FILAS][LUGARES]) {

    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);
    char * matriculaTemporaria;
    int x1, x2, x3, c = 0;
    int piso, fila, lugar;

    readInt(&piso, 0, PISOS - 1, "Introduza o piso : ");
    readInt(&fila, 0, FILAS - 1, "Introduza a fila : ");
    readInt(&lugar, 0, LUGARES - 1, "Introduza o lugar : ");

    if (parque[piso][fila][lugar].estado == 1) {
        printf("\n********************************\n");
        printf("O lugar esta ocupado!!!\n\n");
        printf("\n********************************\n");
    } else {


        printf("Introduza a marca do carro: ");
        scanf("%s", &parque[piso][fila][lugar].marca);

        printf("Introduza a matricula do carro: ");
        scanf("%s", &parque[piso][fila][lugar].matricula);

        for (x1 = 0; x1 < 2; x1++) {
            if (parque[piso][fila][lugar].matricula[x1] < 48 ||
                    parque[piso][fila][lugar].matricula[x1] > 57) {
                c++;
            }
        }

        for (x2 = 3; x2 < 5; x2++) {
            if (parque[piso][fila][lugar].matricula[x2] < 48 ||
                    parque[piso][fila][lugar].matricula[x2] > 57) {
                c++;
            }
        }

        for (x3 = 6; x3 < 8; x3++) {
            if (parque[piso][fila][lugar].matricula[x3] < 65 ||
                    parque[piso][fila][lugar].matricula[x3] > 90) {
                c++;
            }
        }

        if (parque[piso][fila][lugar].matricula[2] != 45 ||
                parque[piso][fila][lugar].matricula[5] != 45) {
            c++;
        }

        if (c == 0) {
            //estaciona o carro
            parque[piso][fila][lugar].estado = 1;
            
            //armazena a data e horas em que o carro foi estacionado
            parque[piso][fila][lugar].DataInicial.ano = (ptr->tm_year + 1900);
            parque[piso][fila][lugar].DataInicial.dia = ptr->tm_mday;
            parque[piso][fila][lugar].DataInicial.mes = (ptr->tm_mon + 1);
            parque[piso][fila][lugar].DataInicial.hora = ptr->tm_hour;
            parque[piso][fila][lugar].DataInicial.min = ptr->tm_min;
            printf("Carro introduzido com sucesso.");
        } else {
            printf("Matrícula Inválida. Carro não introduzido.");
        }
    }
    
    //escreve em ficheiros
    writeParque(parque);

};

/**
 * Função para remover o carro do lugar, basta introduzir o piso, fila e lugar 
 * do carro que pretende remover 
 * Se o lugar estiver vazio ele avisa que esta livre, senão têm que introduzir 
 * o custo a pagar para sair do parque.
 * @param parque Parque de estacionamento
 */
void removerCarro(Carro parque[][FILAS][LUGARES]) {

    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);

    int i, piso, fila, lugar;

    int custo = 0, valor = 0, resultado = 0;

    readInt(&piso, 0, PISOS - 1, "Introduza o piso : ");

    readInt(&fila, 0, FILAS - 1, "Introduza a fila : ");

    readInt(&lugar, 0, LUGARES - 1, "Introduza o lugar : ");

    if (parque[piso][fila][lugar].estado == 0) {
        printf("\nO lugar ja se encontra vazio!!!\n ");
    } else {

        //o lugar fica livre
        parque[piso][fila][lugar].estado = 0;

        //armazena a data e as horas em que o carro é retirado
        parque[piso][fila][lugar].DataFinal.ano = (ptr->tm_year + 1900);
        parque[piso][fila][lugar].DataFinal.dia = ptr->tm_mday;
        parque[piso][fila][lugar].DataFinal.mes = (ptr->tm_mon + 1);
        parque[piso][fila][lugar].DataFinal.hora = ptr->tm_hour;
        parque[piso][fila][lugar].DataFinal.min = ptr->tm_min;

        //calcula o valor a pagar 
        custo = calcularCusto(parque, piso, fila, lugar);

        printf("\nTotal a pagar: %d\n", custo);

        do {
            readInt(&valor, 0, MAXFLOAT, "Introduza a quantia :");
            resultado = custo - valor;
            custo = resultado;
            if (resultado == 0) {

                printf("\n********************************\n");
                printf("Carro removido com sucesso!!!");
                printf("\n********************************\n");
            } else if (resultado < 0) {


                printf("\n********************************\n");
                printf("O troco é : %d\n", abs(resultado));
                printf("Carro removido com sucesso!!!");
                printf("\n********************************\n");
                resultado = 0;

            } else {

                printf("Restante : %d", resultado);

            }

        } while (resultado != 0 || resultado > 0);

    }

}

/**
 * Funçao menu principal do programa.
 * No quanto superior do programa vamos ter o numero de lugares vazios no parque.
 * Também vamos ter varios opções que são :
 * Opção 1 : Imprimir o tamanho do parque.
 * Opção 2 : Imprimir carro, que vai chamar a função imprimirLugares(parque).
 * Opção 3 : Inserir carro, que vai chamar a função estacionar(parque).
 * Opção 4 : Imprimir lugares ocupado, que vai chamar a função imprimirOcupados(parque).
 * Opção 5 : Imprimir lugares livre, que vai chamar a função imprimirLivres(parque).
 * Opção 6 : Remover o lugar, que vai chamar a função removerCarro(parque).
 * Opção 7 : Verificar o lugar e imprimar a marca e matricula, que vai chamar a 
 *           função estadoLugar(parque).
 * Opção 8 : Procura o carro por a matricula, que vai chamar a função 
 *           procurarCarro(parque).
 * Opção 9 : Estaciona o carro automaticamente, que vai chamar a função e
 *           stacionarAutomaticamente(parque).
 * Opção 10 : Desenha o parque, que vai chamar a função desenhar(parque).
 * Opção 0 : Sair para o menu inicial.
 * @param parque Parque de estacionamento
 */
void administrarParque(Carro parque[][FILAS][LUGARES]) {

    int x = PISOS;
    int y = FILAS;
    int z = LUGARES;
    int i = 0, j;
    do {
        j = 0;
        for (int u = 0; u < PISOS; u++) {
            for (int o = 0; o < FILAS; o++) {
                for (int m = 0; m < LUGARES; m++) {
                    if (parque[u][o][m].estado == 0) {
                        j++;
                    }

                }
            }
        }

        printf("\n******************************\n");
        if (j != 0) {
            printf("\n            LIVRE\n\nO parque tem %d lugares vazios \n\n\n", j);

        } else {
            printf("\n******************************\n");
            printf("\n            CHEIO\n\nO Parque esta cheio!!!");
            printf("\n******************************\n");
        }
        printf("\n1-Imprimir tamanho do parque\n");
        printf("\n2-Imprimir lugares\n");
        printf("\n3-Inserir carro\n");
        printf("\n4-Imprimir ocupados\n");
        printf("\n5-Imprimir livres\n");
        printf("\n6-Remover do lugar\n");
        printf("\n7-Pesquisar do lugar\n");
        printf("\n8-Pesquisar carro\n");
        printf("\n9-Estacionar automaticamente\n");
        printf("\n10-Imprimir lugares(Desenho)\n");
        printf("\n0-Sair\n");
        printf("\n******************************\n");
        printf("Introduza a opção que deseja:\n ");
        readInt(&i, 0, 10, "--> ");

        writeParque(parque);

        switch (i) {
            case 1:
                printf("\n********************************\n");
                printf("Tamanho do parque:\n ");
                printf("Pisos: %d\n ", x);
                printf("Filas em cada Piso: %d\n ", y);
                printf("Lugares em cada fila: %d\n ", z);
                printf("\n********************************\n");
                break;

            case 2:
                imprimirLugares(parque);
                break;

            case 3:
                estacionar(parque);
                break;

            case 4:
                imprimirOcupados(parque);
                break;

            case 5:
                imprimirLivres(parque);
                break;

            case 6:
                removerCarro(parque);
                break;
            case 7:

                estadoLugar(parque);
                break;


            case 8:
                procurarCarro(parque);
                break;

            case 9:
                estacionarAutomaticamente(parque);
                break;

            case 10:
                desenhar(parque);
                break;
        }
    } while (i != 0);

    menuInicial(parque);
}

/**
 * Funçao que contem o menu principal do programa.
 * Opção 1: Vai se dirigir para a função administrarParque(parque).
 * Opção 2: Imprime as regras do programa, usando a função informacoes().
 * @param parque Parque de estacionamento
 */
void menuInicial(Carro parque[][FILAS][LUGARES]) {

    int a;
    printf(" ____ \n");
    printf("|  _ \\ __ _ _ __ __ _ _   _  ___\n");
    printf("| |_) / _` | '__/ _` | | | |/ _ \\ \n");
    printf("|  __/ (_| | | | (_| | |_| |  __/ \n");
    printf("|_|   \\__,_|_|  \\__, |\\__,_|\\___|\n");
    printf("                   |_|           \n");
    printf("\n**************Menu**************\n\n");
    printf("Escolha uma das opçoes:\n\n");
    printf("1-Administraçao parque\n\n");
    printf("2-Informaçoes\n\n ");
    printf("0-sair\n\n");
    printf("********************************\n");

    do {
        readInt(&a, 0, 2, "--> ");
        switch (a) {

            case 1:
                administrarParque(parque);
                break;
            case 2:
                informacoes(parque);
                break;

            default:
                return 0;
        }
    } while (a != 0);
}