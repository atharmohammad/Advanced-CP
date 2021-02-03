/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lazy[10000] = {0};
void lazy_propagation(int *tree , int s , int e , int index , int qs , int qe , int inc){

    if(lazy[index] != 0){
        tree[index] += lazy[index];      // first we see that if parent has  a lazy update we update its children 
        if(s != e){                    // and made lazy update of parent 0
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }   
        lazy[index] = 0;
    }

    if(qs > e || qe < s)
        return;


    if(qs <= s && qe >= e){ // now if range compeletly overlaps than increase lazy update of it and its children 
        tree[index] += inc;
        if(s != e){
            lazy[2*index] += inc;
            lazy[2*index + 1] += inc;
        }
        return;
    }

    int mid = (s+e)/2;

    lazy_propagation(tree , s , mid , 2*index , qs , qe , inc);
    lazy_propagation(tree , mid + 1 , e , 2*index+1 , qs , qe , inc);
    tree[index] = min(tree[2*index] , tree[2*index + 1]);
}
void build_tree(int *tree , int *a , int s , int e , int index){

    if(s > e)
        return ;

    if(s == e)
        tree[index] = a[s];

    build_tree(tree , a , s , e , 2*index);
    build_tree(tree , a  ,s , e , 2*index + 1);

    tree[index] = min(tree[2*index] , tree[2*index+1]);

}
int query(int *tree , int s , int e , int index , int qs , int qe){

    if(lazy[index] != 0){
        tree[index] += lazy[index];
        if(s != e){
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }

        lazy[index] = 0;
    }

    if(qs > e || qe < s)
        return INT_MAX;

    if(qs <= s && qe >= e){
        return tree[index];
    }

    int mid = (s+e)/2;
    int left = query(tree , s , mid , 2*index , qs , qe);
    int right = query(tree , mid + 1 , e , 2*index + 1 , qs , qe);

    tree[index] = min(tree[2*index] , tree[2*index + 1]);

}
int main(){
    
    int n = 5;
    int a[n] = {1,5,-3,6};

    int tree[4*n + 1] ;
    build_tree(tree , a ,0 , n-1 , 1);

    int q;
    cin>>q;

    while(q--){

        int l,r;
        cin>>l>>r;

        int inc;
        cin>>inc;

        lazy_propagation(tree , 0 , n-1 , 1 , l , r , inc);
        cout<<query(tree , 0 , n-1 , 1 , l , r );

    }

    return 0;
}