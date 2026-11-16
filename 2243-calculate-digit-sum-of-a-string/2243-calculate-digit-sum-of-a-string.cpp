class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string reserve = "";

            int j = 0;

            while (j < s.size()) {
                int total = 0;
                int count = 0;

                while (j < s.size() && count < k) {
                    total += s[j] - '0';
                    j++;
                    count++;
                }

                reserve += to_string(total);
            }

            s = reserve;
        }

        return s;
    }
};