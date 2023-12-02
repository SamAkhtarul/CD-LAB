#include<iostream>
#include<string>
#define max 5
using namespace std;

int add(int x, int y){
     return x+y;
}

int sub(int x, int y){
     return x-y;
}
int mul(int x, int y){
     return x*y;
}


int main(){
    int a=10, b=9, c=0;
    cout<<"Hello";
    c = a + b;
    int d, e,f;
    d = c - 10;
    e = d * 5 ;
    a = add(b, c);
    d = sub(a, 10);
    f= mul(a,b);
    return 0;
}


