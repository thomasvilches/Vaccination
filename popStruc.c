void set_up_humans(struct Human H[N]){

  float x;

    float dist_men[7][6]= {{0.167, 0.334, 0.563, 0.792, 0.896, 1},    //15-24
			   {0.109,	0.572,	0.7575,	0.943,	0.9725,	1},//25-29
			   {0.201,	0.674,	0.808,	0.942,	0.971,	1},//30-39
			   {0.254,	0.764,	0.8635,	0.963,	0.9815,	1},//40-49
			   {0.456,	0.839,	0.914,	0.989,	0.9945,	1}, //50-59
			   {0.551, 0.905, 0.9525, 1, 1, 1},     //       60-69
			   {0.784, 0.934, 0.963, 0.992, 0.996, 1}} ;      //70+

  float dist_women[7][6] = { {0.265,0.412,	0.5885,	0.765,	0.8825,	1},
			     {0.151,0.628,	0.804,	0.98,	0.99,	1},
			     {0.228,0.73,	0.8395,	0.949,	0.9745,	1},
			     {0.298,0.764,	0.868,	0.972,	0.9855,	1},
			     {0.457,0.819,	0.9035,	0.988,	0.9935,	1},
			     {0.579,0.938,	0.969, 1, 1, 1},
			     {0.789,0.972,	0.979,	0.986,	0.993,	1}};


  int i,AgeMax,AgeMin,a;

  for(i=0;i<N;i++) {//H[i]={1,0,-1,-1,1,999,-1,-1,-1};
    H[i].health=1;
    H[i].latentfrom=0;
    H[i].age=-1;
    H[i].agegroup=-1;
    H[i].gender=1;
    H[i].statetime=999;
    H[i].timeinstate=-1;
    H[i].swap=-1;
    H[i].partner=-1;
    H[i].sexfrequency=-1;
    H[i].cumulativesex=-1;
    H[i].cumulativedays=-1;
    H[i].recoveredfrom=-1;
    H[i].pregnant=-1;
    H[i].pregnantSus=0;
    H[i].microcephaly=-1;
    H[i].Vaccination=0;
    H[i].timevaccination=-1;
    H[i].agedays=365*(rand()/(RAND_MAX+1.));
    H[i].PregnantAgeGroup=-1;
    H[i].InfTrim=-1;
    H[i].VacEff=(vac_eff_max-vac_eff_min)*((float)rand()/RAND_MAX)+vac_eff_min;
  }

  for(i=0;i<N;i++){
    //randomizing the age acording to the distribuition
     x=(float)rand()/(RAND_MAX+1.);
     H[i].agegroup=ParametersAge(x,&AgeMax,&AgeMin);//Age group
     H[i].age=(float)rand()/(RAND_MAX+1.)*(AgeMax-AgeMin)+AgeMin;//age
     //printf("idade %d %d\n",H[i].age,H[i].agegroup);
     //----------------------------------------------------------------////

     x=(float)rand()/(RAND_MAX+1.);
     if(x<0.5) H[i].gender=2;//gender

     /////////////////////////////////////////////////////////////////////////

     //number of sexual contacts
     if(H[i].age<15) H[i].sexfrequency=0;
     else{
       H[i].sexfrequency=ParameterSex(H[i].age,H[i].gender,dist_men,dist_women);
       //printf("aa %d %d\n",H[i].sexfrequency,H[i].age);
     }

   }//close for
}//main

