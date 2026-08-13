class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mpp;
        int left =0;
        int n = nums.size();
        
        int maxi =0;
        for (int i=0;i<n;i++)
        {
            mpp[nums[i]]++;

            while(mpp[nums[i]]>k)
            {
                mpp[nums[left]]--;
                left++;
            }
            maxi = max(maxi,i-left+1);
        }
        return maxi;
    }
};