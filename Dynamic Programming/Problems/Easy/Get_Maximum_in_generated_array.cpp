/*
You are given an integer n. A 0-indexed integer array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n

url :- https://leetcode.com/problems/get-maximum-in-generated-array/
*/


#include<bits/stdc++.h>
using namespace std;

int getMaximumGenerated(int n) {
    if(n < 2) return n;
    int nums[n+1];
    nums[0] = 0;
    nums[1] = 1;
    int max_ans = INT_MIN;
    for(int i = 2; i <= n; i++){
        if(i % 2 == 0){
            nums[i] = nums[i/2];
        }
        else{
            nums[i] = nums[(i - 1)/2] + nums[(i + 1) / 2];
        }
        max_ans = max(max_ans, nums[i]);
    }
    return max_ans;
}

int main(){
    int n;
    cout << "Enter the integer: ";
    cin >> n;
    cout << "The result is: " << getMaximumGenerated(n); 
}