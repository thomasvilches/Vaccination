#include<math.h>
#include<stdio.h>
#include<stdlib.h>

main(){

  int i;

  FILE *ar;

  ar=fopen("uni.dat","w");


  for(i=0;i<1000000;i++) fprintf(ar,"%f\n",(float)rand()/RAND_MAX);

}
