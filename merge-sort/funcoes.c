#include <time.h>
#include <stdlib.h>

#include "funcoes.h"

void trocar(int *n1, int *n2){
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
}

void preencher_aleatorio(int *v, int n){
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        v[i] = rand() % 100 + 1;
    }
}

void preencher_decrescente(int *v, int n){
    for(int i = n - 1; i >= 0; i--){
        v[(n - 1) - i] = i;
    }
}

void preencher_crescente(int *v, int n){
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
}