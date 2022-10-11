#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

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

void main(){
    int i, n, *v, *aux;
    struct timeval b, c;
    long long unsigned int ub, ua;
	
    for (n = 0; n <= 1000; n = n + 1){
        v = (int *) malloc(n * sizeof(int));
     	aux = (int *) malloc(n * sizeof(int));
        for (i = 0; i < n; i++){
            v[i] = i;
		}
        gettimeofday(&b, NULL);
        merge_sort(v, 0, n-1, aux);
        gettimeofday(&c, NULL);

        free(v);

        ub = 1000000 * b.tv_sec + b.tv_usec;
        ua = 1000000 * c.tv_sec + c.tv_usec;
        /**
        printf("%ld %ld\n", b.tv_sec, b.tv_usec);
        printf("%ld %ld\n", a.tv_sec, a.tv_usec);

        printf("%lld - %lld = %lld\n", ua, ub, ua - ub);
        **/
 
        printf("%d \t %lld\n", n, ua - ub);


    }
}


