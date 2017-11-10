/*

gnuplot

gcc -O3 graficos.c -lm
./a.out
gnuplot graficos.gp

*/

/*color solid*/
void grafico(int j)
{
  FILE *P2;
  int i;
  P2 = fopen("graficos.gp","w");
  fprintf(P2,"set term postscript  eps enhanced color\n\n");
  // fprintf(P2,"set output 'ex1.eps'\n");
  // fprintf(P2,"set xlabel 'x'\n");
  //fprintf(P2,"set ylabel 'y'\n");
  //fprintf(P2," plot [1.5:2.5] x**2-x+1 w l,3\n");
  //fprintf(P2,"set output 'ex2.eps'\n");
  //fprintf(P2,"set xlabel 'x'\n");
  //fprintf(P2,"set ylabel 'y'\n");
  //fprintf(P2,"set key at 0.9,2.08\n");
  //fprintf(P2," plot [0.8:1.2] (x-1)/(sqrt(x)-1) w p, sqrt(x)+1,2\n");
  //fprintf(P2,"set output 'ex3.eps'\n");
  //fprintf(P2,"set xlabel 'x'\n");
  //fprintf(P2,"set ylabel 'y'\n");
  //fprintf(P2,"set key at 2.45,0.16\n");
  //fprintf(P2," plot [1.2:2.5] (2*x**2-5*x+2)/(5*x**2-7*x-6) w p, (2*x-1)/(5*x+3),3./13\n");
  //fprintf(P2,"set output 'ex4.eps'\n");
  //fprintf(P2,"set xlabel 'x'\n");
  //fprintf(P2,"set ylabel 'y'\n");
  //fprintf(P2,"set key at 0.8,2.5\n");
  //fprintf(P2,"set sample 101\n");
  //fprintf(P2,"f(x) = x != 1 ? (x**2-1)/(x-1):3\n");
  //fprintf(P2," plot [0.5:1.5][1.4:3.2] f(x) w p, x+1, 2\n");
  //fprintf(P2,"set output 'ex5.eps'\n");
  //fprintf(P2,"set xlabel 'x'\n");
  //fprintf(P2,"set ylabel 'y'\n");
  //fprintf(P2,"set key at 1,9\n");
  //fprintf(P2,"set sample 101\n");
  //fprintf(P2,"f(x)=x<1? x**2:2*x\n");
  //fprintf(P2," plot [-5:5][0:10] f(x) w p, 2,1\n");
  /*
  fprintf(P2,"set output 'ex6.eps'\n");
  fprintf(P2,"set multiplot\n");
  fprintf(P2,"set size 1.0, 0.5\n");
  fprintf(P2,"set origin 0.0,0.5\n");
  fprintf(P2," plot [-1:0]7*x**5-4*x**3+2*x-9,7*x**5\n");
  fprintf(P2,"set origin 0.0,0.0\n");
  fprintf(P2,"set key at -99.2,-6.4e+10\n");
  fprintf(P2," plot [-100:-98]7*x**5-4*x**3+2*x-9,7*x**5\n");
  
  
  fprintf(P2,"set output 'ex7.eps'\n");
  fprintf(P2,"set multiplot\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"set size 1.0, 0.5\n");
  fprintf(P2,"set origin 0.0,0.5\n");
  fprintf(P2,"plot [2:10][0:3](3*x+5)/(6*x-8),1./2\n");
  fprintf(P2,"set origin 0.0,0.0\n");
  fprintf(P2,"set key at 985,0.54\n");
  fprintf(P2,"plot [980:1000][0.45:0.55](3*x+5)/(6*x-8) w p,1./2\n");
  
  
  fprintf(P2,"set output 'ex8.eps'\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"set size 1.0, 1.0\n");
  fprintf(P2,"set key at 0.94,1.48\n");
  fprintf(P2,"plot [0.8:1.2] sqrt((x**2-1)/(x-1)) w p, sqrt(x+1), sqrt(2)\n");
  
  fprintf(P2,"set output 'ex9.eps'\n");
  fprintf(P2,"set multiplot\n");
 fprintf(P2,"set xlabel 'x'\n");
 fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"set size 1.0, 0.34\n");
  fprintf(P2,"set origin 0.0,0.34\n");
  fprintf(P2,"set key at 1.2,0.55\n");
  fprintf(P2,"plot [0.5:1.5] (x-1)/(x**3-1) w p, 1./(x**2+x+1), 1./3\n");
  fprintf(P2,"set origin 0.0,0.68\n");
  fprintf(P2,"set key at -0.6,0.85\n");
  fprintf(P2,"plot [-1.5:-0.5] (x+2)**(1./3),1\n");
  fprintf(P2,"set origin 0.0,0.0\n");
  fprintf(P2,"set key at -0.6,0.4\n");
  fprintf(P2,"plot [-1.5:-0.5] ((x+2)**(1./3)-1)/(x+1) w p, 1./3\n");
   fprintf(P2,"set output 'ex10.eps'\n");
  fprintf(P2,"set multiplot\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"set size 1.0, 0.5\n");
  fprintf(P2,"set origin 0.0,0.5\n");
  fprintf(P2,"set key at 1.8,-40\n");
  fprintf(P2,"plot [1.5:2.5](x**4-16)/(2-x) w p, -(x**3+2*x**2+4*x+8),-32\n");
  fprintf(P2,"set origin 0.0,0.0\n");
  fprintf(P2,"set key at 1.8,-40\n");
  fprintf(P2,"plot [0:2] ((3-x**3)**4-16)/(x**3-1) w p,-32\n");
  
  fprintf(P2,"set output 'ex11.eps'\n");
  fprintf(P2,"set multiplot\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"set size 1.0, 0.5\n");
  fprintf(P2,"set origin 0.0,0.5\n");
  fprintf(P2,"set key at -0.1,0.8\n");
   fprintf(P2,"plot [-0.2:0.2]sin(1./x) w l\n");
  fprintf(P2,"set origin 0.0,0.0\n");
  fprintf(P2,"set key at 0.17,-0.12\n");
  fprintf(P2,"plot [-0.2:0.2] x*sin(1./x) w l,0 \n");

  fprintf(P2,"set output 'ex13.eps'\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"plot [][:0.7] (1.-cos(x))/x**2,1./2 w l\n");
  
  fprintf(P2,"set output 'ex14.eps'\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
  fprintf(P2,"plot [][] (1-cos(x))/x w l,0\n");


 fprintf(P2,"set output 'parametrico.eps'\n");
  fprintf(P2,"set multiplot\n");
  fprintf(P2,"set xlabel 'x'\n");
  fprintf(P2,"set ylabel 'y'\n");
fprintf(P2,"set xrange [0:21]\n");
fprintf(P2,"set yrange [0:5]\n");
  fprintf(P2,"set size 1.0, 0.5\n");
  fprintf(P2,"set origin 0.0,0.5\n");
  fprintf(P2,"plot 'pontos.dat' u 1:2 t''\n");
  fprintf(P2,"set origin 0.0,0.0\n");
  //fprintf(P2,"set key at 985,0.54\n");
  fprintf(P2,"plot 'pontos.dat' u 1:2 t'', 'reta.dat' u 1:2 t'' w l linestyle -1\n");
  
  



  */
  fprintf(P2,"set output 'parametrico%d.eps'\n",j);
  fprintf(P2,"set xlabel '{/*1.5 time (week))}'\n");
  fprintf(P2,"set ylabel '{/*1.5 Symp}'\n");
  
  fprintf(P2,"plot [0:100] 'files%d/test0.dat' u ($1/7):($5+$6) t'' w l lc 6, ",j);
  for(i=1;i<NumberOfFiles;i++) fprintf(P2,"'files%d/test%d.dat' u ($1/7):($5+$6) t'' w l lc 6,",j,i);
  
  fprintf(P2,"'files%d/result.dat' u ($1/7):5 t'' w l lc -1 lw 4",j);
}
