/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class three{
    ll int pref,suf,val;
};

ll int NEUTRAL_ELEMENT = {-15008,-15008 , -15008};
three single(ll int value){
    if(value > 0)
        return { value , value , value};
    else
        return {-15008 ,-15008 ,value};
}
three merge(three a , three b){
    return { 
        a.val,
        b.val,
        max(max(a.pref,a.suf) , max(a.suf + b.pref , max(a.val + b.val , max(b.pref , b.suf))))
    };
}
void build_tree(ll int *tree , ll int *a , ll int s , ll int e , ll int index){

    if(s>e)
        return;

    if(s == e){
       tree[index] = single(a[s]);
       return;
    }

    ll int mid = (s+e)/2;
    build_tree(tree , a , s , mid , 2*index);
    build_tree(tree , a , mid + 1 , e , 2*index + 1);

    tree[index] = merge(tree[2*index] , tree[2*index + 1]);

    return;

}

three query(ll int *tree , ll int qs , ll int qe , ll int s , ll int e , ll int index){
    // no overlapping
    if(qs > e || qe < s)
        return NEUTRAL_ELEMENT ;
    // compelete overlapping
    if(qs <= s && e <= qe)
        return tree[index];

    ll int mid = (s+e)/2;

    ll int left = query(tree , qs ,qe , s , mid , 2*index);
    ll int right = query(tree ,qs , qe , mid + 1 , e , 2*index + 1);

    return merge(left , right);
}

int main(){
    
    ll int n;
    cin>>n;

    ll int a[n];
    for(int i = 0 ; i<n ; i++)
        cin>>a[i];

    ll int q;
    cin>>q;

    three tree[4*n + 1];
    build_tree(tree , a , 0 , n-1 , 1);
    while(q--){

        ll int x,y;
        cin>>x>>y;

        three res = query(tree ,x-1,y-1,0,n-1 , 1);
        cout<<res.val<<endl;
    }

    return 0;
}