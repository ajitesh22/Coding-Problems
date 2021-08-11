class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int zero=0;
        vector<int>negNums , posNums;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0)
                negNums.push_back(arr[i]);
            else if(arr[i]>0)
                posNums.push_back(arr[i]);
            else
                zero++;
        }
        if(negNums.size()%2!=0 || posNums.size()%2!=0 || zero%2!=0)
            return false;
        
        map<int,int>map;
        for(int e : negNums)
            map[e]++;
        for(int i=negNums.size()-1;i>=0;i--){
            if(map[negNums[i]]<=0)continue;
            if(!map.count(negNums[i]*2) || map[negNums[i]*2]<=0)
                return false;
            map[negNums[i]*2]--;
            map[negNums[i]]--;
        }
        map.clear();
        for(int e : posNums)
            map[e]++;
        for(int i=0;i<posNums.size();i++){
            if(map[posNums[i]]<=0)continue;
            if(!map.count(posNums[i]*2) || map[posNums[i]*2]<=0)
                return false;
            map[posNums[i]*2]--;
            map[posNums[i]]--;
        }
        return true;
        
    }
};







