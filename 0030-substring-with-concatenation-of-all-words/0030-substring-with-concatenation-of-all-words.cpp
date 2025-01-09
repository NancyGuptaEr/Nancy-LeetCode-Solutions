class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //TC = O(n*m), SC = O(m+n)
        vector<int> result;
        if(s.empty() || words.empty())  {
            return result;
        }
        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        unordered_map<string, int> wordCount;
        for(const string& word: words)   {
            wordCount[word]++;
        }

        for(int start = 0; start < wordLen; start++)    {
            int left = start;
            unordered_map<string, int> currentWordCount;
            int count = 0;

            for (int right = start; right <= (int)s.length() - wordLen; right += wordLen) {
                string word = s.substr(right, wordLen);
                
                if (wordCount.find(word) != wordCount.end()) {
                    currentWordCount[word]++;
                    count++;
                    
                    while (currentWordCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentWordCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    if (count == numWords) {
                        result.push_back(left);
                        currentWordCount[s.substr(left, wordLen)]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    currentWordCount.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return result;
    }
};