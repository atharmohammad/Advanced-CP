/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[100];
int blk[100] = {0};
int blk_siz;
void preprocess(int *in , int n){

    blk_siz = sqrt(n-1);
    int blk_index = -1;

    for(int i = 0 ; i<n ; i++){
        arr[i] = in[i];
        if(i%blk_siz == 0){
            blk_index++;
        }
        blk[blk_index] += arr[i];
    }
}   
void update(int k , int val){
    int block_num = k/blk_siz;
    blk[block_num] += val - arr[k];
    arr[k] = val;
}
int query(int l , int r){
    int sum = 0;
    while(l < r && l%blk_siz != 0 && l != 0){// here we are traversing first block .. 
        sum += arr[l];  // l%blk_size will be zero when we reach next block so we stop
        l++;        //  l != 0 is because lets say l = 0 now if first block is completly 
    }               // inside range so whole block will be added in second loop 
                    // and if r is also in  first block then it will be calculated in last loop
                    // so we see only if l > 0 coz we dont need prev, elements from l in first block
   

    while(l + blk_siz <= r){    // here we are adding those blocks which are lying compeletly inside
        sum += blk[l/blk_siz];  
        l += blk_siz;
    }

    while(l <= r){  // now we are adding if there are some elements in block which is not compeletly inside range
        sum += arr[l];  // so we traverse in array not in block as we dont need elements after r
        l++;
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 10;
    int in[n] = {1,2,4,5,3,6,7,9,8};

    preprocess(in , n);
    int q;
    cin>>q;

    while(q--){
        int op;
        cin>>op;

        if(op){
            int a,b;
            cin>>a>>b;
            cout<<query(a-1,b-1)<<" ";
        }
        else{
            int k,val;
            cin>>k>>val;
            update(k-1 , val);
        }
        
    }


    return 0;
}