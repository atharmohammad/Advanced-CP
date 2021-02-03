/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void update(int * tree , int index , int qs, int s , int e){
    if(qs < s || qs > e)
        return ;

    if(s == e){
        tree[index] = 1;
        return;
    }

    int mid = (s+e)/2;
    update(tree , 2*index , qs , s , mid);
    update(tree ,2*index+1 , qs , mid+1 , e);

    tree[index] = tree[2*index] + tree[2*index + 1];
}
int seg(int *tree ,int index, int qs , int qe , int s , int e){

    if(qs > e || qe < s)
        return 0;

    if(qs <= s && qe >= e)
        return tree[index];

    int mid = (s+e)/2;

    int left = seg(tree ,2*index, qs ,qe , s , mid);
    int right = seg(tree ,2*index+1, qs , qe , mid+1 , e);

    return(left + right);
}
int sum(int *tree,int qs , int qe , int s , int e){
    int d = seg(tree,1, qs , qe , s, e);
    update(tree ,1 , qs, s , e);
    return d;
}
int main(){
    
    int n;
    cin>>n;

    int a[2*n];
    for(int i = 0 ; i<2*n ; i++)
        cin>>a[i];

    int tree[4*(2*n + 1)] = {0};

    int res[n+1];   // Approach : see what we do is we call for element to tell 
    int filled[2*n + 1];// how many segments are nested only when its right occurence come so 
    memset(filled , -1 , sizeof(filled));// untill some element's last occurence didnt come we can calculate how many segments has already came
    for(int i = 0 ; i<2*n ; i++){   //and when we calculate for a segment count of nested segments we will mark that segment's left occurence as 1 and calculate sum on seg tree
        if(filled[a[i]] == -1){ //now seg tree will count for only those segment's whose left and right occurence lies in that range
            filled[a[i]] = i;// and as we put 1 on some element's left occurence only when its right occurence is visited
        }   // so see even if some elements left occurence is lying in segment but not right occurence that segment will not be counted as 1 is not being put at that left occurence since its right occurence still not came
        else{// and if right occurence is lying but not left in that case this segment will not be counted as we had put 1 in left occurence and that is not lying in the segmenet
            res[a[i]]=sum(tree, filled[a[i]] , i , 0 , (2*n)-1 );
        }
    }

    for(int i = 1 ; i<=n ; i++)
        cout<<res[i]<<" ";

    cout<<endl;

    return 0;
}