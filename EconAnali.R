as=c(10,30,50,70,90)
b=c(0,60,70,80,90)

for(arquivo in 1:length(as)){
  path1=as.character(paste("/home/thomas/Doutorado/PDSEproject/prog/Data/R22/As",as[arquivo],sep=""))
  for(arquivo2 in 1:length(b)){
  print(c(arquivo,arquivo2))
    path.list=as.character(paste(path1,"/Cov",b[arquivo2],"/",sep=""))
    setwd(path.list)
    lista2<-system("ls tt*.dat",intern = T)
    lista2=t(lista2)
    y1=read.table("tt0.dat",h=F)
    y=y1[,4]
    for(i in 1:(ncol(lista2)-1)){
      File=as.character(paste("tt",i,".dat",sep=""))
      y1=read.table(File,h=F)
      y=cbind(y,y1[,4])
    }
    path.list=as.character(paste(path1,"/sympVac",b[arquivo2],".dat",sep=""))
    write.table(y,path.list,col.names = F,row.names = F)
    
    lista2<-system("ls PregBaby*.dat",intern = T)
    lista2=t(lista2)
    
    preg=read.table("PregBaby0.dat",h=F)
    
    Baby1=preg[,2]
    Baby2=preg[,3]
    Baby3=preg[,4]
    Preg1=preg[,6]
    Preg2=preg[,7]
    Preg3=preg[,8]
    
    for(i in 1:(ncol(lista2)-1)){
      
      File=as.character(paste("PregBaby",i,".dat",sep=""))
      preg=read.table(File,h=F)
      Baby1=cbind(Baby1,preg[,2])
      Baby2=cbind(Baby2,preg[,3])
      Baby3=cbind(Baby3,preg[,4])
      Preg1=cbind(Preg1,preg[,6])
      Preg2=cbind(Preg2,preg[,7])
      Preg3=cbind(Preg3,preg[,8])
    }
    path.list=as.character(paste(path1,"/Mic1Sem",b[arquivo2],".dat",sep=""))
    write.table(Baby1,path.list,col.names = F,row.names = F)
    path.list=as.character(paste(path1,"/Mic2Sem",b[arquivo2],".dat",sep=""))
    write.table(Baby2,path.list,col.names = F,row.names = F)
    path.list=as.character(paste(path1,"/Mic3Sem",b[arquivo2],".dat",sep=""))
    write.table(Baby3,path.list,col.names = F,row.names = F)
    
    path.list=as.character(paste(path1,"/InfPreg1Sem",b[arquivo2],".dat",sep=""))
    write.table(Preg1,path.list,col.names = F,row.names = F)
    path.list=as.character(paste(path1,"/InfPreg2Sem",b[arquivo2],".dat",sep=""))
    write.table(Preg2,path.list,col.names = F,row.names = F)
    path.list=as.character(paste(path1,"/InfPreg3Sem",b[arquivo2],".dat",sep=""))
    write.table(Preg3,path.list,col.names = F,row.names = F)
    
    
    
    lista<-system("ls NoM*.dat",intern = T)
    
    names1=c("sim","MicBaby","NormVac","PregVac","Ignore","Ignore2","Total")
    
    lista=t(lista)
    
    x=read.table("NoM0.dat",h=F)
    for(i in 1:(ncol(lista)-1)){
      File=as.character(paste("NoM",i,".dat",sep=""))
      x1=read.table(File,h=F)
      x=rbind(x,x1)
    }
    
    path.list=as.character(paste(path1,"/Vaccine",b[arquivo2],".dat",sep=""))
    write.table(x,path.list,col.names = F,row.names = F)
  }
}
par(mfrow=c(1,2))

setwd("/home/thomas/Doutorado/PDSEproject/prog/Data/R22/As10")

y=read.table("Mic1Sem0.dat",h=F)
yy=read.table("Mic2Sem0.dat",h=F)
yyy=read.table("Mic3Sem0.dat",h=F)
y=y+yy+yyy
sum(y)
y2=c()
for(i in 1:nrow(y))
  y2[i]=sum(y[i,])
y2=y2/ncol(y)

a=seq(1,729,1)

a=a/7
limit=c(0,1)
plot(a,y[,1],type="l",col="lightgrey",xlim=c(0,100),ylim=limit,ylab = "",xlab = "")
for(i in 2:ncol(y)){
  
  lines(a,y[,i],col="lightgrey")
  
}
lines(a,y2,col="red",lwd=3)

sum(y2)

y=read.table("Vaccine60.dat",h=F)
##########################################################

setwd("/home/thomas/Doutorado/PDSEproject/prog/Data/R22/As90")

for(arquivo2 in 1:length(b)){
  arquivo2=1
path.list=as.character(paste("Vaccine",b[arquivo2],".dat",sep=""))

x=read.table(path.list,h=F)

path.list=as.character(paste("sympVac",b[arquivo2],".dat",sep=""))
y=read.table(path.list,h=F)
Mort0=c()
Mort1=c()
for(i in 1:sum(x$V2)){
  aux=1
  while(aux==1){
    Mort0[i]=-35*log(1-runif(1,0,1))
    Mort1[i]=-70*log(1-runif(1,0,1))
    if(Mort1[i]>Mort0[i])
      if(Mort1[i]<100) aux=0
  }
  
}

DeadBabies=rbinom(sum(x$V2),1,0.8)
SympCost=c()
for(i in 1:ncol(y))
  SympCost[i]=sum(y[,i])*64.5

bb=1
MicCost=c()
for(j in 1:nrow(x)){
  MicCost[j]=0
 
  if(x[j,2]!=0){
    for(i in 1:x[j,2]){
      
      MicCost[j]=MicCost[j]+690000*DeadBabies[bb]
      bb=bb+1
    }
  }
}

VaccineCost=x$V4*1.89
table=cbind(t(t(SympCost)),t(t(MicCost)),t(t(VaccineCost)))
TotalPerCat = c(sum(table[,1]),sum(table[,2]),sum(table[,3]))
TotalCost=sum(TotalPerCat)

r=0.03
w=0.5
bb=1
YLL=c()
YLD=c()
DALY=c()
for(j in 1:nrow(x)){
  YLL[j]=0
  YLD[j]=0
  if(x[j,2]!=0){
    for(i in 1:x[j,2]){
      if(DeadBabies[bb]==0) YLL[j]=YLL[j]+(1/r)*(1-exp(-r*Mort1[bb]))
      else{
        YLD[j]=YLD[j]+w*(1/r)*(1-exp(-r*Mort0[bb]))
        YLL[j]=YLL[j]+(1/r)*(1-exp(-r*(Mort1[bb]-Mort0[bb])))*exp(-r*Mort0[bb])
      }
      bb=bb+1
    }
  }
  DALY[j]=YLL[j]+YLD[j]
}

table2=cbind(SympCost,MicCost,VaccineCost,YLL,YLD,DALY)
path.list=as.character(paste("CostTable",b[arquivo2],".dat",sep=""))
write.table(table2,path.list)
}