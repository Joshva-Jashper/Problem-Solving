class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        array<int, 26> freq{};
        for (char c : magazine) {
            ++freq[c - 'a'];
        }

        for (char c : ransomNote) {
            if (--freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};