#include<bits/stdc++.h>
using namespace std;


//1st approach
//Recursive approach
//Tc- O(2^n), Sc - O()

int coin_count(vector<int>& coins, int n, int amount){
    if(amount == 0) return 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        if(coins[i] <= amount){
            int get_ans = coin_count(coins, n, amount - coins[i]);
            if(get_ans != -1){
                ans = min(ans, get_ans + 1);
            }
        } 
    }
    return (ans == INT_MAX) ? -1 : ans;
}


//2nd approach
//Dp approach(Tabulation)
//Tc - O(N^2), Sc - O(n)
int coin_count(vector<int>& coins, int n, int amount){
    intdp[amount + 1];
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        dp[i] = INT_MAX;
    }
    for(int i = 1; i <= amount; i++){
        for(int j = 0; j < n; j++){
            if(coins[j] <= i){
                int get_res = dp[i - coins[j]];
                if(get_res != INT_MAX){
                    dp[i] = min(dp[i], get_res + 1);
                }
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}  

int main(){
    int amount, n;
    cout << "Enter the amount and size of coin array: ";
    cin >> amount >> n;
    vector<int> coins(n);
    cout << "Enter the coins: ";
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    cout << "Minimum no of coins required are: "<< coin_count(coins, n, amount);
    return 0;
}