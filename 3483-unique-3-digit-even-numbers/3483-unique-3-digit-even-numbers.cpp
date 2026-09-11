void find_(vector<int>& ds, unordered_set<int>& res, vector<int>& digits,
           vector<int>& visited) {
    if (ds.size() == 3) {
     
        if (ds[2] % 2 == 0) {
            int num = ds[0] * 100 + ds[1] * 10 + ds[2];
            res.insert(num); 
        }
        return;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (visited[i] == 1)
            continue;

        if (ds.empty() && digits[i] == 0)
            continue;

        visited[i] = 1;
        ds.push_back(digits[i]);

        find_(ds, res, digits, visited);

        ds.pop_back();
        visited[i] = 0;
    }
}

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> ds;
        unordered_set<int> res;
        vector<int> visited(digits.size(), 0);

        find_(ds, res, digits, visited);

        return res.size();
    }
};