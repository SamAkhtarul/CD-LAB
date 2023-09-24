//
//  main.cpp
//  compiler lab
//
//  Created by SAM on 24/9/23.


//token catagorization

#include<iostream>
#include<string>
using namespace std;

int main()
{
string x;

int length;

cout<<"enter an input:";

cin>>x;
length=x.length();

for(int i=0;i<length;i++)
    {
        if(!isdigit(x[i]))
            
            
        {
            cout<<"This is not a number. \n";

            return 1;
        }
    }
    cout<<"This is a number \n";

       return 0;

}
