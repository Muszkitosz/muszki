#include "std_lib_facilities.h"
using namespace std;
void f(int);
main()
{
f(1);
string first_name;
cout<<"Enter the name of the person you want to write to: \n";
cin>>first_name;
cout<<"Dear "<<first_name<<','<<endl;
f(2);
cout<<"How are you "<<first_name<<'?'<<'\n';
cout<<"I am fine. I miss you.\n";
f(3);
string friend_name;
cout<<"Please enter the name of a friend: \n";
cin>>friend_name;
f(4);
char friend_sex=0;
cout<<"Please enter the sex of this friend (m is male and f is female)\n";
cin>>friend_sex;
if (friend_sex=='m') cout<<"If you see "<<friend_name<<" please ask him to call me.\n";
if (friend_sex=='f') cout<<"If you see "<<friend_name<<" please ask her to call me.\n";
f(5);
int age=0;
cout<<"Please enter the age of your friend: \n";
cin>>age;
if (age<0 || age>110)
{
simple_error("you're kidding!");
}
cout<<"I hear you just had a birthday and you are "<<age<<" years old.\n";
f(6);
if (age<=12) cout<<"Next year you will be "<<age+1<<'.'<<endl;
if (age==17) cout<<"Next year you will be able to vote.\n";
if (age>=70) cout<<"I hope you are enjoying retirement.\n";
f(7);
cout<<"Yours sicerely, "<<endl<<endl<<"Szilagyi Zoltan\n";

return 0;
}
void f(int a)
{
cout<<a<<". feladat: \n";
}
