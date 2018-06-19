#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void makeDeret(int *arr,int start, int stop){

    int i=0;
    while (start<stop){
        arr[i]=rand()%stop;
        start++;
        i++;
    }
//    printf("%d\n",i);
}

bool is_sorted(int *a, int n)
{
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}

void shuffle(int *a, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }
}

void printArr(int *arr,int n){
    if(n==0){

    }
    else{
        printArr(arr,n-1);
        printf("%d ",*(arr+(n-1)));
    }
}


void bogosort(int *a, int n)
{
  while ( !is_sorted(a, n) ) {
        shuffle(a, n);
        puts("");
        printArr(a,n);
        puts("");
  }

}
int main()
{
  int *numbers = malloc(100);
  int i;
  makeDeret(&numbers,0,9);
  bogosort(&numbers, 9);
  printArr(&numbers,9);
  printf("\n");
}
