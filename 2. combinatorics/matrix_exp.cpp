#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000
#define ll unsigned long long 
vector<ll int>a,b,c;
ll int k;

vector<vector<ll int >> multiply(vector<vector<ll int >> A , vector<vector<ll int >> B){    // we take two matrices 
    // matices multiplicatiion

    vector<vector<ll int >> C (k+1 , vector<ll int >(k+1));  // for extra space here we take matrix C to store matrix mul. result
    for(int i = 1 ; i<=k ; i++){    // i travese on rows of A as we do in Matrix Mul
        for(int j = 1;  j<=k ; j++){    // j traverse on columns of B as we multiply every row of A with every column
            for(int x = 1 ; x<=k ; x++){    // x traverse on elements of A and B
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;  /*As we take sum after multiplying each element of row with 
                                                                           column element of B as we do in matrix multiplication                                             */
            }
        }
    }    

        // Time colmplexity : K^3 


    return C;


}


vector<vector<ll int >> power(vector<vector<ll int >> A , ll int n){   // same as fast power just for matrices with some changes TC: O(log n)

    if(n == 1)  // here if n == 1 we just return Matrix
        return  A;


   if(n&1){                                     // Now if n is odd
        return multiply(A , power(A , n-1));    // we return multiplication of matrices A ans A^n-1 //doubt 
    }

    vector<vector<ll int >> X = power( A , n/2); // Now if n is even , We take power of A as n/2;

    return multiply(X , X);  // here we return A^n/2 * A^n/2

}

ll int compute(ll int n){

    if(n == 0){
        return 0;       //  zeroth element in sequence is 0
    }

    if(n <= k){
        return b[n-1];      // if the nth number is smaller than k  // doubt
    }

    // Matrix exponentiation is start from here

    vector<ll int > F(k+1);  // indexing is done from 1

    // first step is to take first k elements that are given

    for(ll int i = 1 ; i<=k ; i++){
        F[i] = b[i-1];
    }

    // second step is to make a transformation matrix
    vector<vector<ll int >>T(k+1 , vector<ll int>(k + 1)) ;  // tranformation matrix T

    for(int i = 1 ; i<=k ; i++){
        for(int j = 1 ; j<=k ; j++){

            if(i<k){   // i is taken less than k as we have to fill  last row with coefficients

                if(j == i+1)      //here j == i+1 taken so just to fill diagonals 
                    T[i][j] = 1;    // here we are making identity matrix which is shifted by one row and one column shown in notes
                else
                    T[i][j] = 0;

            }
            else{
                T[i][j] = c[k - j]; // here we are filling coefficients in reverse order in trans. matrix
            }
        }
    }

    // 3rd step is to compute T raised to power n-1 for T^n-1 * F1 = Fn

    T = power(T , n-1); // here we get Trans. Matrix

    // Now 4step is to just multiply transformation matrix with first k elements 
    ll int sum = 0;
    for(int i=1 ; i<=k ; i++){

        sum = ((sum) + (T[1][i] * F[i])%MOD )%MOD ;  // here we just multiplied our first row with 1st k elements as we just needed that to get our nth element

    }

    return sum;

}

int main(){
    
    ll int t,n,num;
    cin>>t;

    while(t--){

        cin>>k;

        for(int i = 0 ; i<k ; i++){ // input starting k elements of sequences 
            cin>>num;
            b.push_back(num);
        }

        for(int i = 0 ; i<k ; i++){     // input k coefficents
            cin>>num;
            c.push_back(num);
        }

        cin>>n;
        cout<<compute(n)%MOD<<endl;

        b.clear();      // clear the matrices as they are defined globally to use them in other test cases
        c.clear();

    }

}