class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        array<vector<int>, 26> ancestors_by_char;

        auto dfs = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            ancestors_by_char[c].push_back(u);

            for (int v : children[u]) {
                self(self, v);
            }

            ancestors_by_char[c].pop_back();

            int new_parent = !ancestors_by_char[c].empty()
                                 ? ancestors_by_char[c].back()
                                 : parent[u];

            if (new_parent != -1) {
                ans[new_parent] += ans[u];
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};