class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int b = target - nums[i];
            if(mp.find(b) != mp.end() && mp[b] != i){
                return {mp[b], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};