//https://leetcode.com/problems/find-unique-binary-string/
class Solution {
public:
    
    int convertToInt(string s){
        int sum = 0 , p = 1;
        for(int i=s.size()-1 ; i>=0;i--){
            if(s[i]=='1')
                sum += p;
            p*=2;
        }
        return sum;
    }
    
    string convertToBin(int n , int sz){
        string r;
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        
        return padding(r , sz);
    }
    
    string padding(string r , int sz){
        int csz = r.size();
        while(csz<sz){
            r = '0' + r;
            csz++;
        }
        return r;
    }
    
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        int sz = nums[0].size();
        vector<int> newList;
        for(string num : nums){
            newList.push_back(convertToInt(num));
        }
        sort(newList.begin() , newList.end());
        vector<int> newList2;
        newList2.push_back(newList[0]);
        for(int i=1;i<newList.size();i++){
            if(newList[i]==newList[i-1])
                continue;
            newList2.push_back(newList[i]);
        }
        for(int i=0;i<newList2.size();i++){
            cout<<newList2[i]<<" ";
            if(i!=newList2[i])
                return convertToBin(i , sz);
        }
        
        return convertToBin(nums.size() , sz);
    }
};
