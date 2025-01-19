class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //TC = O(n), SC = O(1)
        vector<int> indexS(200,0);
        vector<int> indexT(200,0);
        int n = s.length();
        if(n != t.length())   {
            return false;
        }
        for(int i = 0; i < n; i++)    {
            if(indexS[s[i]] != indexT[t[i]])    {
                return false;
            }
            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
        return true;
    }
};