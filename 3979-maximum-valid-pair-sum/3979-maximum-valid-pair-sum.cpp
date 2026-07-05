class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int j = k;
        int maxi =0;
        int max_seen=0;

        while( j < n)
        {
            int i = j-k;
            maxi = max(maxi,nums[i]);
            max_seen = max(max_seen,maxi+nums[j]);
            j+=1;
        }
        return max_seen;

    }
};