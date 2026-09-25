class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int p : prices) {
            if (p < min1) {
                min2 = min1;
                min1 = p;
            } else if (p < min2) {
                min2 = p;
            }
        }

        int min_cost = min1 + min2;

        if (money >= min_cost) {
            return money - min_cost;
        }

        return money;
    }
};