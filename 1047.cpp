class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;
        char top;
        string result;
        for(int i=0;i<s.length();i++)
        {
            if(!stack.empty())
            {
                top=stack.back();
                stack.push_back(s[i]);
                if(top==stack.back())
                {
                    stack.pop_back();
                    stack.pop_back();
                }
            }
            else
            {
                stack.push_back(s[i]);
            }
        }
        for(int i=0;i<stack.size();i++)
        {
            result.push_back(stack[i]);
        }
        return result;
    }
};
