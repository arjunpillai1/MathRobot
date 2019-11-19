#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

int main(){
	//char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int a=0,b=0,c=0;
	string equation="";
	
	cout<<"Enter the quadratic equation in the form ax2+bx+c"<<endl;
	cin>> equation;
	
	char equationCharArray[9];
	strcpy(equationCharArray,equation.c_str());
	
	const int charToIntConversionNum=48;
	a=(char)equationCharArray[0]-48;
	b=(char)equationCharArray[4]-48;
	c=(char)equationCharArray[7]-48;
	
	cout<<a<<" "<<b<<" "<<c;
	cout<<endl<<(a+b+c);
	
	double discriminant=b*b-4*a*c;
	if (discriminant>0){
//		string x1="%f"
		to_string(45.2);
		//string x1="x1 is "+ to_string((-b+sqrt(discriminant))/(2*a));
		//string x2=to_string((-b-sqrt(discriminant))/(2*a));
	} else if (discriminant==0){
		 
	}
	
}
