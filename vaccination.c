void vaccination(struct Human *H,int VacVector[4]){

    int i,numVac,rd,numPregVac;
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
        else{
            if(H[i].age>=Min_age_vac){
                if(H[i].age<=Max_age_vac){
                    VacSus[numVac]=i;
                    numVac++;
                }//close if
            }//close if
        }
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

    i=0;
    while(i<Vac_Cover_Preg*numPregVac){
        rd=numPregVac*(rand()/(RAND_MAX+1.));
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
