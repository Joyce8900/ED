#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int search(int *v, unsigned int n, int k)
{
    int i;

    for (i = 0; i < n; i++)
    {
	if (v[i] == k)
            return i;
    }

    return -1;
}

int main()
{
    int i, n, *v, k;
    struct timeval b, a;
    long long unsigned int t, ub, ua;

    srand(time(NULL));

    for (n = 1000; n <= 100000; n = n + 1000)
    {
        v = (int *) malloc(n * sizeof(int));

        for (i = 0; i < n; i++)
            v[i] = i;

	t = 0;
	for (i = 0; i < 1000; i++)
	{
            //k = 0;
            //k = -1;
            k = rand() % n;
         
            gettimeofday(&b, NULL);
            search(v, n, k);
            gettimeofday(&a, NULL);
         
            ub = 1000000 * b.tv_sec + b.tv_usec;
            ua = 1000000 * a.tv_sec + a.tv_usec;

	    t = t + (ua - ub);
	}
         
        free(v);
         
        printf("%d %lf\n", n, t / 1000.0);
    }
    
    return 0;
}
