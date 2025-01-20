class Solution {
public:
    void buildAns(stack<string> &s, string &ans)    {
        //this is basically used since the string is in stack, we need to pop all and put back in string
        // TC = O(n) and SC = O(n)
        if(s.empty())   {
            return;
        }
        string minPath = s.top();
        s.pop();
        //recursive call
        buildAns(s, ans);
        ans += minPath;
    }
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;
        while(i < path.size())  {
            int start = i;
            int end = i+1;
            while(end < path.size() && path[end] != '/')    {
                end++;
            }
            string minPath = path.substr(start, end-start);
            i = end;
            if(minPath == "/" || minPath == "/.")   {
                continue;   //do next iteration and skip everything below
            }
            if(minPath != "/..")    {
                s.push(minPath);
            }
            else if(!s.empty()) {
                s.pop();
            }
        }

        string ans = s.empty()? "/" : "";
        buildAns(s, ans);
        return ans;
    }
};