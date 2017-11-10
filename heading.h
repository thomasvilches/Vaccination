#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"ConstantParameters.h"

struct Human{
  int health;  //1-susc, 2-lat, 3- Asymp, 4- Symp, 5- SympIso, 6- Rec, 7- Dead.... -1 undef
  int latentfrom; //1- bite, 2 - sexual
  int age; //years
  int agegroup;// 0-16
  int gender;//1- Male, 2- Female
  int statetime;
  int timeinstate;//time in each state;
  int swap;//0- no swap, 1..7
  int partner; //index to the partner in the lattice
  int sexfrequency;
  int cumulativesex;
  int cumulativedays;
  int recoveredfrom;
  float sexprobability;
  int pregnant;
  int PregnantAgeGroup;
  int timepregnant;
  int microcephaly;
  int pregnantSus;
  int Vaccination;
  int timevaccination;
  int agedays;
  int InfTrim;
  float VacEff
};

struct Mosquito{

  int health;  //1-susc, 2-lat, 3-infec
  int infectionfrom; ///----
  int age;//days
  int ageofdeath;//
  int statetime;
  int timeinstate;//time in each state;
  int numberofbites;
  int bitesdistribuition[60];
  int swap;

};

void set_up_humans(struct Human *H);
void sexual_tree(struct Human *H);
int ParametersAge(float x,int *Age1,int *Age2);
int ParameterSex(int age,int gender,float dist_men[7][6],float dist_women[7][6]);
void setup_pregnant(struct Human *H,int NumberInAge[7],int **PregAgeGroup,float distPreg[7]);
void vaccination(struct Human *H,int VacVector[4]);
void increase_timestateH(struct Human *H,int VacVector[4]);
void update_human(struct Human *H,int UpDating[6],int NumPregInf[4],int VacVector[4]);
int update_pregnant(struct Human *H,int NumberInAge[7],int **PregAgeGroup,int NumPregInf[4],int VacVector[4],int PregBaby[4]);


void set_up_mosquito(struct Mosquito *M,int i,float dist[2][60]);
int lifespan(float dist[2][60]);
void BiteDistribuition(struct Mosquito *M,int i);
void increase_timestateM(struct Mosquito *M);
void increase_mosquito_age(struct Mosquito *M,float dist[2][60]);
void update_mosquito(struct Mosquito *M);


void BiteTransmission(struct Human *H,struct Mosquito *M);
void Sexual_interaction(struct Human *H);
void ProbMicrocephaly(struct Human *H,int i,int NumPregInf[4]);
int CountingLast(struct Human *H,int PregBaby[4]);


int deleteMember(int *A,int del,int num);
int **Alocar_matriz_inteira(int m,int n);
int *ivector(long nl, long nh);
void nrerror(char error_text[]);
int max(int a,int b);
int min(int a,int b);
int season,TotalNumberofPreg;//summer= 0 winter = 1


////////////////////////////////////////
float Poisson(float xm);
float gammln(float xx);
