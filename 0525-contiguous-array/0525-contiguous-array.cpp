class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;

        int curr =0;
        int ans  = 0;

        for (int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                curr+=1;
            }
            else
                curr-=1;

            if(curr == 0)
            {
                ans = max(ans,i+1);
            }   
            if(mpp.find(curr)!=mpp.end())
            {
                int rem = mpp[curr];
                ans = max(ans,i-rem);
            }
            else
            {
                mpp[curr]=i;
            }
        }
        return ans;
    }
};