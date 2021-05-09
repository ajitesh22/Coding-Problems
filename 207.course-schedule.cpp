//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //topological sort
        
        vector<int>outDegree(numCourses,0);
        vector<int> adj[numCourses+1];
        for(auto pair : prerequisites){
            adj[pair[1]].push_back(pair[0]);
            outDegree[pair[0]]++;
        }
        
        queue<int>queue;
        for(int i=0;i<numCourses;i++){
            if(outDegree[i]==0)
                queue.push(i);
        }
        
        int coursesTaken = 0;
        while(!queue.empty()){
            int course = queue.front();
            queue.pop();
            for(int neighbor : adj[course]){
                outDegree[neighbor]--;
                if(outDegree[neighbor]==0)
                    queue.push(neighbor);
            }
            coursesTaken++;   
        }
        
        return numCourses == coursesTaken;
    }
};
