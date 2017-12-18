void increase_timestateH(struct Human *H,int VacVector[4]){

  int i;
  float rd,rn;

  for(i=0;i<N;i++){
    H[i].timeinstate++;
    H[i].agedays++;
    if(H[i].pregnant==1)
        H[i].timepregnant++;
/*-------------------------------VACCINATION OF NEW 9 YO HERE--------------------*/
    if(H[i].agedays==365){
        H[i].agedays=0;
        H[i].age++;
        if(H[i].age==Min_age_vac){
            if(H[i].health<4){/// are Latent people and assymp suitable to vaccination and the recovered from them???
                rn=(float)rand()/RAND_MAX;
                if(rn<=Vac_Cover_Norm){

                        H[i].Vaccination=1;
                        H[i].timevaccination=0;

                    VacVector[0]++;
                }
            }
            else{
                if(H[i].health==6){
                    if(H[i].recoveredfrom==3){

                        rn=(float)rand()/RAND_MAX;
                        if(rn<=Vac_Cover_Norm){

                                H[i].Vaccination=1;
                                H[i].timevaccination=0;

                            VacVector[0]++;
                        }

                    }
                }
            }
        }//close if age
    }//close if agedays
/*------------------------------------------- VACCINATION HERE---------------------------------*/
/*---------------------------------------------------------------------------------------------*/
    if(H[i].timeinstate>H[i].statetime){

      if(H[i].health==2){

      if(H[i].Vaccination>0) H[i].swap=3;
      else{
            rd=(float)rand()/RAND_MAX;
            rn=rd*(ProbLatentToASymptomaticMax-ProbLatentToASymptomaticMin)+ProbLatentToASymptomaticMin;
            rd=(float)rand()/RAND_MAX;
            if(rd<rn) H[i].swap=3;
            else{
              //lets check if it will be isolated
              rd=(float)rand()/RAND_MAX;
              if(rd<ProbIsolationSymptomatic) H[i].swap=5;
              else H[i].swap=4;
            }//close else

        }
      }//close if latent

      else{
        if(H[i].health==3){
          H[i].swap=6;
        }
        else{
          if(H[i].health==4) H[i].swap=6;
          else if(H[i].health==5) H[i].swap=6;
        }//close else if 3
      }//close else
//close else susc
    }//close if timein>statetime
  }//close for i

}

void increase_timestateM(struct Mosquito *M){

  int i;

  for(i=0;i<NM;i++){
    M[i].timeinstate++;
    if(M[i].timeinstate>M[i].statetime){
      if(M[i].health==2) M[i].swap=3;
    }//close if instate>statetime
  }//close for i

}


void update_human(struct Human *H,int UpDating[6],int NumPregInf[3],int VacVector[4]){

  int i,d;
  float rd;

  for(i=0;i<N;i++){

    if(H[i].swap==2){
      H[i].health=2;
      d=log_normal_sample(exp(h_lognormal_latent_scale),exp(h_lognormal_latent_shape),rand());
      H[i].statetime=max(4,min(d,h_latency_max));
      H[i].timeinstate=0;
      H[i].swap=-1;
      UpDating[0]++;

     // printf("error = %d",i);

      ProbMicrocephaly(H,i);
    }//close if swap 2
    else{

      if(H[i].swap==3){
        H[i].health=3;
        d=log_normal_sample(exp(h_lognormal_symptomatic_scale),exp(h_lognormal_symptomatic_shape),rand());
        H[i].statetime=max(3,min(d,h_symptomatic_max));
        H[i].cumulativedays=0;
        H[i].cumulativesex=0;
        rd=(float)rand()/RAND_MAX;

        H[i].sexprobability=rd*(sextransMax-sextransMin)+sextransMin;
        H[i].timeinstate=0;
        H[i].swap=-1;
        if(H[i].latentfrom==1) UpDating[1]++;
        else{ UpDating[4]++; }
        if(H[i].pregnant==1) NumPregInf[0]++;

      }//close if
      else{
        if(H[i].swap==4){
          H[i].health=4;
          d=log_normal_sample(exp(h_lognormal_symptomatic_scale),exp(h_lognormal_symptomatic_shape),rand());
          H[i].statetime=max(3,min(d,h_symptomatic_max));
          H[i].cumulativedays=0;
          H[i].cumulativesex=0;
          rd=(float)rand()/RAND_MAX;

          H[i].sexprobability=rd*(sextransMax-sextransMin)+sextransMin;
          H[i].timeinstate=0;
          H[i].swap=-1;

          if(H[i].latentfrom==1) UpDating[2]++;
        else{ UpDating[5]++; }
          if(H[i].pregnant==1) NumPregInf[1]++;
        }//close if
        else{
          if(H[i].swap==5){
            H[i].health=5;
            d=log_normal_sample(exp(h_lognormal_symptomatic_scale),exp(h_lognormal_symptomatic_shape),rand());
            H[i].statetime=max(3,min(d,h_symptomatic_max));
            H[i].cumulativedays=0;
            H[i].cumulativesex=0;
            rd=(float)rand()/RAND_MAX;

            H[i].sexprobability=rd*(sextransMax-sextransMin)+sextransMin;
            H[i].timeinstate=0;
            H[i].swap=-1;
            if(H[i].latentfrom==1) UpDating[2]++;
            else{ UpDating[5]++; }
            if(H[i].pregnant==1) NumPregInf[2]++;
          }//close if
          else{
            if(H[i].swap==6){

              H[i].recoveredfrom=H[i].health;
              H[i].health=6;
              H[i].statetime=999;
              H[i].timeinstate=0;
              H[i].swap=-1;
              UpDating[3]++;
            }//close if
          }//close 4th else
        }//close 3rd else
      }//close 2nd else
    }//close 1st else
  }//close for i

}

int max(int a,int b){
  int max1;
  if(a>=b) max1=a;
  else max1=b;

  return(max1);
}

int min(int a,int b){
int min1;
  if(a<=b) min1=a;
  else min1=b;

  return(min1);
}


void update_mosquito(struct Mosquito *M){

  int i,d;

  for(i=0;i<NM;i++){
    if(M[i].swap==2){

      M[i].health=2;
      d=log_normal_sample(exp(m_lognormal_latent_scale),exp(m_lognormal_latent_shape),rand());
      M[i].statetime=max(m_latency_min,min(d,m_latency_max));
      M[i].timeinstate=0;
      M[i].swap=-1;
    }//close if
    else{
      if(M[i].swap==3){
	M[i].health=3;
	M[i].statetime=M[i].ageofdeath+1;
	M[i].timeinstate=0;
	M[i].swap=-1;
      }
    }//close else


  }//close for

}

void increase_mosquito_age(struct Mosquito *M,float dist[2][60]){

  int i;

  for(i=0;i<NM;i++){

    M[i].age++;
    if(M[i].age>M[i].ageofdeath)
      set_up_mosquito(M,i,dist);
  }

}
