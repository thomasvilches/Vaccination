#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NumberOfFiles 40
#define NL 728 //numberoflines
#include"graficos.c"
void grafico(int j);
main(){

  char name[30],name2[30];
  FILE *ar;
  int i,time,line,j;
  float susc[NL],lat[NL],asym[NL],sym[NL],symiso[NL],rec[NL],a1,a2,a3,a4,a5,a6;
  
  for(line=0;line<NL;line++) susc[line]=lat[line]=asym[line]=sym[line]=symiso[line]=rec[line]=0;

  printf("what is the number of the folder\n",j);
  scanf("%d",&j);
  for(i=0;i<NumberOfFiles;i++){
    sprintf(name,"files%d/test%d.dat",j,i);
    ar=fopen(name,"r");

    for(line=0;line<NL;line++){

      fscanf(ar,"%d %f %f %f %f %f %f",&time,&a1,&a2,&a3,&a4,&a5,&a6);

      susc[line]+=a1;
      lat[line]+=a2;
      asym[line]+=a3;
      sym[line]+=a4;
      symiso[line]+=a5;
      rec[line]+=a6;
      

    }

    fclose(ar);
  }

  sprintf(name2,"files%d/result.dat",j);
  ar=fopen(name2,"w");
  for(line=0;line<NL;line++){

    susc[line]/=NumberOfFiles;
    lat[line]/=NumberOfFiles;
    asym[line]/=NumberOfFiles;
    sym[line]/=NumberOfFiles;
    symiso[line]/=NumberOfFiles;
    rec[line]/=NumberOfFiles;

    fprintf(ar,"%d %f %f %f %f %f\n",line,susc[line],lat[line],asym[line],sym[line]+symiso[line],rec[line]);

    
    
  }
  grafico(j);
  
}
