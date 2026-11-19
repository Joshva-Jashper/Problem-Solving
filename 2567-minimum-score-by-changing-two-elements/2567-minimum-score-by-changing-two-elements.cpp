class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int drop_two_min = nums[n - 1] - nums[2];
        int drop_both_ends = nums[n - 2] - nums[1];
        int drop_two_max = nums[n - 3] - nums[0];

        return min({drop_two_min, drop_both_ends, drop_two_max});
    }
};