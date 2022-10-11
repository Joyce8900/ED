#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>




void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
  
  
  int pivot = array[high];
  
 
  int i = (low - 1);

  
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      
      i++;
      
      
      swap(&array[i], &array[j]);
    }
  }

  
  swap(&array[i + 1], &array[high]);
  

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    
    int pi = partition(array, low, high);
    
  
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


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
            quickSort(v, 0, i-1);
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