setwd("/home/thomas/Doutorado/PDSEproject/prog/WithMicrocephaly2/R19/teste8/")

lista<-system("ls NoM*.dat",intern = T)


lista=t(lista)

x=read.table(lista[1,1],h=F)
for(i in 2:ncol(lista)){
  
  x1=read.table(lista[1,i],h=F)
  x=rbind(x,x1)
}

sum(x$V2)

mean(x$V2)

x=x[x$V3+x$V4+x$V5>0,]
mean(x$V2)

################################################################################

x=x[x$V2>0,]

name="PregBaby67.dat"

timepreg=read.table(name,h=F)


################################################################################
#y=read.table("/home/thomas/Doutorado/PDSEproject/prog/WithMicrocephaly2/symp4.dat",h=F)

setwd("/home/thomas/Doutorado/PDSEproject/prog/Vaccination/test15Dec/Immu0/As10/Iso10/Cov0/GCov0/")
lista2<-system("ls tt*.dat",intern = T)

lista2=t(lista2)

y1=read.table(lista2[1,1],h=F)
y=y1[,4]+y1[,7]
for(i in 2:ncol(lista2)){
  
  y1=read.table(lista2[1,i],h=F)
 y=cbind(y,y1[,4]+y1[,7])
}

#y=y/ncol(lista2)



y=as.matrix(y)


sum=c()

for(j in 1:ncol(y)){
sum[j]=0;
  for(i in 140:nrow(y)){
  sum[j]=sum[j]+y[i,j]
  }

}

R0=2.2
y=y[,sum>0]
y2=c()
for(i in 1:nrow(y))
y2[i]=sum(y[i,])
y2=y2/ncol(y)

a=seq(1,nrow(y),1)
a=a/7
limit=c(1:25)
plot(a,y[,1],type="l",col="lightgrey",ylim=c(1,25))
for(i in 2:ncol(y)){
  
  lines(a,y[,i],col="lightgrey")
  
}
lines(a,y2,col="red",lwd=3)
########################################################################
preg=read.table("/home/thomas/Doutorado/PDSEproject/prog/WithMicrocephaly2/server/test4/statepreg.dat")
preg=preg[preg$V1!=0,]
preg
