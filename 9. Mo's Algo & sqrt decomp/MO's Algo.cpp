/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class node{
public:
    int l ;
    int r ;
    int blk_no;
    int q_no;

    bool operator <(node &a){
        if(blk_no < a.blk_no)
            return 1;
        else if(blk_no > a.blk_no)
            return 0;
        else
            return(r < a.r);
    }
};
unordered_map<ll int,int>frq;
int distinct = 0;

void ADD(ll int val){

    if(frq.find(val) == frq.end() || frq[val] == 0){
        frq[val] = 0;
        distinct++;
    }

    frq[val]++;
}

void REMOVE(ll int val){
    frq[val]--;

    if(frq[val] == 0)
        distinct--;
}

void adjust(int& cl , int& cr , node&q , ll int *in){

    while(cl < q.l){
        REMOVE(in[cl]);
        cl++;
    }

    while(cl > q.l){
        cl--;
        ADD(in[cl]);
    }

    while(cr < q.r){
         cr++;
        ADD(in[cr]);
       
    }

    while(cr > q.r){
       
        REMOVE(in[cr]);
         cr--;
    }
}

void query(node * Q , int m , ll int *in , int n){

    sort(Q , Q + m);

    ll int res[m];
    int cl = Q[0].l , cr = Q[0].r; // current left , current right , current sum

    distinct = 0;
    for(int i = Q[0].l ; i<=Q[0].r ; i++){
       ADD(in[i]);
    }

   res[Q[0].q_no] = distinct;

   for(int i = 1 ; i<m ; i++){
      adjust(cl , cr , Q[i] , in);
      res[Q[i].q_no] = distinct;
   }

   for(auto temp : res){
     cout<<temp<<endl;
   }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n ;
    cin>>n;

    ll int in[n];
    for(int i = 0 ; i<n ; i++)
        cin>>in[i];

    int q;
    cin>>q;

    node Q[q];

    int blk_size = sqrt(n);
   for(int j = 0 ; j<q ; j++){
        int a,b;
        cin>>a>>b;

        Q[j].l = a-1;
        Q[j].r = b-1;
        Q[j].blk_no = a/blk_size;
        Q[j].q_no = j;
    }

    query(Q , q , in , n);

    return 0;
}