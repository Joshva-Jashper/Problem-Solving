class Solution {
public:
    void find(vector<string>& res, int n, int open, int close, string curr) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            find(res, n, open + 1, close, curr + '(');
        }
        if (close < open) {
            find(res, n, open, close + 1, curr + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        find(res, n, 0, 0, "");
        return res;
    }
};