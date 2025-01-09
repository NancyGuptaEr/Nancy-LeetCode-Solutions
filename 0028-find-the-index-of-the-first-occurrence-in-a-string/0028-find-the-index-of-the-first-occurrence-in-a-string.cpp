// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         //TC = O(n), SC = O(1)
//         int n = haystack.length();
//         int m = needle.length();
        
//         if (m == 0) return 0;  // If needle is an empty string, return 0
//         if (n < m) return -1;   // If haystack is shorter than needle, return -1

//         for (int i = 0; i <= n - m; i++) {
//             if (haystack.substr(i, m) == needle) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) return 0;  // If needle is empty, return 0

        // Step 1: Build the prefix table for the needle
        vector<int> lps(m, 0);  // Longest Prefix Suffix
        int j = 0;  // Length of the previous longest prefix suffix
        for (int i = 1; i < m; i++) {
            if (needle[i] == needle[j]) {
                j++;
                lps[i] = j;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                    i--;  // Decrease i to recheck the current character
                } else {
                    lps[i] = 0;
                }
            }
        }

        // Step 2: Perform the KMP search
        j = 0;  // Index in needle
        for (int i = 0; i < n; i++) {
            if (haystack[i] == needle[j]) {
                j++;
                if (j == m) {
                    return i - m + 1;  // Found needle, return starting index
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                    i--;  // Decrease i to recheck the current character
                }
            }
        }

        return -1;  // Needle not found in haystack
    }
};


// Start searching from the end of haystack (i = n - m)
//         for (int i = n - m; i >= 0; i--) {
//             if (haystack.substr(i, m) == needle) {
//                 return i;
//             }
//         }