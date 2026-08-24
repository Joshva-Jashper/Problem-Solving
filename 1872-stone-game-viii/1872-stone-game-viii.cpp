class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        int best = stones.back();
        for (int i = n - 2; i > 0; --i) {
            best = std::max(best, stones[i] - best);
        }
        return best;
    }
};