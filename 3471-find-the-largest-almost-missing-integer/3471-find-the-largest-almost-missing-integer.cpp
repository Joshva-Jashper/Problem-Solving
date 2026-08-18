class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int len = nums.size();

        map<int,int> mpp;
        int max_n=0;


        for (auto it:nums)
        {
            mpp[it]++;
            max_n = max(max_n,it);
        }
        int maxi =-1;

        if (k==1)
        {
            for (auto [x,y]: mpp)
            {
                if (y==1) maxi = max(maxi,x);
            }
            return maxi;
        }

        else if (k==len)
        {
            return max_n;
        }

        else
        {
            int ans =-1;
            if (mpp[nums[0]] == 1)
            {
                ans = max(ans,nums[0]);
            }    
            
            if (mpp[nums[len-1]]==1)
            {
                ans = max(ans,nums[len-1]);
            }
            return ans;
        }

    }
};