#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;


void equationInput(double xVal[], string type){
	if (type=="sin"){
		cout<<"The sine function will be of the form Asin(kx)=c";
	} else if (type=="cos"){
		cout<<"The cosine function will be of the form Acos(kx)=c";
	} else if (type=="tan"){
		cout<< "The tangent function will be of the form Atan(kx)=c";
	}
	double a=0,k=0, c=0;
	cout<<endl<< "Enter in the A value: ";
	cin>>a;
	cout<<endl<<"Enter in the k value: ";
	cin>>k;
	cout<< endl<<"Enter in the c value: ";
	cin>>c;
	if (type=="sin"){
		xVal[0]=asin(c/a)/k;
	} else if (type=="cos"){
		xVal[0]=acos(c/a)/k;
	} else if (type=="tan"){
		xVal[0]=atan2(c,a)/k;
	}
	xVal[1]=M_PI/(xVal[0]);
}

int main(){
	double xVal[2]={0};
	string type="";
	cout<<"Is the equation a 'sin', 'cos', or 'tan' function?";
	cin>>type;
	equationInput(xVal,type);
	
	char pi='\u03c0';
	
	cout<<setprecision(3)<<"The decimal value of x is: "<<xVal[0]<<" radians";
	cout<<endl<<setprecision(3)<<"The value of x is: "<<pi<<"/"<<xVal[1];
}
