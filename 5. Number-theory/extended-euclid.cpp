#include<bits/stdc++.h>
using namespace std;
int x,y,GCD;
void extended_euclid(int a , int b){
    if(b == 0){
        x = 1;
        y = 0;
        GCD = a;
        return ;
    }

    extended_euclid(b , a%b);
    int cx = y;
    int cy = x - (a/b)*y;

    x = cx;
    y = cy;
    

}
int main(){

    int a,b;
    cin>>a>>b;

   extended_euclid(a , b);
   cout<<x<<" "<<y<<endl;

}