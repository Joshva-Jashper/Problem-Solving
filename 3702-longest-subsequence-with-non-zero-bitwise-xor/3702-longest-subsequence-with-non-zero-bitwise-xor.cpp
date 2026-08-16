class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int found =0;

        for (auto i: nums)
        {
            if(i!=0)
                found =1;
        }
        if (found ==0)
            return 0;
            
        int sum = 0;
        for (int i=0;i<n;i++)
        {
            sum^=nums[i];
        }
        if(sum==0)
        {
            return n-1;
        }
        else
            return n;
    }
};