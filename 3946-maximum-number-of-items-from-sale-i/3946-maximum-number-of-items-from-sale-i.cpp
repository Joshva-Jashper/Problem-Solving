class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        for (auto& x : items) {
            minPrice = min(minPrice, x[1]);
        }

        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int freeItems = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeItems++;
                }
            }

            int cost = items[i][1];
            int gain = 1 + freeItems;

            for (int b = budget; b >= cost; b--) {
                if (dp[b - cost] != -1e9) {
                    dp[b] = max(dp[b], dp[b - cost] + gain);
                }
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            if (dp[b] != -1e9) {
                ans = max(ans, dp[b] + (budget - b) / minPrice);
            }
        }

        return ans;
    }
};