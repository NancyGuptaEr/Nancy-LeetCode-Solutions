class Solution {
public:
    bool isValid(string s) {
        // TC = O(n) and SC = O(n)
        stack<char> answer;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            //it got opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                answer.push(ch);
            }
            //it got closing bracket
            else{
                if(!answer.empty()) {
                    char top = answer.top();
                    if(ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[')  {
                        answer.pop();
                    }
                    else    {
                        return false;
                    }
                }
                else    {
                    //stack is empty and got closing bracket
                    return false;
                }
            }
        }
        if(answer.empty())
            return true;
        else
            return false;
    }
};