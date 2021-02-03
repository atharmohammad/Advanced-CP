/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,y;
void multi_mod_inverse(int a , int mod){
    if(mod == 0){
        x = a;
        y = 0;
        return ;
    }

    multi_mod_inverse(mod , a%mod);

    int cx = y;
    int cy = x - (a/mod)*y;

    x = cx;
    y = cy;


}
int inverse_mod(int a , int b){
    multi_mod_inverse(a , b);       // we just use extended eucledian algo to find the multiplicative modular inverse

    return (x  + b)%b;
}
int main(){
    
    int a,mod;
    cin>>a>>mod;

    if(__gcd(a,mod) != 1){      // multiplicative modular inverse can only be find out if the mod and the number has their has gcd equal to 1 
        cout<<"NO";
        return 0;
    }

    // multi_mod_inverse(a , mod);
    cout<<inverse_mod(a ,mod);      


    return 0;
}