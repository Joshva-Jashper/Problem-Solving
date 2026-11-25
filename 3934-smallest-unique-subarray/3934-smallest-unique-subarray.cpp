class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE1 = 911382323;
    const ll BASE2 = 972663749;

    vector<ll> h1, h2, p1, p2;

    void preprocess(vector<int>& nums) {
        int n = nums.size();

        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;

            p1[i + 1] = p1[i] * BASE1 % MOD1;
            p2[i + 1] = p2[i] * BASE2 % MOD2;
        }
    }

    ll getHash(int l, int r) {
        ll a = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
        ll b = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;

        return a * MOD2 + b;
    }

    bool check(int len, int n) {
        unordered_map<ll, int> freq;
        freq.reserve(n * 2);

        for (int i = 0; i + len <= n; i++) {
            ll hash = getHash(i, i + len);
            freq[hash]++;
        }

        for (auto& it : freq) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        preprocess(nums);

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};