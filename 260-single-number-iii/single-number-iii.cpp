class Solution {
public:
    using lli = long long int;
    vector<int> singleNumber(vector<int>& nums) {
        lli x = 0;
        for(int it: nums) x ^= it;
        lli rightMostSetBit = x & (-x);
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightMostSetBit){
                a ^= nums[i];
            }else{
                b ^= nums[i];
            }
        }
        return {a, b};
    }
};