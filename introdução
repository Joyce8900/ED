#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int soma = 0;
    int i;
    int n = 10;
    int vetor[n];
//Vet é o vetor utilizado.
    srand(time(NULL));

    for(i = 0; i < n; i++){
        vetor[i] = rand() % 100 + 1;
        printf("Valor:%d\n",vetor[i]);
        /* rand ()% 100 + 1, pega o número aleatorio de random, e divide por 100+1 sem resto, na divisão. 
        Deixando o número aleatorio sempre menor que 100.
        for: i é declarado como int e recebe o valor de 0
        a parada dele é i<n ou seja, quando a soma de todos de cada elemento do vetor é menor que n, ou seja menor que 10.
        ele roda com o passo a passo de i= i + i 
        gerando valores aleatórios entre zero e 100
        e colocando no vetor. */
    }
//
    
    for (i = 0; i < n; i++)
        soma += vetor[i];
    /* somar os valores do vetor
    */
    printf("%d\n",soma);
    
    return 0;
}
