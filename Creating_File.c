#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define Num 2000
#define lines 728

float **Alocar_matriz_inteira(int m,int n);
main(){

  int i,j,t;
  float **Symp,a1,a2,a3,a4,a5,a6,**Asymp;
  FILE *ar,*arq,*Asym;
  char name[30];

  Symp=Alocar_matriz_inteira(lines,Num);
  Asymp=Alocar_matriz_inteira(lines,Num);
  arq=fopen("symp6.dat","w");
  Asym=fopen("asymp6.dat","w");
  for(i=0;i<Num;i++){
    sprintf(name,"server/test6/tt%d.dat",i);

    ar=fopen(name,"r");

    for(j=0;j<lines;j++){
      fscanf(ar,"%d %f %f %f %f",&t,&a1,&a2,&a3,&a4);
      Symp[j][i]=a3;
      Asymp[j][i]=a2;
      //printf("%f\n",Symp[j][i]);
      //getchar();
    }

    fclose(ar);
  }
  //printf("ok\n");
  for(j=0;j<lines;j++){
    //fprintf(arq,"%d ",j);
    for(i=0;i<Num;i++){
      fprintf(arq,"%f ",Symp[j][i]);
      fprintf(Asym,"%f ",Asymp[j][i]);
    }
    fprintf(arq,"\n");
    fprintf(Asym,"\n");
  }

}


float **Alocar_matriz_inteira(int m,int n) {
  float **v;
  /* ponteiro para a matriz */
  int i;

  /* aloca as linhas da matriz */
  v = (float**) calloc (m,sizeof(float*));
  if (v == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    return (NULL);
  }
/* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
    v[i] = (float*) calloc (n, sizeof(float));
    if (v[i] == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      return
	(NULL);
    }
  }
  return
    (v);
  /* retorna o ponteiro para a matriz */
}
