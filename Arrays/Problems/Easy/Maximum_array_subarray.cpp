class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double Average = -1000*k;
        double count(0);

        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (i >= k) count -= nums[i - k];
            if (i+1 >= k) Average = max(count, Average);
        }
        return Average / double(k);
    }
};