class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> minOps = getMinOps(nums, x);
        vector<vector<long long>> memo(n + 1, vector<long long>(k + 1, -1));
        return dp(0, k, x, minOps, memo);
    }

private:
    const long long INF = 1e15;

    vector<long long> getMinOps(const vector<int>& nums, int x) {
        vector<long long> minOps;
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            if (i >= x) {
                int outNum = nums[i - x];
                auto it = lower.find(outNum);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }

            if (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            } else if (lower.size() - upper.size() > 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }

            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lowerSum) +
                                (upperSum - median * upper.size());
                minOps.push_back(ops);
            }
        }
        return minOps;
    }

    long long dp(int i, int remainK, int x, const vector<long long>& minOps,
                 vector<vector<long long>>& memo) {
        if (remainK == 0)
            return 0;
        if (i + (long long)remainK * x > minOps.size() + x - 1)
            return INF;
        if (memo[i][remainK] != -1)
            return memo[i][remainK];

        long long skip = dp(i + 1, remainK, x, minOps, memo);

        long long pick = INF;
        if (i + x - 1 < minOps.size() + x - 1) {
            pick = minOps[i] + dp(i + x, remainK - 1, x, minOps, memo);
        }

        return memo[i][remainK] = min(skip, pick);
    }
};