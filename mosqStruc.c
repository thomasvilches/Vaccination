void set_up_mosquito(struct Mosquito *M,int i,float dist[2][60]){

 
    M[i].health=1;
    M[i].infectionfrom=-1;
    M[i].age=1;
    M[i].statetime=999;
    M[i].timeinstate=999;
    M[i].numberofbites=-1;
    M[i].swap=-1;
    M[i].ageofdeath=lifespan(dist);
    BiteDistribuition(M,i);
  
}//close function


int lifespan(float dist[2][60]){

  int i,life,maximumDays[2];
  float rd;

  maximumDays[0]=60;
  maximumDays[1]=30;
  
    
  rd=(float)rand()/RAND_MAX;
  
  for(i=0;i<maximumDays[season];i++)
    if(rd<dist[season][i]){
      break;
    }
  
  return(i+1); 
}

void BiteDistribuition(struct Mosquito *M,int i){

  int count,rd,j;
  float mean;
  
  
    //printf("%d\n",M[i].ageofdeath);
    mean=M[i].ageofdeath/2.;
    
    //printf("mean=%f\n",mean);
    //getchar();
    M[i].numberofbites=Poisson(mean);

    if(M[i].numberofbites<M[i].ageofdeath){
      count=M[i].numberofbites;
      
      for(j=0;j<M[i].ageofdeath;j++) M[i].bitesdistribuition[j]=0;
      
      while(count>0){
	rd=M[i].ageofdeath*(rand()/(RAND_MAX+1.));
	if(M[i].bitesdistribuition[rd]==0){
	  M[i].bitesdistribuition[rd]=1;
	  count--;
	}//close if Mbitesdist
      }//close while
    }//close if number<death
    else  for(j=0;j<M[i].ageofdeath;j++) M[i].bitesdistribuition[j]=1;
 
}

