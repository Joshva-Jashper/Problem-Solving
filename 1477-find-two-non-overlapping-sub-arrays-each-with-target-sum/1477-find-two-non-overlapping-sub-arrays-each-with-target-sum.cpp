class Solution {
public:
    int minSumOfLengths(vector<int>& A, int k) {
        int n = A.size();
        int res = n + 1;
        int tot = 0;
        int i = 0;

        std::vector<int> dp(n + 1, n + 1);

        for (int j = 0; j < n; ++j) {
            tot += A[j];

            while (tot > k) {
                tot -= A[i];
                i++;
            }

            dp[j + 1] = dp[j];

            if (tot == k) {
                int currentLen = j - i + 1;
                res = std::min(res, currentLen + dp[i]);
                dp[j + 1] = std::min(dp[j], currentLen);
            }
        }

        return res > n ? -1 : res;
    }
};