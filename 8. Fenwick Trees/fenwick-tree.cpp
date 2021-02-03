/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fenwick[1000] = {0};
void update(int i , int n , int x){
    while(i-1 < n){

        fenwick[i] += x;
        i += (i&(-i));  // we are just updating those index in which the give index is included 
    }                   // we find it by taking its bitwise AND with its 2's compliment and adding in the index 
}
int range(int x){

    int sum = 0;
    while(x > 0){       // here we can find sum by adding those sum in whose range our index lies  
        sum += fenwick[x];  // we only needs those which are in the left and include our index 
        x -= (x&(-x));  // so we just add and subtrtact 2's power in same way we did in update
    }

    return sum;

}
int sum(int l , int r){
    return range(r) - range(l-1);
}
int lower_bound_pre_sum(int s , int n){

    int prevsum = 0;
    int curr = 0;
    for(int i = log2(n) ; i>= 0; i--){
        if(fenwick[curr + (1<<i)] + prevsum < s){ // traversing in power's of 2 and see if sum is smaller than we need 
           curr += (1<<i);                              
            prevsum += fenwick[curr];
        }
    }

    return curr+1 ;
}
int main(){
    
    int n = 10;

    int arr[n] = {1 , 2 , 3 , 4 , 5,  6 , 7 , 8 , 9 , 10}; 

    for(int i = 0 ; i<n ; i++){
        update(i+1 , n , arr[i]); //  here in decleration we put i + 1 as we are making fenwick array 1 based indexing 
    }

    int q;
    cin>>q;

    while(q--){
        int l,r;    // we are also quering on 1 based indexing means if you want sum from 0 you would give l as 1 instead of 0
        cin>>l>>r;

        cout<<sum(l , r)<<endl;
    
    }
    cout<<lower_bound_pre_sum(16 , n) -1; // here we are subtracting 1 because we took fenwick array as 1 based indexinig 
    // so now it has become 0 indexed and we see from 0 to ...        


    return 0;
}