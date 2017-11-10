#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define cores 25
#define sim 2000


main(){

  FILE *arq;
  char name[40];
  int num1,num2,baby,num3,num4,num5,num6,num7,num8,i,babys,j;

  printf("ok");
  babys=0;
  for(i=0;i<cores;i++){

    sprintf(name,"server/test3/NoM%d.dat",i);

    arq=fopen(name,"r");


    for(j=0;j<sim/cores;j++){

      fscanf(arq,"%d %d %d %d %d %d %d %d %d",&baby,&num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8);
      printf("%d\n",baby);
      babys+=baby;

    }

    fclose(arq);

  }
  printf("sum= %d %f\n",babys,(float)babys/sim);

}
