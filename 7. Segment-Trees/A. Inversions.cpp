       
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
int sum(int*tree,int index , int x , int s , int e ){
    if(e < x)
        return 0;

    if(x <= s)
        return tree[index];

    int mid = (s+e)/2;
    int left = sum(tree , 2*index , x , s , mid);
    int right = sum(tree , 2*index+1 , x , mid+1 , e);

    return(left + right);
}
void update(int*tree,int index , int x , int s , int e){

    if( x < s ||e < x)
        return ;

    if(s == e){
        tree[index] = 1;
        return ;
    }

    int mid = (s+e)/2;
    update(tree , 2*index , x , s , mid);
    update(tree , 2*index+1 , x ,mid+1 ,e);

    tree[index] = (tree[2*index] + tree[2*index+1]);

}
int seg(int*tree , int x , int e){
    int s = sum(tree , 1 , x-1 , 0 , e);
    update(tree ,1, x-1 ,0 ,e);

    return s;
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int p[n];
    for(int i = 0 ; i<n ; i++)
        cin>>p[i];

                                // Approach: we fill our segment tree with 0 first
    int tree[4*n+1] = {0};      // then we traverse in our segment tree and calculate sum for every index greater than element
                                // and return that sum and then update the value of our index to 1
    for(int i = 0 ; i<n ; i++){ // in simple words we can say , we are using segment tree as a visited tree
        cout<<seg(tree ,p[i], n-1)<<" ";    // we mark those index 1 which have come in the permutations
    }                           // and sum of those 1 which are right of it will bve number of elements greater than it which have come in permutation up untill now
                                
    return 0;
}