#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void vamoscinco(string filename);

int main()
{
    
    vamoscinco("JaimePongameCinco.dat");
    
    return 0;
    
}

void vamoscinco(string filename)
{
    ofstream outfile;
    outfile.open(filename);
    int m = 100;
    double c=1.0;
    double dx=1.0/m;
    double beta=0.8;
    double u[m+1];
    double uO[m+1];
    double uf[m+1];
    double dt = (beta*dx)/c;
    double T_final=0.5;
    int n = int(T_final/dt);
    
    for(int i=0;i<m; i++) //funcion inicial exacta
    {
        double x = i*dx;
        uO[i]=exp(-300.0*pow((x-0.12),2.0));
        uf[i]=exp(-300.0*pow(((x-0.12)-(c*T_final)),2.0));
    }
    
    for(int j=0;j<n+1; j++)
    {
            for(int i=0;i<m-1; i++)
            {
                u[i+1]=(1.0-beta*beta)*uO[i+1]-(0.5*beta)*(1.0-beta)*uO[i+2];
                
                u[0]=0.0;
                u[m-1]=0.0;
                uO[i]=u[i];
            }
            for(int i=0;i<m-1;i++)
            {
            outfile << u[i] << " ";
            }
            outfile << "\n";
    }
    
    outfile.close();
}