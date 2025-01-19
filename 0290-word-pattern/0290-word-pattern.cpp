class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //TC = O(n), SC = O(n+m)
        if (pattern.empty() && s.empty()) {
            return true;
        }
        if (pattern.empty() || s.empty()) {
            return false;
        }
        stringstream ss(s);
        string word;
        unordered_map<string, char> mp1;
        unordered_map<char, char> mp2;
        string s1, s2;
        char i = 'a';

        while(ss >> word)   {
            if(mp1.find(word) == mp1.end())
                mp1[word] = i++;
            s1.push_back(mp1[word]);
        }
        i = 'a';
        for(auto &it:pattern)   {
            if(mp2.find(it) == mp2.end())
                mp2[it] = i++;
            s2.push_back(mp2[it]);
        }
        if (s1.length() != pattern.length()) {
            return false;
        }
        if(s1 != s2)
            return false;
        return true;
    }
};