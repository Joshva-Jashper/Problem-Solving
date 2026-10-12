class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        std::vector<int> bitCount(30, 0);

        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        long long totalSum = 0;

        for (int i = 0; i < k; ++i) {
            long long currentVal = 0;
            for (int bit = 0; bit < 30; ++bit) {
                if (bitCount[bit] > 0) {
                    currentVal |= (1LL << bit);
                    bitCount[bit]--;
                }
            }
            totalSum =
                (totalSum + (currentVal % MOD) * (currentVal % MOD)) % MOD;
        }

        return totalSum;
    }
};