class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3) return -1;
        sort(nums.begin(), nums.end());
        int res1 = nums[0] * nums[1] * nums[nums.size() - 1];
        int res = nums[nums.size() - 1] * nums[nums.size() - 2] *nums[nums.size() - 3];
        return max(res1, res);
    }
};