//https://leetcode.com/problems/map-sum-pairs/
class MapSum {
public:
    /** Initialize your data structure here. */
    map<string,int>map;
    MapSum() {
        map.clear();
    }
    
    void insert(string key, int val) {
        
        map[key] = val;
        
        
    }
    
    int sum(string prefix) {
        int sum = 0;
        for(auto v : map){
            if(v.first.find(prefix)==0)
                sum+=v.second;
        }
        return sum;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
