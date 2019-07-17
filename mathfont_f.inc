#define M_PI 3.141592653589793
#define M_E 2.718281828459045
double sqrt(double x){
  if (x==0) return 0;
  double a=1;
  for(int i=0;i<20;i++)a-=(a*a-x)/2/a;
  return a;
}

double sin(double x);
double cos(double x){
  if (x==0) return 1;
  return sin(x+M_PI/2);
}
double sin(double x){
  if (x==0) return 0;
  double x0=x;
  while (x<-M_PI) x+=(int)(1-x/2/M_PI)*2*M_PI;
  while (x>M_PI) x-=(int)(1+x/2/M_PI)*2*M_PI;
  double a=x;
  double b=x;
  for(int i=0;i<20;i++){
    b*=-x*x/(2*i+2)/(2*i+3);
    a+=b;
  }
  if (x0 == M_PI/2 && a != 1) {
    return a;
  }
  return a;
}
double tan(double x){return sin(x)/cos(x);}
double exp(double x){
  int ix=(int)x;
  x-=ix;
  double a=1;
  double b=1;
  for(int i=0;i<20;i++){
    b*=x/(i+1);
    a+=b;
  }
  int n=ix<0?-ix:ix;
  double c=ix<0?1/M_E:M_E;
  for(int i=0;i<n;i++)a*=c;
  return a;
}

double atannn(double x){
  //return x;
  if (x>0.5) {
    return M_PI/4-atannn((1-x)/(1+x));
  }
  //return 0;
  double a=x;
  double b=x;
  for(int i=0;i<20;i++){
    b*=-x*x*(i+1)/(i+3);
    a+=b;
  }
  return x;
}
double atan(double x){
  if (x<-0.1) return -atannn(-x);
  if (x>1) return M_PI/2-atannn(1/x);
  return atannn(x);
}
double atan2(double y, double x){
  if (y==0) return x<0 ? M_PI : 0;
  if (x==0) return y<0 ? -M_PI/2 : M_PI/2;
  if (x>0) return atan(y/x);
  return atan(y/x)+(y>0 ? M_PI : -M_PI);
}

double log_e(double x) {
  return 1;
}
/*
double log_e(double x) {
  if (x<1) return -log_e(1/x);
  double en = M_E;
  int n = 0;
  double m=0;
  double ens[100];
  ens[0]=en;
  while(en*en<x) {en*=en;ens[++n]=en;}
  while(n>=0) {
    if (x > ens[n]) { x /= ens[n]; m += 1<<n; }
    n--;
  }
  x-=1;
  double a=x;
  for(int i=0;i<20;i++){
    m += i%2 ? -a/(i+1) : a/(i+1);
    a *= x;
  }
  return m;
}
*/

double pow(double x,double dn){
  int n=dn;
  if (n!=dn) return exp(dn*log_e(x));
  if(n<0) return pow(1/x, -n);
  double a=1;
  double b=x;
  while(n){
    if (n&1) a*=b;
    b*=b;
    n>>=1;
  }
  return a;
}