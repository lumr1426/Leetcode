class Solution {
public:
    int maxDepth(string s) {
        vector<char> stack;
        int result=0;
        int count=0;
        int maxval=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stack.push_back('(');
                count++;
                if(maxval<count)
                {
                    maxval=count;
                }
            }
            else if(s[i]==')')
            {
                stack.pop_back();
                count--;
                if(stack.empty())
                {
                    if(result<maxval)
                    {
                        result=maxval;
                    }
                    count=0;
                    maxval=0;
                }
            }
        }
        return result;
    }
};
