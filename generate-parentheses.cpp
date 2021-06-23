//https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    
    //checks if generated 2*n length sequence is valid or not
    int checkIfValid(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push('(');
            else if(st.empty())
                return 0;
            else
                st.pop();   
        }
        if(!st.empty())
            return 0;

        return 1;    
    }
    
    
    void solve(string currStr ,  int n , vector<string> &res){
        
        if(currStr.size()==(n*2)){
            if(checkIfValid(currStr))
                res.push_back(currStr);
            return;
        }
        
        //At position i  try to keep '('  and ')'
        solve(currStr+'(',n,res);
        solve(currStr+')',n,res);
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string currStr="";
        solve(currStr,n,res);
        return res;
    }
};
