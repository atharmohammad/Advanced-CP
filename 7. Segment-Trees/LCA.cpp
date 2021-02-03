/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// class tree{
// public:
//     int val;
//     tree *left;
//     tree *right;
//     tree(int data){
//         left = right = NULL;
//         this->val = data;
//     }
// };

// tree* build_bst(tree* root , int * a , int i){
//    if(root == NULL)
//         return new tree(a[i]);

//     if(root->val <= a[i]){
//         root->right = build_bst(root->right , a , i);
//     }
//     else{
//         root->left = build_bst(root->left , a, i);
//     }
    
//     return root;
// }
// tree* insert(int *a , int n){
//      tree*root = new tree(a[0]);

//      for(int i = 1 ; i<n ; i++)
//         root = build_bst(root , a , i);

//     return root;
// }
// void print_bst(tree* root){

//     if(root == NULL)
//         return ;

//     print_bst(root->left);
//     cout<<root->val<<" ";
//     print_bst(root->right);

// }
// pair<int,int>height_diameter(tree* root){
//     if(root == NULL)
//         return {0 , 0};


//     pair<int,int>left = height_diameter(root->left);
//     pair<int,int>right = height_diameter(root->right);

//     int height = 1 + max(left.first , right.first);
//     int diameter = max(left.first , max(left.first + right.first , right.first));

//     return {height , diameter};

// }
int sparse[100][100];
int dfs(int node, int parent ,unordered_map<int,vector<int>>adj  ){

    sparse[node][0] = parent;

    for(auto child : adj[node] ){
        if(child != parent){
            dfs(child, node,adj);
        }
    }
}
void dfs_level(int node,int parent , unordered_map<int,vector<int>>adj , int& count , int x){
    if(node == x){
        return ;
    }
    count++;
    for(auto child : adj[node]){
        if(child != parent){
            dfs_level(child,node,adj,count,x);
        }
    }
}
int lca(int a , int b , unordered_map<int,vector<int>>adj){

  int level_a = 0 , level_b = 0;

  dfs_level(1 , -1 , adj , level_a , a);
  dfs_level(1 , -1 , adj , level_b , b);

   if(level_a > level_b){
        swap(a , b);
   }
   int d = level_b - level_a;
   while(d  > 0){

    int i = log2(d);
    b = sparse[b][i];
    d -= (1<<i);

   }

   if(a == b)
    return a;
    int maxN = log2(8);
    for(int i = maxN; i>=0 ; i--){
        if(sparse[a][i] != -1 && sparse[a][i] != sparse[b][i]){
            a = sparse[a][i];
            b = sparse[b][i];
        }
    }

    return sparse[a][0];

}
void sparse_filling(int n){
    int maxN = log2(n);

    for(int i = 1 ; i<=maxN ; i++){

        for(int j = 0 ; j<n ; j++){
            if(sparse[j][i-1] != -1){
                int parent = sparse[j][i-1];
                sparse[j][i] = sparse[parent][i-1];
            }
        }
    }

}
int main(){
    // int n = 10;
    // int a[n] = {6 , 2 , 4 , 5 , 12 , 5 , 7 , 8 , 10 , 11 };  

    // tree* root =  insert(a , n);

    // print_bst(root);
    // auto temp = height_diameter(root);
    // cout<<endl<<temp.first;
    unordered_map<int,vector<int>>adj;
    int n = 8;
    for(int i = 0 ; i<n ; i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
    }
    memset(sparse , -1 , sizeof(sparse));
    sparse_filling(n);
    dfs(1,-1,adj);
    cout<<lca(5 , 4 , adj);

    return 0;
}