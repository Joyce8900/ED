#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>



void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int *) malloc( fim * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main()
{
    int i, n, *v;
    struct timeval b, a;
    long long unsigned int t, ub, ua;

    srand(time(NULL));

    for (n = 1; n <= 1000; n = n + 1)
    {
        v = (int *) malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
            v[i] = rand() % 1000 + 1;

	t = 0;
	for (i = 0; i < 10; i++)
	{
                        
         
            gettimeofday(&b, NULL);
            mergeSort(v,  0,  i);
            gettimeofday(&a, NULL);
         
            ub = 1000000 * b.tv_sec + b.tv_usec;
            ua = 1000000 * a.tv_sec + a.tv_usec;

	    t = t + (ua - ub);
	}
         
        free(v);
         
        printf("%d \t %lf\n", n, t / 1000.0);
    }
    
    return 0;
}
