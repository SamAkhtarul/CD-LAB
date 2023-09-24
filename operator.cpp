//
//  main.cpp
//  compiler 2
//
//  Created by SAM on 24/9/23.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string y;
    cout<<"enter a equation:";
    cin>>y;
    int count=0;
    
    for(int i=0;i<y.size();i++){
        
        if(y[i]=='+' || y[i]=='-' || y[i]=='/' || y[i]=='*' || y[i]=='+%' || y[i]=='=' ){
            count++;
            cout<<" operator"<<count<<":"<<y[i]<<endl;
        }
        
    }
    
    
   

}
