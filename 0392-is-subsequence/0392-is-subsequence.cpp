class Solution {
public:
    bool isSubsequence(string s, string t) {
        //TC = O(m), SC = O(1)
        int n = s.length();
        int m = t.length();
        int i = 0;
        for(int j = 0; j < m && i < n; j++) {
            if(s[i] == t[j])    {
                i++;
            }
        }
        return (i == n);
    }
};