#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "funcoes.h"
#include <sys/timeb.h>

void merge_sort(int *, int, int, int*);
void merge(int*, int, int, int, int*);

void merge(int v[], int s, int m, int e, int aux[]) {
    int i = s;
	int j = m +1;
   for(int k = 0; k< e-s+1; k++){
		if ((v[i] < v[j]) && (i <= m) || (j > e )) {
		    aux[k] = v[i];
			i = i + 1;
		    
		} else{
		    aux[k] = v[j];
			j = j + 1;
		    
		}
	}
}

void merge_sort(int v[], int s, int e, int aux[]) {
   

    if (s < e) {
		int m = floor((s + e) / 2);
        merge_sort(v, s, m, aux);
        merge_sort(v, m + 1, e, aux);
        merge(v, s, m, e, aux);

        for (int i = 0; i < e - s + 1; i++) {
            v[s + i] = aux[i];
        }
    }
}

int main(void){
    int *v, *aux, i, j;
    int media = 0, delta;
    struct timeb timer_start, timer_end;

    for(i = 1000; i <= 10000; i += 100){
        v = (int *) malloc(i * sizeof(int));
        aux = (int *) malloc(i * sizeof(int));
        
        if(v == NULL){
            printf("Erro de alocação de memoria.\n");
            return -1;
        }
        
        for(j = 0; j < 10; j++){
            preencher_aleatorio(v, i);

            ftime(&timer_start);
            merge_sort(v, 0, i - 1, aux);
            ftime(&timer_end);

            delta = (int) (1000.0 * (timer_end.time - timer_start.time) + (timer_end.millitm - timer_start.millitm));
            media = media + delta;
        }
        
        printf("%d \t %lf\n", i, media / (float) j);

        free(v);
    }
    
    return 0;
}