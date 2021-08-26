 //Verify Preorder Serialization of a Binary Tree
class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        preorder+=',';
        int n = 1;
        string c="";
        for(int i=0;i<preorder.size();i++){
            if(n==0)
                return false;
            if(preorder[i]==','){
                if(c=="#")
                    n--;
                else
                    n++;
                c="";
            }
            else
                c+=preorder[i];
        }
        return n==0;
        
    }
};
