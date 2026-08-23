class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left_sum = 0, right_sum = 0;
        int left_q = 0, right_q = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') left_q++;
            else left_sum += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') right_q++;
            else right_sum += num[i] - '0';
        }

        int delta_q = left_q - right_q;
        int delta_s = right_sum - left_sum; 
        if (delta_q % 2 != 0) return true;
        return delta_s != (delta_q / 2) * 9;
    }
};