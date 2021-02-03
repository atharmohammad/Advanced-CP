/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int sum(int *tree ,int index , int s , int e , int qs , int qe){
    if(qe < s || qs > e)
        return 0;

    if(qs <= s && qe >= e){
        return tree[index];
    }

    int mid = (s+e)/2;
    int left = sum(tree ,2*index, s , mid , qs, qe);
    int right = sum(tree ,2*index +1 , mid + 1 , e , qs , qe);

    return (left + right);
}
void update(int *tree , int index , int s , int e , int qs ){
    if(qs < s || qs > e)
        return ;

    if(s == e){
        tree[index] = 0;
        return;
    }

    int mid = (s+e)/2;
    update(tree , 2*index , s , mid , qs);
    update(tree , 2*index +  1 , mid + 1 , e ,qs);

    tree[index] = tree[2*index] + tree[2*index + 1];
}
void build_tree(int*tree , int index , int s , int e){
    if(s > e)
        return;

    if(s == e){
        tree[index] = 1;
        return;
    }

    int mid = (s+e)/2;
    build_tree(tree , 2*index , s , mid);
    build_tree(tree , 2*index + 1 , mid + 1 , e);

    tree[index] = tree[2*index] + tree[2*index+1];
}
int seg(int*tree , int s , int e , int qs , int qe){
    int d = sum(tree , 1 , s , e, qs , qe);
    update(tree , 1 , s ,e , qs );
    update(tree , 1 , s , e , qe);

    return d-2;
}
int main(){
    
    int n;
    cin>>n;

    int a[2*n];
    for(int i = 0 ; i<2*n ; i++)
        cin>>a[i];

    int tree[8*n + 1];
    memset(tree , 0 ,sizeof(tree)); // Approach : we traverse first from left to right to count intersecting segment
                    // which are of type x z x z means counting z , segments intersecting with right x
    build_tree(tree ,1  ,0 , 2*n-1);// then we traverse in reverse direction , means from right to left and find those segments which 
                            // intersect left side, eg : z x z x 
    int visited[n+1];
    memset(visited , -1 ,sizeof(visited));
    int res[n + 1];                     // what we do is we had put 1 on every node and taken sum
    for(int  i= 0 ; i<2*n ; i++){   // now when an element comnes again we find hoe many segments intersect
        if(visited[a[i]] == -1) // by just printing sum in its range and after that we put 0 on left part
            visited[a[i]] = i;  // as since right x came so means we had already counted those segments 
        else{   // in which left x was occuring but not right x  and we do same in 2nd condition
            res[a[i]] = seg(tree , 0 ,2*n-1 , visited[a[i]] , i);
        }       //and we print counnt - 2 for every segement as in sum we also included x .
    }
    
    memset(visited , -1 ,sizeof(visited));
    build_tree(tree ,1  ,0 , 2*n-1);
    for(int  i= 2*n-1 ; i>=0 ; i--){
        if(visited[a[i]] == -1)
            visited[a[i]] = i;
        else{
            res[a[i]] += seg(tree , 0 ,2*n-1 , i, visited[a[i]]);
        }
    }

    for(int i = 1 ; i<=n ; i++){
        cout<<res[i]<<" ";
    }

    return 0;
}