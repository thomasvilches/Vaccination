void setup_pregnant(struct Human *H,int NumberInAge[7],int **PregAgeGroup,float distPreg[7]){


  int i,group,rn,j,total,number_pregnant;
  float rd;

  for(i=0;i<7;i++) NumberInAge[i]=0;//setting 0
  total=0;

  for(i=0;i<N;i++){
    if(H[i].gender==2){
        if(H[i].age>=15){
          group=(H[i].age-15)/5;
          //printf("%d %d",H[i].age,group);
          //getchar();
            if(group<7){
                H[i].pregnantSus=1;
                PregAgeGroup[group][NumberInAge[group]]=i;//Who is each age groupand is not pregnant
                H[i].PregnantAgeGroup=group;
                NumberInAge[group]++;//counting the number of women in group age
                total++;
            }
        }
    }
  }//close for

//CASE 1
    number_pregnant=total*0.045;

//printf("total=%d\n",number_pregnant);
//getchar();
  // printf("total=%d\n",total);
  //getchar();

  //splitting the number of pregnant women according to the distPreg
  //if(total>number_pregnant){ //////////no caso
    i=0;
    while(i<number_pregnant){

      rd=(float)rand()/(RAND_MAX+1.);
      for(group=0;group<7;group++)
	if(rd<distPreg[group]) break;
      // printf("group=%d %d\n",group,NumberInAge[group]);
      if(NumberInAge[group]>0){

	rn=NumberInAge[group]*(rand()/(RAND_MAX+1.));

	//printf("r=%d %d\n",rd,PregAgeGroup[group][rn]);
	//	getchar();
    TotalNumberofPreg++;
	H[PregAgeGroup[group][rn]].pregnant=1;
	H[PregAgeGroup[group][rn]].timepregnant=Time_Preg_Max*((float)rand()/RAND_MAX);//starting a random time

	//excluding this woman of the group

	for(j=rn;j<NumberInAge[group]-1;j++)
	  PregAgeGroup[group][j]=PregAgeGroup[group][j+1];
	NumberInAge[group]--;

	i++;

      }//close if NUMBER
    }//close while
 // }//close if
/*   else{
 *
 *     for(group=0;group<7;group++){
 *       for(i=0;i<NumberInAge[group];i++){
 * 	H[PregAgeGroup[group][rn]].pregnant=1;
 * 	H[PregAgeGroup[group][rn]].timepregnant=Time_Preg_Max*((float)rand()/RAND_MAX);//starting a random time
 *       }//close for i
 *       NumberInAge[group]=0;
 *     }//close for
 *   }//close else
 */
  //printf("%d %d %d %d\n",H[15].pregnant,H[15].PregnantAgeGroup,H[15].timepregnant,H[15].age);
  //getchar();
}


void ProbMicrocephaly(struct Human *H,int i){

  float rd,rn;
  if(H[i].pregnant==1){
  //printf("aaaa %d\n",H[i].timepregnant);
    if(H[i].timepregnant<=90){
        //NumPregInf[0]++;
        rd=(float)rand()/(RAND_MAX+1.);

        rn=rd*(Prob_Microcephaly_1_max-Prob_Microcephaly_1_min)+Prob_Microcephaly_1_min;
     // printf("%f ",rn);
        rd=(float)rand()/(RAND_MAX+1.);
        if(rd<rn) H[i].microcephaly=1;

        H[i].InfTrim=1;

    }
    else{
        if(H[i].timepregnant<=180){

            //NumPregInf[1]++;
            rd=(float)rand()/(RAND_MAX+1.);

            rn=rd*(Prob_Microcephaly_2_max-Prob_Microcephaly_2_min)+Prob_Microcephaly_2_min;
          //printf("%f ",rn);
            rd=(float)rand()/(RAND_MAX+1.);
            if(rd<rn) H[i].microcephaly=1;

            H[i].InfTrim=2;

        }
        else{
            //NumPregInf[2]++;
            H[i].InfTrim=3;
//printf("i=%d\n",i);
//printf("%d %d %d %d %d\n",H[i].health,H[i].Vaccination,H[i].pregnant,H[i].timepregnant,H[i].timevaccination);
    //getchar();
        }
    }
  }
}

