// Problem link: https://leetcode.com/problems/valid-parentheses/

class Solution 
{
public:
    bool isValid(string parantheses_string) 
    {
        vector<char> open_parantheses;
        
        for(int i = 0; i < parantheses_string.size(); i++)
        {
            if(parantheses_string[i] == '(' || parantheses_string[i] == '{' || parantheses_string[i] == '[')
            {
                open_parantheses.push_back(parantheses_string[i]);
            }
            
            if(parantheses_string[i] == ')')
            {
                if(open_parantheses.size() == 0 || open_parantheses.back() != '(')
                    return false;
                else
                    open_parantheses.pop_back();
            }
           
            if(parantheses_string[i] == '}')
            {
                if(open_parantheses.size() == 0 || open_parantheses.back() != '{')
                    return false;
                else
                    open_parantheses.pop_back();
            }
            
            if(parantheses_string[i] == ']')
            {
                if(open_parantheses.size() == 0 || open_parantheses.back() != '[')
                    return false;
                else
                    open_parantheses.pop_back();
            }
        }
        
        if(open_parantheses.size() == 0)
            return true;
        else
            return false;
    }
};
