#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

int main(){
	double solution=0;
	int b=0;
	double k=0;c=0;
	cout<<"The logarithm will have base b and be of the form log(kx)=c ";
	cout<<endl<<"Enter the base: ";
	cin>>b;
	cout<<endl<<"Enter the value of k: ";
	cin>>k;
	cout<<endl<<"Enter the value of c: ";
	cin>>c;
	solution=(pow(b,c)/k); 
	
}



