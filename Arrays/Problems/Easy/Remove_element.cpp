//Leetcode question 
//25. Remove Element

#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for(int i = 0; i< nums.size(); i++){
        if(nums[i] != val){
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

int main(){
    int n, val;
    cout << "Enter the size of array and value: ";
    cin >> n >> val;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << removeElement(nums, val);

}
