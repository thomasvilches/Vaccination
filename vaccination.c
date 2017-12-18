void vaccination(struct Human *H,int VacVector[4]){

    int i,numVac,rd,numPregVac,aux;
    float rn;

    int *VacSus=malloc(N*sizeof(int));
    int *VacSusPreg=malloc(N*sizeof(int));

    numVac=numPregVac=0;
    for(i=0;i<N;i++){
        if(H[i].pregnant==1){
            if(H[i].age>=Min_age_vac_preg){
                if(H[i].age<=Max_age_vac_preg){
                    VacSusPreg[numPregVac]=i;
                    numPregVac++;
                }
            }
        }

        if(H[i].age>=Min_age_vac){
            if(H[i].age<=Max_age_vac){
                VacSus[numVac]=i;
                numVac++;
            }//close if
        }//close if

    }//close for

    //printf("%d %d\n",numPregVac,numVac);
    //getchar();

    i=0;

    while(i<Vac_Cover_Norm*numVac){
        rd=numVac*(rand()/(RAND_MAX+1.));
        if(H[VacSus[rd]].Vaccination==0){


                H[VacSus[rd]].Vaccination=1;
                H[VacSus[rd]].timevaccination=0;

            i++;
            VacVector[0]++;
        }
    }//close while

    aux=numPregVac;
    //printf("asd=%d\n",numPregVac);
    for(i=0;i<numPregVac;){
    //printf("%d %d\n",H[VacSusPreg[i]].Vaccination,numPregVac);
    //getchar();
        if(H[VacSusPreg[i]].Vaccination>0){
            for(aux=i;aux<numPregVac-1;aux++){
                VacSusPreg[aux]=VacSusPreg[aux+1];
            }
            numPregVac--;
         }
         else i++;
    }

    i=0;
    //printf("asd=%d\n",numPregVac);
    while(i<Vac_Cover_Preg*numPregVac){
        rd=numPregVac*(rand()/(RAND_MAX+1.));
        //printf("vac=%d %d\n",H[VacSusPreg[rd]].Vaccination,i);
       // getchar();
        if(H[VacSusPreg[rd]].Vaccination==0){

                H[VacSusPreg[rd]].Vaccination=2;
                H[VacSusPreg[rd]].timevaccination=0;

            i++;
            VacVector[1]++;
        }
    }//close while
    //printf("%d %d\n",numPregVac,i);
//getchar();
    free(VacSus);
    free(VacSusPreg);
}
