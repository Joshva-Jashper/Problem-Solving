class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, {-1, 0}));
        dp[n - 1][m - 1] = {0, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if ((i == n - 1 && j == m - 1) || board[i][j] == 'X') {
                    continue;
                }

                int current_val = (isdigit(board[i][j])) ? (board[i][j] - '0') : 0;
                pair<int, int> options[] = {dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]};

                int max_score = -1;
                int path_count = 0;

                for (auto& option : options) {
                    int next_score = option.first;
                    int next_paths = option.second;

                    if (next_score != -1) {
                        if (next_score > max_score) {
                            max_score = next_score;
                            path_count = next_paths;
                        } else if (next_score == max_score) {
                            path_count = (path_count + next_paths) % MOD;
                        }
                    }
                }

                if (max_score != -1) {
                    dp[i][j] = {max_score + current_val, path_count};
                }
            }
        }

        pair<int, int> result = dp[0][0];
        if (result.first == -1) {
            return {0, 0};
        }
        return {result.first, result.second};
    }
};