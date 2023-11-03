#include<bits/stdc++.h>
using namespace std;

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