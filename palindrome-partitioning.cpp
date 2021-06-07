//https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    
    
    int isPalindrome(string s , int left , int right){
        while(left<=right){
            if(s[left++]!=s[right--])
                return 0;
        }
        return 1;
    }
    
    void partitionHelper(string s, int index,vector<vector<string>> &allPartitionsList,vector<string> &currentPartition){
        
        if(index==s.size()){
            allPartitionsList.push_back(currentPartition);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                currentPartition.push_back(s.substr(index,i+1-index));
                partitionHelper(s,i+1,allPartitionsList,currentPartition);
                currentPartition.pop_back();    
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allPartitionsList;
        vector<string> currentPartition;
        partitionHelper(s,0,allPartitionsList,currentPartition);
        
        return  allPartitionsList;
    }
};

/*


   aab
   
   aa b
   
   a a b
   

*/
