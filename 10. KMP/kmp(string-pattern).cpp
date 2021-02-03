/* Author : Mohd Athar */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void compute_lps(string p , int lps[]){

    int i = 1;
    int len = 0;

    lps[0] = 0; // LPS of 0 is always 0 as we are considering only proper prefix and suffix.

    while(i < p.size()){

        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }

    }

}
void KMP(string s , string p , vector<int>&v){

    int lps[p.size()] = {0};

    compute_lps( p , lps);

    int i = 0; //for string 
    int j = 0;  //for pattern;

    while(i < s.size()){

        if(p[j] == s[i]){
            i++;
            j++;

        }
        
        if(j == p.size()){
            v.push_back(i-j);
            j = 0;
        }
        else if(i < s.size() && p[j] != s[i]){

            if(j == 0)  // as not even starting character matched so we increment i
                i++;
            else
                j = lps[j-1];

        }   

    }


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s = "AABAEAAB"; // string 
    string p = "AAB";   //pattern to be found

    vector<int>v;
    KMP(s , p , v);

    cout<<v.size();

    return 0;
}