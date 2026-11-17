class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();

        auto get_cost = [&](int l, int r) {
            int len = r - l + 1;
            int min_changes = 1e9;
            for (int d = 1; d < len; ++d) {
                if (len % d != 0)
                    continue;
                int current_cost = 0;
                for (int i = 0; i < d; ++i) {
                    int left = l + i;
                    int right = r - d + 1 + i;
                    while (left < right) {
                        if (s[left] != s[right]) {
                            current_cost++;
                        }
                        left += d;
                        right -= d;
                    }
                }
                min_changes = std::min(min_changes, current_cost);
            }
            return min_changes;
        };

        std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                cost[i][j] = get_cost(i, j);
            }
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 1e9));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = j - 1; h < i; ++h) {
                    if (dp[h][j - 1] != 1e9) {
                        dp[i][j] =
                            std::min(dp[i][j], dp[h][j - 1] + cost[h][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};