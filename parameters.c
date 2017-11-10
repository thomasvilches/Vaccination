int ParametersAge(float x,int *Age1,int *Age2){

  float ProbBirthAge[17],soma;
  int AgeMin[17],AgeMax[17],i,agegroup;
  
  AgeMin[0] = 1;
  AgeMax[0] = 4;
  
  AgeMin[1] = 5;
  AgeMax[1] = 9;
  
  AgeMin[2] = 10;
  AgeMax[2] = 14;
  
  AgeMin[3] = 15;
  AgeMax[3] = 19;
  
  AgeMin[4] = 20;
  AgeMax[4] = 24;
  
  AgeMin[5] = 25;
  AgeMax[5] = 29;
  
  AgeMin[6] = 30;
  AgeMax[6] = 34;
 
  AgeMin[7] = 35;
  AgeMax[7] = 39;
  
  AgeMin[8] = 40;
  AgeMax[8] = 44;
  
  AgeMin[9] = 45;
  AgeMax[9] = 49;
  
  AgeMin[10] = 50;
  AgeMax[10] = 54;
  
  AgeMin[11] = 55;
  AgeMax[11] = 59;
  
  AgeMin[12] = 60;
  AgeMax[12] = 64;
  
  AgeMin[13] = 65;
  AgeMax[13] = 69;
 
  AgeMin[14] = 70;
  AgeMax[14] = 74;
  
  AgeMin[15] = 75;
  AgeMax[15] = 79;
  
  AgeMin[16] = 80;
  AgeMax[16] = 100;
    
  ProbBirthAge[0] = 0.091248422;
  ProbBirthAge[1] = 0.090502874;
  ProbBirthAge[2] = 0.091847835;
  ProbBirthAge[3] = 0.093120832;
  ProbBirthAge[4] = 0.089609792;
  ProbBirthAge[5] = 0.08103463;
  ProbBirthAge[6] = 0.072690616;
  ProbBirthAge[7] = 0.065216532;
  ProbBirthAge[8] = 0.061130039;
  ProbBirthAge[9] = 0.060741253;
  ProbBirthAge[10] = 0.053966855;
  ProbBirthAge[11] = 0.043527878;
  ProbBirthAge[12] = 0.033841535;
  ProbBirthAge[13] = 0.025345255;
  ProbBirthAge[14] = 0.018361588;
  ProbBirthAge[15] = 0.014017567;
  ProbBirthAge[16] = 0.013796498;
  
  soma=0;
  for(i=0;i<17;i++){
    soma+=ProbBirthAge[i];
    if(soma>x) break;
    
  }
  //printf("%f\n",soma);
  agegroup=i;

  *Age1=AgeMin[i];
  *Age2=AgeMax[i];
  return(agegroup);
}


int ParameterSex(int age,int gender,float dist_men[7][6],float dist_women[7][6]){

  float random;

  int linha,i;

  if(age<=24) linha=0;
  else{
    if(age<=29) linha=1;
    else{
      if(age<=39) linha=2;
      else{
	if(age<=49) linha=3;
	else{
	  if(age<=59) linha=4;
	  else{
	    if(age<=69) linha=5;
	    else linha=6;
	  }
	}
      }
    }
  }
  //Columns 0,1,2,3,4,5

  random=(float)rand()/(RAND_MAX);
  if(gender==1)
    for(i=0;i<6;i++){
      if(dist_men[linha][i]>random) break;
    }

  else
    for(i=0;i<6;i++){
      if(dist_women[linha][i]>random) break;
    }
  return(i);
}
