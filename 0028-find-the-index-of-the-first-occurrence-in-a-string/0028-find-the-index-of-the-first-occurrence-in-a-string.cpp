class Solution {
public:
    int strStr(string haystack, string needle) {
        //TC = O(n), SC = O(1)
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) return 0;  // If needle is an empty string, return 0
        if (n < m) return -1;   // If haystack is shorter than needle, return -1

        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }

        return -1;
    }
};

// Start searching from the end of haystack (i = n - m)
//         for (int i = n - m; i >= 0; i--) {
//             if (haystack.substr(i, m) == needle) {
//                 return i;
//             }
//         }