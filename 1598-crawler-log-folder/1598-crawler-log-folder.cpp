class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const string& log : logs) {
            if (log == "../") {
                depth = std::max(0, depth - 1);
            } else if (log == "./") {
                continue;
            } else {
                depth++;
            }
        }
        return depth;
    }
};