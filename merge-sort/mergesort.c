#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

void mergeSort(int *v, int s, int n)
{
    int i, j, k, metadeTamanho, *vetorTemp;
    if (s == n)
        return;
    metadeTamanho = (s + n) / 2;

    mergeSort(v, s, metadeTamanho);
    mergeSort(v, metadeTamanho + 1, n);

    i = s;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *)malloc(sizeof(int) * (n - s + 1));

    while (i < metadeTamanho + 1 || j < n + 1)
    {
        if (i == metadeTamanho + 1)
        {
            vetorTemp[k] = v[j];
            j++;
            k++;
        }
        else
        {
            if (j == n + 1)
            {
                vetorTemp[k] = v[i];
                i++;
                k++;
            }
            else
            {
                if (v[i] < v[j])
                {
                    vetorTemp[k] = v[i];
                    i++;
                    k++;
                }
                else
                {
                    vetorTemp[k] = v[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for (i = s; i <= n; i++)
    {
        v[i] = vetorTemp[i - s];
    }
    free(vetorTemp);
}

/*Medio Caso

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
            v[i] = rand() % 1000 + 1;

    t = 0;
    for (i = 0; i < 10; i++)
    {


            gettimeofday(&b, NULL);
            mergeSort(v, 0,i);
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


//Melhor Caso
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
            mergeSort(v, 0, i-1);
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
