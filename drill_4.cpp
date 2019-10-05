#include "std_lib_facilities.h"
#include <cmath>
#include <vector>
using namespace std;
main()
{
/*
double a,b;
while (cin>>a>>b && (a!='|' || b!='|'))
{
if (abs(a-b)<1.0/100 && a!=b) cout<<"The numbers are almost equal \n";
else if (a<b) cout<<"The smaller value is: "<<a<<'\n'<<"The larger value is: "<<b<<endl;
else if (a>b) cout<<"The smaller value is: "<<b<<'\n'<<"The larger value is: "<<a<<endl;
else if (a=b) cout<<"The numbers are equal! \n";
}*/  //1-5. feladatok
/*
double c;
double legnagyobb=0, legkisebb=0;
bool k=true;
while (cin>>c)
{
cout<<c<<'\n';
if (k) 
{
legnagyobb=c;
legkisebb=c;
k=false;
}
else if (c<legkisebb)
{
cout<<"The smallest so far \n";
c=legkisebb;
}
else if (c>legnagyobb)
{
cout<<"The largest so far \n";
c=legnagyobb;
}
}*/ //6.feladat
double d;
string mertek;
vector <double> v;
bool k=true;
double sum=0;
double smallest, largest, db=0;

cout<<"Please enter a number and an unit: \n";
while (cin>>d>>mertek)
{
if (mertek=="cm")
{
d=d/100;
sum+=d;
db++;
}
else if (mertek=="in")
{
d=d*2.54/100;
sum+=d;
db++;
}
else if (mertek=="ft")
{
d=d*12*2.54/100;
sum+=d;
db++;
}
else if(mertek=="m")
{
sum+=d;
db++;
}
else cout<<"Wrong unit! \n";
v.push_back(d);
if(k)
{
    smallest=d;
    largest=d;
    k=false;
}
else if (d<smallest) 
{
    cout<<"The smallest so far "<<"\n";
    smallest=d;
}
else if (d>largest)
{
    cout<<"The largest so far "<<"\n";
    largest=d;
}
}
cout<<"Largest: "<<largest<<'\n';
cout<<"Smallest: "<<smallest<<'\n';
cout<<"Sum: "<<sum<<'\n';
cout<<"DB: "<<db<<'\n';

sort(v.begin(),v.end());
 for (int i = 0;i<v.size();i++)
{
   cout<<v[i]<<" ";
}

return 0;
}