void sexual_tree(struct Human *H){

  int i,numMale,numFemale,countGood,rd,del,j;
  int *Male=malloc(N*sizeof(int));
  int *Female=malloc(N*sizeof(int));
  int *goodOnes=malloc(N*sizeof(int));
  numMale=numFemale=0;
  for(i=0;i<N;i++){
    if(H[i].gender==1){
      if(H[i].age>=15) numMale++;
    }
    else if(H[i].age>=15) numFemale++;
  }

  // printf("num= M=%d F=%d\n",numMale,numFemale);

  //Male=ivector(0,numMale-1);
  //Female=ivector(0,numFemale-1);

  numMale=numFemale=0;
   for(i=0;i<N;i++){
    if(H[i].gender==1){
      if(H[i].age>=15){
	Male[numMale]=i;
	numMale++;
      }
    }//close if
    else{
      if(H[i].age>=15){
	Female[numFemale]=i;
	numFemale++;
      }
    }//close else
   }//close for
   //printf("ok\n");
   /*----------------------------------------------*/

// for(i=0;i<numFemale;i++){
//   printf("%d %d\n",Female[i],H[Female[i]].age);
   //   getchar();
//  }

   /*-----------------------------------------------*/

   if(numMale>numFemale){
     //printf("entrou 1\n");
     //getchar();


     for(i=0;i<numFemale;i++){
       countGood=0;
       for(j=0;j<numMale;j++){
	 if(H[Female[i]].age>=H[Male[j]].age-5){
	   if(H[Female[i]].age<=H[Male[j]].age+5){
	     goodOnes[countGood]=j;
	     countGood++;
	   }//close if +5
	 }//close if -5
       }//close for j

       if(countGood==0){
	 //rd=numMale*(rand()/(RAND_MAX+1.));
       }//close if countgood
       else{
	 rd=countGood*(rand()/(RAND_MAX+1.));
	 H[Female[i]].partner=Male[goodOnes[rd]];
	 H[Male[goodOnes[rd]]].partner=Female[i];

	 del=goodOnes[rd];//deleting the sorted index
	 numMale=deleteMember(Male,del,numMale);

       }//close else
     }//close for i



     for(i=0;i<numFemale;i++){

       if(H[Female[i]].partner<0){
	 //printf("nao encontrou fem=%d\n",Female[i]);
	 rd=numMale*(rand()/(RAND_MAX+1.));
	 H[Female[i]].partner=Male[rd];
	 H[Male[rd]].partner=Female[i];
	 del=rd;//deleting the sorted index
	 numMale=deleteMember(Male,del,numMale);
       }
       if(H[i].partner>=N){
	 printf("ERROR\n");
	 getchar();
       }
     }//close for

   }//close if male>female
   else{
     //printf("entrou 2\n");
// getchar();


     for(i=0;i<numMale;i++){
       countGood=0;
       for(j=0;j<numFemale;j++){
	 if(H[Male[i]].age>=H[Female[j]].age-5){
	   if(H[Male[i]].age<=H[Female[j]].age+5){
	     goodOnes[countGood]=j;
	     countGood++;
	   }//close if +5
	 }//close if -5
       }//close for j

       if(countGood==0){
	 //rd=numMale*(rand()/(RAND_MAX+1.));
       }//close if countgood
       else{
	 rd=countGood*(rand()/(RAND_MAX+1.));
	 H[Male[i]].partner=Female[goodOnes[rd]];
	 H[Female[goodOnes[rd]]].partner=Male[i];

	 del=goodOnes[rd];//deleting the sorted index
	 numFemale=deleteMember(Female,del,numFemale);
       }//close else
     }//close for i


     for(i=0;i<numMale;i++){
       if(H[Male[i]].partner<0){
	 // printf("nao encontrou masc=%d\n",Male[i]);
	 rd=numFemale*(rand()/(RAND_MAX+1.));
	 H[Male[i]].partner=Female[rd];
	 H[Female[rd]].partner=Male[i];
	 del=rd;//deleting the sorted index
	 numFemale=deleteMember(Female,del,numFemale);
       }
       if(H[i].partner>=N){
	 printf("ERROR\n");
	 getchar();
       }
     }//close for
   }//close else
   free(Female);
   free(Male);
   free(goodOnes);
   // printf("ok tree\n");
}
int *ivector(long nl, long nh)
/* allocate an int vector with subscript range v[nl..nh] */
{
  int *v;

  v=(int *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int)));
  if (!v) nrerror("allocation failure in ivector()");
  return v-nl+NR_END;
}

int deleteMember(int A[N],int del,int num){

  int i,var;
  var=num;
  for(i=del;i<num-1;i++) A[i]=A[i+1];

  var--;
  return(var);

}
