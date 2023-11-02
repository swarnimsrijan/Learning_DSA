//So the fibonacci number is a sequence 0, 1, 1, 2, 3, 5 .....
//when n = 0 fib(n) = 0,
//When n = 1 fib(n) = 1,
//When n > 1 fib(n) = fib(n-1) +fib(n-2)

#include<bits/stdc++.h>
using namespace std;

//1st approach 
//iterative approach
//Tc - O(n), Sc - (1)
int fib(int n){
    if(n < 0) return -1;
    int curr;
    if(n == 0 || n == 1) return n;
    int val1 = 0;
    int val2 = 1;
    for(int i = 2; i <= n; i++){
        curr = val1 + val2;
        val1 = val2;
        val2 = curr; 
    }
    return curr;
}

//2nd approach
//Recursive approach
//Tc - O(2^n), Sc - O(n)
// int fib(int n){
//     if(n < 0) return -1;
//     if(n == 0 || n == 1) return n;
//     return fib(n-1) + fib(n-2);
// }


//3rd approach
//Dp approach
//Recursive + memoization
//Tc - O(N), Sc - O(N)
int topDown(int n,vector<int>& dp){
    if(n == 1 or n == 0) return n;

    if(dp[n] != -1) return dp[ n];

    dp[n] = topDown(n - 1,dp) + topDown(n - 2,dp);

    return dp[n];
}

int fib(int n){
    vector<int> dp;
    return topDown(n,dp);
}



//4th method
//Dp solution
//Tabulation(bottomup)
//Tc - O(N), Sc - O(N)
int fib(int n) {
    if(n == 0 || n == 1) return n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The fibonacci sum is: " << fib(n); 
}