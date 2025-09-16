/**
 * Problem Statement: Given a set of N numbers, find the smallest number that 
 * you can not create as a sum of some subset of the given numbers.
 * 
 * Example 
 * N = 5
 * Input: {1, 2, 1, 7, 6}
 * Output: 5
 * 
 * Explanation: All subset sums are
 * 1, 2, 6, 7, 3, 8, 9, 13, 4, 10, 11, 14, 15, 16, 17
 * so the answer is 5 which can't be created
 * 
 */


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solution(vector<int>& arr, int n){
        int ans = 1;
        // Sorting the array
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i++){
            if(arr[i] > ans){
                break;
            }
            ans += arr[i];
        }

        cout << "The smallest number that cannot be formed is: " << ans << endl;
        return;
    }
};

int main(){
    int n;
    vector<int> array;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    Solution s;
    s.solution(array, n);
    return 0;
}


/**
 * 
 * Let's talk about ideas
 * By sorting the array, you always consider the smallest numbers first.
 * Starting with ans = 1, you check if you can form every number up to ans - 1 using the subset sums so far.
 * If the next number in the array is greater than ans, you cannot form ans with any subset (since all previous numbers are too small).
 * If the next number is less than or equal to ans, you can now form all sums up to ans + arr[i] - 1.
 * This process continues until you find a gap, which is the smallest number you cannot form.
 * 
 * 1, 1, 2, 6, 7 
 * 
 * with this the sums which can be found
 * 
 * ans = 1(initially)
 * arr[0] = 1 -> ans = 2 (so 1, 2)
 * arr[1] = 1 -> ans = 3 (so 1, 2, 3)
 * arr[2] = 2 -> ans = 5 (so 1, 2, 3, 4, 5)
 * arr[3] = 6 -> break (as 6 > 5)
 */