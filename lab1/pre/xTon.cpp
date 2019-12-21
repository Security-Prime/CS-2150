// Fr2md Farid Rajabi Nia xTon.Cpp

#include <iostream>
using namespace std;

int foo (int a, int b) {
  if (b==0)
    return 1;
  else
    return (a*foo(a,b-1));
}

int main( ) {
    int x, y, z;
    cout<<"Enter a number: "<<endl;
    cin >> x;
    cout<<"Enter a positive number: "<<endl;
    cin >> y;
    z = foo (x, y);
    cout << x << " ^ " << y << " = " << z << endl;
    return 0;
}