int update_pregnant(struct Human *H,int NumberInAge[7],int **PregAgeGroup,int VacVector[4],int PregBaby[4]){

    int i,number_of_borns,rd,aux;
    float rn,ran;
    number_of_borns=0;
    //FILE *arpreg;

    //arpreg=fopen("statepreg.dat","a");

    for(i=0;i<7;i++) NumberInAge[i]=0;

    for(i=0;i<N;i++){
        if(H[i].pregnantSus==1){
        if(H[i].pregnant!=1){
                if(H[i].health<4){
                    PregAgeGroup[H[i].PregnantAgeGroup][NumberInAge[H[i].PregnantAgeGroup]]=i;
                    NumberInAge[H[i].PregnantAgeGroup]++;
                }//close for health
                else{
                    if(H[i].health>5){
                        PregAgeGroup[H[i].PregnantAgeGroup][NumberInAge[H[i].PregnantAgeGroup]]=i;
                        NumberInAge[H[i].PregnantAgeGroup]++;
                    }
                }
            }
        }//close if gender
    }//close for i

  for(i=0;i<N;i++){
        if(H[i].pregnant==1){
            if(H[i].timepregnant>Time_Preg_Max){
                if(H[i].microcephaly==1){
                    number_of_borns++;
                    //fprintf(arpreg,"%d\n",H[i].Vaccination);
                    PregBaby[H[i].InfTrim-1]++;
                    //printf("test %d %d %d\n",i,H[i].timepregnant,H[i].pregnant);
                }
                PregBaby[3]++;
                H[i].pregnant=-1;
                H[i].microcephaly=-1;
                H[i].timepregnant=0;
                if(NumberInAge[H[i].PregnantAgeGroup]>0){

                      //printf("aaa %d %d %d %d %d\n",H[i].PregnantAgeGroup,H[i].timepregnant,H[i].pregnant,H[i].gender,i,H[i].age);
                    rd=NumberInAge[H[i].PregnantAgeGroup]*(rand()/(RAND_MAX+1.));

                    aux=PregAgeGroup[H[i].PregnantAgeGroup][rd];

                    PregAgeGroup[H[i].PregnantAgeGroup][rd]=i;
                    TotalNumberofPreg++;
                    H[aux].pregnant=1;
                    H[aux].timepregnant=0;

                    if(H[aux].health==1){/////same question: are latent and assymp people suitable to vaccination???
                        if(H[aux].Vaccination==0){
                            if(H[aux].age>=Min_age_vac_preg){
                                if(H[aux].age<=Max_age_vac_preg){
                                    rn=(float)rand()/RAND_MAX;

                                    if(rn<=Vac_Cover_Preg){
                                            H[aux].Vaccination=2;
                                           // H[aux].health=6;
                                            H[aux].timevaccination=0;
                                        VacVector[1]++;
                                    }//close if
                                }
                            }
                        }
                    }//close if health
                    else{
                        if(H[i].health<4){
                            if(H[aux].Vaccination==0){
                                if(H[aux].age>=Min_age_vac_preg){
                                    if(H[aux].age<=Max_age_vac_preg){
                                        rn=(float)rand()/RAND_MAX;

                                        if(rn<=Vac_Cover_Preg){

                                            H[aux].Vaccination=2;
                                           // H[aux].health=6;
                                            H[aux].timevaccination=0;

                                            VacVector[1]++;
                                        }//close if
                                    }
                                }
                            }

                        }

                            else{
                                if(H[aux].health==6){
                                    if(H[aux].Vaccination==0){
                                            if(H[aux].recoveredfrom==3){
                                                if(H[aux].age>=Min_age_vac_preg){
                                                    if(H[aux].age<=Max_age_vac_preg){
                                                        rn=(float)rand()/RAND_MAX;

                                                        if(rn<=Vac_Cover_Preg){

                                                                H[aux].Vaccination=2;
                                                                H[aux].timevaccination=0;

                                                            VacVector[1]++;
                                                        }//close if
                                                    }//close if age
                                                }//close if age

                                        }//close recover from
                                    }
                                }//close health
                            }//close else
                    }

                }//close if number
              else{
                H[i].pregnant=1;
                TotalNumberofPreg++;
                if(H[i].health==1){/////same question: are latent and assymp people suitable to vaccination???
                    if(H[i].Vaccination==0){
                            if(H[i].age>=Min_age_vac_preg){
                                if(H[i].age<=Max_age_vac_preg){
                                    rn=(float)rand()/RAND_MAX;

                                    if(rn<=Vac_Cover_Preg){

                                            H[i].Vaccination=2;
                                            //H[i].health=6;
                                            H[i].timevaccination=0;

                                        VacVector[1]++;
                                    }//close if
                                }
                            }
                        }
                    }//close if health
                    else{
                        if(H[i].health==6){
                            if(H[i].Vaccination==0){
                                if(H[i].recoveredfrom==3){

                                    if(H[i].age>=Min_age_vac_preg){
                                        if(H[i].age<=Max_age_vac_preg){
                                            rn=(float)rand()/RAND_MAX;

                                            if(rn<=Vac_Cover_Preg){

                                                    H[i].Vaccination=2;
                                                    H[i].timevaccination=0;

                                                VacVector[1]++;
                                            }//close if
                                        }//close if age
                                    }//close if age

                                }//close recover from
                             }
                           }//close health
                        else{

                                    if(H[i].health<4){

                                            if(H[i].Vaccination==0){
                                                if(H[i].age>=Min_age_vac_preg){
                                                    if(H[i].age<=Max_age_vac_preg){
                                                        rn=(float)rand()/RAND_MAX;

                                                        if(rn<=Vac_Cover_Preg){

                                                                H[i].Vaccination=2;
                                                                H[i].timevaccination=0;

                                                            VacVector[1]++;
                                                        }//close if
                                                    }
                                                }
                                            }

                                    }
                        }
                    }//close else





              }//close else

            }//close time
            }
          }//close for i
//fclose(arpreg);
  return(number_of_borns);
}


int CountingLast(struct Human *H,int PregBaby[3]){

  int i,number;
  float rd;
 // FILE *arpreg;

   // arpreg=fopen("statepreg.dat","a");

  number=0;
  for(i=0;i<N;i++){
    if(H[i].pregnant==1){
      if(H[i].microcephaly==1){
      number++;
       // fprintf(arpreg,"%d\n",H[i].Vaccination);
        PregBaby[H[i].InfTrim-1]++;
      }

    }//close if pregnant
  }//close for

  //fclose(arpreg);
  return(number);

}
