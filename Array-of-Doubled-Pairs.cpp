
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        vector<int>negNums , posNums;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0)
                negNums.push_back(arr[i]);
            else
                posNums.push_back(arr[i]);
        }
        if(negNums.size()%2!=0 || posNums.size()%2!=0)
            return false;
        
        map<int,int>map;
        if(negNums.size()!=0)
            map.insert({negNums[0] , 1 });
        for(int i=1;i<negNums.size();i++){
            if(!map.count(negNums[i]*2) || map[negNums[i]*2]<=0)
                return false;
            map[negNums[i]*2]--;
            map[negNums[i]]++;
        }
        map.clear();
        if(posNums.size()!=0)
            map.insert({posNums[0] , 1 });
        for(int i=1;i<posNums.size();i++){
            if(!map.count(posNums[i]/2) ||  map[posNums[i]/2]<=0)
                return false;
            map[posNums[i]/2]--;
            map[posNums[i]]++;
        }
        return true;
        
    }
};
