class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Approach 1: using hashing
        unordered_map<int, int> cnt;
        for(int num: nums) cnt[num]++;
        for(auto it: cnt){
            if(it.second == 1) return it.first;
        }
        return -1;
    }
};