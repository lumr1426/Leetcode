class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> stack;
        string ans;
        
        if(s.size()==1)
        {return "";}
        
        stack.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='(')
            {
               if(!stack.empty())
               {
                   ans.push_back(s[i]);
               }
               stack.push_back(s[i]); 
            }
            else
            {
                if(!(stack.size()==1))
                {
                    ans.push_back(s[i]);
                }
                stack.pop_back();
            }
        }
        
        return ans;
    }
};
