class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();


        int count = 1;  // Initialize count to 1 since a single element is also an increasing subsequence.
        int Max = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                count++;
            } else {
                count = 1;  // Reset count when the sequence breaks.
            }

            Max = max(Max, count);
        }

        return Max;
    }
};
