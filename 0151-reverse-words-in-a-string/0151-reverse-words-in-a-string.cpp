class Solution {
public:
    string reverseWords(string s) {
        //TC = O(n), SC = O(n)
        stack<string> st;
        stringstream ss(s);
        string word;
        
        // Use stringstream to split the string by spaces and push words onto the stack
        while (ss >> word) {
            st.push(word);
        }
        
        string result;
        // Pop words from the stack to form the result string
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) {
                result += " ";
            }
        }
        
        return result;
    }
};

// class Solution {
// public:
//     string reverseWords(string s) {
//         //TC = O(n), SC = O(n)
//         stack <string> st;
//         int j = 0;

//         while(j < s.size()) {
//             if(s[j] == ' ')  {
//                 j++;
//                 continue;
//             }
//             int i = j;
//             string temp = "";
//             while(s[i] != ' ' && i<s.size()) {
//                 temp = temp + s[i];
//                 i++;
//             }
//             st.push(temp);
//             j = i;
//         }
//         //now reverse the string and pop elements from stack
//         string result = st.top();
//         st.pop();
//         while(!st.empty())  {
//             result = result + " " + st.top();
//             st.pop();
//         }
//         return result;
//     }
// };