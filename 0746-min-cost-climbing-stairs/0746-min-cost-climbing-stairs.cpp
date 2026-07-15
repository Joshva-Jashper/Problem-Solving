class Solution {
public:

    auto findWays(auto idx,auto n,vector<int>& dp,vector<int>& arr)
    {
        if(idx >= n)
            return 0;

        if(dp[idx]!=-1)
            return dp[idx];

        
        return dp[idx] = min(arr[idx]+findWays(idx+1,n,dp,arr),
                            arr[idx]+findWays(idx+2,n,dp,arr));
                 
    }



    int minCostClimbingStairs(vector<int>& cost) {
        auto n = cost.size();

        vector<int>dp(n,-1);

        return  min(findWays(0,n,dp,cost),findWays(1,n,dp,cost));
    }
};