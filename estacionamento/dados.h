/* 
 * File:   login.h
 * Author: Pedro Luís
 *
 * Created on 9 de Dezembro de 2015, 18:01
 */

#ifndef LOGIN_H
#define	LOGIN_H
#define TAM_USERNAME 30+1
#define TAM_PASSWORD 30+1
#define NUM_USERS 15
#define MAX_ALERT 10


#ifdef	__cplusplus
extern "C" {
#endif


#include <string.h>


    typedef struct dados{
        unsigned short nUsers;
        char username[TAM_USERNAME];
        char pass[TAM_PASSWORD];      
    }Carro;





#ifdef	__cplusplus
}
#endif


#endif	/* LOGIN_H */

