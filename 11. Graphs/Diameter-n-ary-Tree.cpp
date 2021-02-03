/*
LOGIC : first find the node which is farthest from the root, And now from this node we find which node is farthest 
and returns the diameter , Even if graph is directed Make it undirected.
*/
/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int diameter[200001];
int bfs(map<int,vector<int>>&adj , int n , int node){
    memset(diameter , 0 ,sizeof(diameter));
    int visited[n+1] = {0};

    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        for(auto temp : adj[element]){
            if(visited[temp])
                continue;


            diameter[temp] = diameter[element] + 1;
            visited[temp] = 1;
            q.push(temp);

        }
    }
    int res = -1 , x;
    for(int i = 1;  i<=n ; i++){
        if(diameter[i] > res){
            x = i;
            res = diameter[i];
        }
    }

    return x;


}
int FindDiameter(map<int,vector<int>>&adj , int n , int src){
    int start = bfs(adj , n , src);
    int end = bfs(adj , n , start);

    return diameter[end];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodes;
    cin>>nodes;

    map<int,vector<int>>adj;

    for(int i = 0 ; i<nodes-1; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src = 1; //Here we are taking src as 1 , 

    int d = FindDiameter(adj , nodes , src);
    cout<<d<<"\n";

    return 0;
}