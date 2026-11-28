class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
          int mx = 0;

        for (auto& item : items) {
            mx = max(mx, item[0]);
        }

        vector<int> freq(mx + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        for (int i = 1; i <= mx; i++) {
            for (int j = i * 2; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long minPrice = items[0][1];
        long long remaining = budget;
        long long ans = 0;

        for (auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            if (price >= 2 * minPrice) {
                break;
            }

            int freeCount = freq[factor] - 1;

            long long take = min(
                (long long)freeCount,
                remaining / price
            );

            ans += take * 2;
            remaining -= take * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    
    }
};