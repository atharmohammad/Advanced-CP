#include<bits/stdc++.h>
using namespace std;

#define MAX 10000005
#define ll long long 
bitset<MAX>b;
vector<ll int >primes;
void bitsieve(){
    b.set();

    b[0]=b[1]=0;

    for(ll int i = 2 ; i<MAX ; i++){
        if(b[i]){
            primes.push_back(i);
        }
        else{
            continue;
        }

        for(ll int j = i*i; j<=MAX ; j +=i){
            b[j] = 0;
        }
    }

}
bool isprime(ll int num){
    if(num <= MAX)
        return b[num] == 1 ? true : false;

    for(ll int i = 0 ; primes[i]*(ll int )primes[i] <= num ; i++){
        if(num % primes[i] == 0)
            return false;
    }

    return true;
}
int main(){

     bitsieve();

    if(isprime(20234565667)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }


}