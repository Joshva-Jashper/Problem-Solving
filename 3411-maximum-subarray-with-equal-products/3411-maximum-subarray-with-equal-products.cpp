class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {
                long long x = nums[j];

                g = gcd(g, x);
                l = lcm(l, x);

                __int128 next = (__int128)prod * x;
                __int128 target = (__int128)g * l;

                if (next == target) {
                    ans = max(ans, j - i + 1);
                }

                if (next > target) {
                    break;
                }

                prod = next;
            }
        }

        return ans;
    }
};