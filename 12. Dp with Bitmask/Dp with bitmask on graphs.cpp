class Solution {
int64_t dp[20][(1<<13)];
    
   int64_t fact(int64_t x){
       int64_t mul = 1;
       for(int i = 1; i<=x ; i++)
           mul *= i;
       
       
       return mul;
   }
   int64_t dfs(int i , map<int,vector<int>>&adj , int n , int mask){
       if(mask == (1<<n) - 1)
           return 1;
       
       if(dp[i][mask] != -1)
           return dp[i][mask];
    
       int ans = 0;
       for(auto temp : adj[i]){
           if(((mask>>temp)&1 )== 0)
             ans += dfs(temp , adj , n , mask|(1<<temp));
       }
       
       return dp[i][mask] = ans;
   }
public:
    int numSquarefulPerms(vector<int>& A) {
        
        int n = A.size();
        map<int,vector<int>>adj;
        memset(dp , -1 , sizeof(dp));
        
        for(int i = 0 ;i<n ; i++){
           for(int j = 0; j<n ; j++){
               if(j == i)
                   continue;
               
               int64_t x = A[i]+A[j];
               int64_t sq = sqrt(x);
               if(sq*sq == x){
                   adj[i].push_back(j);
               }              
           }
        }
        
        int res = 0;
        for(int i = 0 ; i<n ; i++){
            res += dfs(i , adj , n , (1<<i));
        }
        
        int64_t count = 1;
        
        sort(A.begin() , A.end());
        vector<int64_t>v;
        for(int i = 1 ; i<n ; i++){
            if(A[i] == A[i-1]){
                count++;
            }
            else{
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);
        
        for(auto temp : v)
            res /= fact(temp);
        
        return res;
    }
};