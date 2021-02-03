       
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

void build_tree(ll int*tree , ll int *a , int index , int s , int e){
    if(s > e)
        return ;

    if(s==e){
        tree[index] = a[s];
        return;
    }

    int mid = (s+e)/2;

    build_tree(tree , a , 2*index, s , mid);
    build_tree(tree , a , 2*index+1 , mid+1 , e);

    tree[index] = max(tree[2*index] , tree[2*index + 1]);
}
void update(ll int *tree , int i , ll int x , int index , int s , int e){
    if(s > i || e < i)
        return;

    if(s == e){
        tree[index] = x;
        return;
    }

    int mid = (s+e)/2;
    update(tree , i , x , 2*index , s , mid);
    update(tree , i , x , 2*index+1 , mid+1 , e);

    tree[index] = max(tree[2*index] , tree[2*index + 1 ]);
}
int seg(ll int *tree , ll int x , int index , int s , int e){
    if(x > tree[index])
        return INT_MAX;

    if(s == e)
        return s;                   // Remember : only call left or right only if they have an element 
                                    //greater or equal to given
    int mid = (s+e)/2;
    if(x <= tree[2*index]){
        int left = seg(tree , x , 2*index , s , mid);
        return left;
    }
    else if(x <= tree[2*index + 1]){
        int right = seg(tree , x , 2*index + 1 , mid+1, e);
        return right;
    }
    else
        return INT_MAX;
   
}
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    ll int a[n];
    for(int i = 0 ; i<n ; i++)
        cin>>a[i];

    ll  int tree[4*n + 1] ;
    build_tree(tree , a , 1 , 0 , n-1);
    while(m--){

        int op;
        cin>>op;

        if(op == 1){
            ll int i,x;
            cin>>i>>x;
            update(tree , i , x , 1 , 0 , n-1);
        }
        else{
            ll int x;
            cin>>x;
            int res = seg(tree , x , 1 , 0 , n-1);
            if(res == INT_MAX)
                cout<<"-1";
            else
                cout<<res;

            cout<<"\n";
        }


    }


    return 0;
}