#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>



void insertion_sort (int v[], int n){
    int fim;
    int i = 0 ;
    int j = 0;
    if (n<=1){
        return ;
    }
    insertion_sort(v, n-1);
    fim = v[n-1];
    i= n-2;
    while (j>=0 && v[j] > fim){
        v[j+1]= v[j];
        j= j-1;

    }
    v [j + 1] = fim;

}
//Médio Caso
/*
int main()
{
    int i, n, *v;
    struct timeval b, a;
    long long unsigned int t, ub, ua;

    srand(time(NULL));

    for (n = 10; n <= 10000; n = n + 10)
    {
        v = (int *) malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
            v[i] = rand() % 1000 + 1;

	t = 0;
	for (i = 0; i < 10; i++)
	{
                        
         
            gettimeofday(&b, NULL);
            insertion_sort(v, n);
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
*/

//Pior caso
int main()
{
    int i, n, *v;
    struct timeval b, a;
    long long unsigned int t, ub, ua;

    srand(time(NULL));

    for (n = 0; n <= 10000; n = n + 10)
    {
        v = (int *) malloc(n * sizeof(int));

        for (i = n-1; i >=0; i--)
            v[i] = i;

	t = 0;
	for (i = 0; i < 10; i++)
	{
            
            
         
            gettimeofday(&b, NULL);
            insertion_sort(v, n);
            gettimeofday(&a, NULL);
         
            ub = 1000000 * b.tv_sec + b.tv_usec;
            ua = 1000000 * a.tv_sec + a.tv_usec;

	    t = t + (ua - ub);
	}
         
        free(v);
         
        printf("%d \t%lf\n", n, t / 1000.0);
    }
    
    return 0;
}

/*
Melhor Caso
int main()
{
    int i, n, *v;
    struct timeval b, a;
    long long unsigned int t, ub, ua;

    srand(time(NULL));

    for (n = 10; n <= 100000; n = n + 100)
    {
        v = (int *) malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
            v[i] = i;

	t = 0;
	for (i = 0; i < 10; i++)
	{
           
            
         
            gettimeofday(&b, NULL);
            insertion_sort(v, n);
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
*/