#include<bits/stdc++.h>
using namespace std;

//1st recursive approach
//Tc - O(2^n) Sc- O(n)
//NP complete problem
// bool isSubsetSum(int arr[], int n, int sum){
//     if(n == 0) return false;
//     if(sum == 0) return true;
//     if(arr[n - 1] > sum){
//         return isSubsetSum(arr, n - 1, sum);
//     }
//     return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
// }

//2nd approach
//Dp solution
//Memoization approach
//Tc - O(n*sum) Sc- O(sum*n) +O(n)
// int tab[2000][2000];
// int isSubsetSum(int arr[], int n, int sum){
//     if(sum == 0) return 1;
//     if(n <= 0) return 0;
//     if(tab[n - 1][sum] != -1) return tab[n - 1][sum];
//     if(arr[n - 1] > sum)
//         return tab[n -1][sum] = isSubsetSum(arr, n - 1, sum);
//     else{ 
//         return tab[n - 1][sum] = (isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]));
//     }
// }


//3RD APPROACH
//Dp tabulation solution
//Tc - O(sum * n) Sc - O(sum * n)
// bool isSubsetSum(int arr[], int n, int sum){
//     bool subset[n + 1][sum + 1];
//     for(int i = 1; i <= sum; i++){
//         subset[0][i] = false;
//     }
//     for(int i = 0; i <= n; i++){
//         subset[i][0] = true;
//     }

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= sum; j++){
//             if(j < arr[i - 1]){
//                 subset[i][j] = subset[i-1][j];
//             }
//             if(j >= arr[i - 1]){
//                 subset[i][j] = subset[i-1][j] || subset[i-1][j - arr[i - 1]];
//             }
//         }
//     }
//     return subset[n][sum];
// }

//3rd b, space optimization
//sc - O(sum)
bool isSubsetSum(int arr[], int n, int sum){
    vector<bool> subset(sum + 1);
    for(int i = 0; i <= n; i++){
        subset[0] = true;
    }
    for(int i = 1; i <= sum; i++){
        subset[i] = false;
    }
    vector<bool> curr(sum +1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < arr[i - 1]){
                curr[j] = subset[j];
            }
            if(j >= arr[i - 1]){
                curr[j] = subset[j] || subset[j - arr[i - 1]];
            }
        }
        subset = curr;
    }
    return subset[sum];
}



int main(){
    int test;
    cout << "Enter total no of test cases: ";
    cin >> test;
    //for 2nd approach
    //memset(tab, -1, sizeof(tab));
    while(test--){
        int n, sum;
        cout << "Enter the size and sum: ";
        cin >> n >> sum; 
        int arr[n];
        cout << "Enter the elements of the array: ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        if (isSubsetSum(arr, n, sum))
            cout << "Found a subset with given sum" << endl;
        else
            cout << "No subset with given sum" << endl;
    }
    return 0;
}