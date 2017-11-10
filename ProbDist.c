float Poisson(float xm){//this function returns a number with a poisson distribuition!
    
  static float sq,alxm,g,oldm=(-1.0);
  float em,t,y;
  //printf("entrou poisson");
  
  if (xm < 12.0) {
    if (xm != oldm) {
      oldm=xm;
      g=exp(-xm);
    }
    em = -1;
    t=1.0;
    do {
      ++em;
      t *= (float)rand()/(RAND_MAX);
    } while (t > g);
  } else {
    if (xm != oldm) {
      oldm=xm;
      sq=sqrt(2.0*xm);
      alxm=log(xm);
      g=xm*alxm-gammln(xm+1.0);
    }
    do {
      do {
	y=(float)rand()/(RAND_MAX);
	em=sq*y+xm;
      } while (em < 0.0);
      em=floor(em);
      t=0.9*(1.0+y*y)*exp(em*alxm-gammln(em+1.0)-g);
    } while ((float)rand()/RAND_MAX > t);
  }
  // printf("poisson=%f\n",em);
  //getchar();
  return(em);
}

float gammln(float xx)
//Returns the value ln[Γ( xx )] for xx > 0.
{
  double x,y,tmp,ser;
  static double cof[6]={76.18009172947146,-86.50532032941677,
			24.01409824083091,-1.231739572450155,
			0.1208650973866179e-2,-0.5395239384953e-5};
  int j;
  y=x=xx;
  tmp=x+5.5;
  tmp -= (x+0.5)*log(tmp);
  ser=1.000000000190015;
  for (j=0;j<=5;j++) ser += cof[j]/++y;
  return(-tmp+log(2.5066282746310005*ser/x));
}
