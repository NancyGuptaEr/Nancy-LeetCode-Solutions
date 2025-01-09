class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //TC = O(n), SC = O(1)
        string ans = "";
        sort(strs.begin(), strs.end()); //sort lexicographically
        //in this way, first and last words will have most and least common words
        string first = strs[0], last = strs[strs.size()-1];

        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};
