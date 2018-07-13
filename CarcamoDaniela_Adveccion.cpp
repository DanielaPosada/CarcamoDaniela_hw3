#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::endl;

double fescalon(double y);

int main(){

  
  double nx=80.0;
  double nt=30.0;
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
	U_pasado[i]=u_inicial[i];
    }    
Ufuturo[0]=1.0;
Ufuturo[nx-1]=1.0;

double Upresente[nx];	
Upresente[0]=1.0;
Upresente[nx-1]=1.0;
for(i=1;i<nx-1;i++)
    {
        	Ufuturo[i]=-(c*dt/dx)*(u_inicial[i]-u_inicial[i-1])+u_inicial[i];
	Upresente[i]=Ufuturo[i];
    }
for (j=0;j<nt;j++)
{
	for (i=1;i<nx-1<i++)
	{
		Ufututo[i]=Upresente[i]-((c*dt/dx)*(Upresente[i]-Upresente[i-1])	)
	}
Upasado[j]=Upresente[j];
Upresente[j]=Ufuturo[j];
}


 return 0;
}

double fescalon(double y)
{
	double resp:
	
	if(0.75<y<=1.25)
	{
		resp=2.0;
	}
	else
	{
		resp=1.0;
	}

	return resp;
}
