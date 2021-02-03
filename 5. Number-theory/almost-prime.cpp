       
        /* Author : Mohd Athar */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define ll long long
#define MOD 1000000007
#define MAX 1000000

/* unordered_map<ll int , ll int>fib; //fibbonaci

ll int f(ll int n){
    if(fib.count(n))return fib[n];

    ll int k = (n/2);  //k = 2*n
    if(n%2 == 0)
        return fib[n] = (f(k)*f(k) + f(k-1)*f(k-1))%MOD;
    else
        return fib[n] = (f(k)*f(k+1) + f(k)*f(k-1))%MOD;
    
} */

int primes[MAX] = {0};
void primesieve(){
    for(int i = 2 ; i*i<MAX ; i++){
        if(primes[i] == 1)
            continue;

        for(int j = i*i ; j<MAX ; j+=i){
                primes[j] = 1;
        }
    }
}

// ll int power( ll int a ,  ll int n){

//     if(n == 0){
//         return 1;
//     }

//      ll int subp = power(a , n/2);

//     if(n&1){
//         return  a * subp * subp;
//     }

//     return subp*subp;



// }


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

   primesieve();

   int count = 0;
   ll int ap = 0;
   for(int i = 2 ; i<=n ; i++){
       for(int j = 2 ; j<=i ; j++){
            if( i%j == 0 && primes[j] == 0)
                count++;
        }
        if(count == 2){
            ap++;
        }
        count = 0;
   }

   cout<<ap<<endl;

    return 0;
}