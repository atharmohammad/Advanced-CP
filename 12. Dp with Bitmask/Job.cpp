/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mat[25][25];
int dp[25][(1<<21)];
int solve(int i , int mask , int n){

    if(i == n)
        return 0;

    if(dp[i][mask] != -1)
        return dp[i][mask];

    int res = INT_MAX;
    for(int person = 0; person<n ; person++){   //We are traversing on every person and seeing if he had been appointed a certain job or not
        if(mask&(1<<person)){//if a person has been appointed a job , means its bit must be 0 and if it is 1 we will appoint him current job
            int x = mat[person][i] + solve(i+1 , (mask^(1<<person)) , n);// and we see which person when appoint current job i will give us the minimum ans
            res = min(res,x);   
        }
    }


    return dp[i][mask] = res;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    memset(dp , -1 , sizeof(dp));

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++)
            cin>>mat[i][j];
    }

    cout<<solve(0 , (1<<n) - 1 , n);


    return 0;
}