#include "std_lib_facilities.h"

using namespace std;

int main()
{

    cout<<"Egyszeru szamologep v1.1"<<endl;
    cout<<"Hasznalhato muveletijelek: + - * / q(kilepes) "<<endl;
    cout<<"Hasznalat: szam,muveletijel,szam,enter,vegeredmeny "<<endl;
    char op;
    float szam1,szam2,potsz;
    cin>>szam1>>op>>szam2;
    float eredmeny;

    switch(op)
    {
        case '+':
         eredmeny = szam1+szam2;
         break;

        case '-':
          eredmeny = szam1-szam2;
          break;

        case '*':
          eredmeny = szam1*szam2;
          break;

        case '/':
          eredmeny = szam1/szam2;
          break;

        case 'q':
          exit(0);
          break;

        default:

              cout<<"Hibas muveletijel!"<<endl;
              exit(0);
              break;
    }
    cout<<"Vegeredmeny: "<<eredmeny<<endl;
  while(cin){
      cin>>op>>potsz;
      switch(op) {

        case '+':
         eredmeny = eredmeny + potsz;
         break;

        case '-':
          eredmeny = eredmeny - potsz;
          break;

        case '*':
           eredmeny = eredmeny * potsz;
           break;

        case '/':
            eredmeny = eredmeny / potsz;
            break ;

        case 'q':
            exit(0);
            break;

        default:

           cout<<"Hibas muveletijel!"<<endl;
           break;
           exit(0);
      }
      cout<<"Vegeredmeny: "<<eredmeny<<endl;
    }
    return 0;
}
