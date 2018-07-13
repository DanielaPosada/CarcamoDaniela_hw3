#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::endl;

double fescalon(double y);

int main(){

  
  int nx=80;
  int nt=3;
  double dx=2.0/nx;
  double c=1.0;
  double dt=(1/2.0)*dx/c;
  double ti=0.0;
  double tfinal=nt*dt;

//Construyo el vector de tiempo
	int i,j;
  double tiempo[nt];
  double x[nx];
  double Ufuturo[nx];
  double u_inicial[nx];
double Upasado[nx];
 for(i=0;i<nx;i++)
    {
  	x[i]=dx*i;
	u_inicial[i]=fescalon(x[i]);
	Upasado[i]=u_inicial[i];
		  cout << 0 << " " << x[i] << " " << u_inicial[i] << endl;
    }    
Ufuturo[0]=1.0;
Ufuturo[nx-1]=1.0;

double Upresente[nx];	
Upresente[0]=1.0;
Upresente[nx-1]=1.0;
 for(i=1;i<nx-1;i++)
    {
        Ufuturo[i]=-(c*dt/dx)*(u_inicial[i]-u_inicial[i-1])+u_inicial[i-1];
	Upresente[i]=Ufuturo[i];
	
	
    }
 tiempo[0]=0;
 for (j=1;j<nt;j++)
{
  tiempo[j]=j*dt;
  for (i=1;i<nx-1;i++)
	{
	  Ufuturo[i-1]=Upresente[i-1]-((c*dt/dx)*(Upresente[i]-Upresente[i-1]));
	  cout << tiempo[j] << " " << x[i] << " " << Ufuturo[i-1] << endl;
	 }
  for (i=0;i<nx;i++)
    {
      Upresente[i]=Ufuturo[i];
    }
  
}


 return 0;
}

double fescalon(double y)
{
  double resp;
	
	if(0.75<=y&&y<=1.25)
	{
		resp=2.0;
	}
	else
	{
		resp=1.0;
	}

	return resp;
}
