#include <stdio.h>
int c = 0;


int fibR (int n ) {
  c++;
    if (n<2)
        return n;
    
    return fibR (n-1)+ fibR (n-2);
    
}
unsigned long int fibI (int n ) {
    if (n<2)
        return n;
    
    int n1 = 1;
    int n2 = 0;
    unsigned long int v ;
  
    for (int i = 0;i<n;i=i+1){
        v = n1;
        n1 = n1+n2;
        n2=v;
        c=c+1;
        printf("%lu %d\n",v , c);
    }
    return v;
}

int main (void){
    int n;
    
    printf("Digite N:");
    scanf("%d",&n);
    //printf("Com Recursividade: %d\n",fibR(n));
    fibI(n);
}
