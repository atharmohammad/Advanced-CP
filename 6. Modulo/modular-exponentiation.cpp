/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int modular_exp(int a , int b , int mod){

    int res = 1;
    int p = 1;
    while(b){
        int bit = b&1;
        if(bit == 1){
         res = (res*a)%mod;
        }
        b = b>>1;
        a = (a*a)%mod;
       

        // res = (res%mod * c%mod )%mod; 
    }
    return res%mod;
}

int main(){
    
    int a,b;
    cin>>a>>b;

    int mod;
    cin>>mod;

    cout<<modular_exp(a,b,mod);


    return 0;
}