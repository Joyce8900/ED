#include <stdio.h>

int fatorialR (int n){
  int res;
  if (n ==0)
  {
    return 1;
  }
  res = n*fatorialR(n-1);
  printf("%d %d\n", n, res);
  return res;
}
int fatorialI(int n){
  int a=1;
  int t =0;
  for (int i=0; i<(n-1);i=i+1){
    a=a*(n-i);
    t=t+1;
    printf("%d %d \n", t, a);
  }
  return a;
}



int main(void) {
  printf("R:%d\n",fatorialR(13));
  printf("I:%d\n",fatorialI(10));
  return 0;
}
