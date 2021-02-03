/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void build_tree(ll int *tree , ll int *a , ll int s , ll int e , ll int index){

    if(s>e)
        return;

    if(s == e){
        tree[index] = a[s];
        return;
    }

    ll int mid = (s+e)/2;
    build_tree(tree , a , s , mid , 2*index);
    build_tree(tree , a , mid + 1 , e , 2*index + 1);

    tree[index] = min(tree[2*index] , tree[2*index + 1]);

    return;

}

ll int query(ll int *tree , ll int qs , ll int qe , ll int s , ll int e , ll int index){
    // no overlapping
    if(qs > e || qe < s)
        return INT_MAX ;
    // compelete overlapping
    if(qs <= s && e <= qe)
        return tree[index];

    ll int mid = (s+e)/2;

    ll int left = query(tree , qs ,qe , s , mid , 2*index);
    ll int right = query(tree ,qs , qe , mid + 1 , e , 2*index + 1);

    return min(left,right);
}

int main(){
    
    ll int n;
    cin>>n;

    ll int a[n];
    for(int i = 0 ; i<n ; i++)
        cin>>a[i];

    ll int q;
    cin>>q;

    ll int tree[4*n + 1];
    build_tree(tree , a , 0 , n-1 , 1);
    while(q--){

        ll int x,y;
        cin>>x>>y;

        cout<<query(tree ,x,y ,0,n-1 , 1)<<endl;

    }

    return 0;
}