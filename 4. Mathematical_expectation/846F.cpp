       
        /* Author : Mohd Athar */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

#define ll unsigned long long
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

//int primes[MAX] = {0};
//void primesieve(){
    // for(int i = 2 ; i*i<MAX ; i++){
    //     if(primes[i] == 1)
    //         continue;

    //     for(int j = i*i ; j<MAX ; j+=i){
    //             primes[j] = 1;
    //     }
    // }
//}

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

ll int ans[1000000];
ll int last_occ[1000000];
ll int a[10000000];
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll int n;
    cin>>n;

  
    for(ll int i= 1;  i<=n ; i++)
        cin>>a[i];

    memset(last_occ,  0 ,sizeof(last_occ));     // last occurences array to store last occurences of every element as we have to find no unique elements 
    memset(ans , 0 ,sizeof(ans));   //ans array is to store the number of subarray of unique elements

    ans[0] = 0;
    ll int sum = 0;
    for(ll int i = 1 ; i<=n ; i++){
        ans[i] = ans[i - 1] + (i - last_occ[a[i]]);   // we just add the current number to sequence to get more unique subarrays
        last_occ[a[i]] = i;     // as if we have  4,5,2 previously as subarray no when 8 comes we get {4,5,2,8}:{2,8}:{5,2,8}:{8}
        sum += ans[i];             // these are the more unique subarrays we get in addition to prev we stored in ans 
                                // but if there is one more occurence of the number we just subtract the last occurence of that number from the number of unique subarray we get from the current number
    }                          //as this number of subarray will also contains the subarray of the previous occurence so subtracting that we just add the unique subarrays of this occurence 
    long double res = 0.0;
    res = (double)(2*(sum - n) + n)/(n*n*1.0); // as final ans willbe 2 times as we just calculate ans when l<r since number of unique subarrays for r < l will also be same
    cout<<fixed<<setprecision(12)<<res<<endl; // but we will be countining each elements twice for l == r so we subtract n from the final result

    return 0;           // result is represented as such to avoid overflow 
}