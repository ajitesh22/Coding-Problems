//https://binarysearch.com/problems/Movie-Theatres
int solve(vector<vector<int>>& intervals) {
    
    vector<int>entryTime;
    vector<int>exitTime;

    for(auto interval : intervals){
        entryTime.push_back(interval[0]);
        exitTime.push_back(interval[1]);
    }

    sort(entryTime.begin() , entryTime.end());
    sort(exitTime.begin() , exitTime.end());

    int minCnt = 0 , cnt = 0;
    int exitPtr = 0;

    for(int i=0;i<intervals.size();i++){

        if(exitPtr>=intervals.size())
            continue;
        
        cnt++;
        while(exitPtr<intervals.size() && exitTime[exitPtr] <= entryTime[i]){
            cnt--;
            exitPtr++;
        }
        minCnt = max(minCnt , cnt);
    }

    return minCnt;
}
