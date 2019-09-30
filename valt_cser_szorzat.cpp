#include "std_lib_facilities.h"
using namespace std;
main()
{
int a=0, b=0;
cout<<"Adjon meg erteket a-nak es b-nek! \n";
cin>>a>>b;

cout<<"1. valtozo= "<<a<<endl;
cout<<"2. valtozo= "<<b<<endl;

//csere

a=a*b;
b=a/b;
a=a/b;

cout<<"Csere utan: \n";

cout<<"1. valtozo= "<<a<<endl;
cout<<"2. valtozo= "<<b<<endl;

return 0;
}
