//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    
    int trap(vector<int>& A) {
        ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
        int n=A.size();
    if(n==0)return 0;
    int lmax[n];
    int  rmax[n];
    lmax[0]=A[0];rmax[n-1]=A[n-1];
    for(int i=1;i<A.size();i++){
        lmax[i]=(lmax[i-1]>=A[i])?lmax[i-1]:A[i];
        
    }
    for(int i=n-2;i>=0;i--){
        rmax[i]=(rmax[i+1]>=A[i])?rmax[i+1]:A[i];
        
    }
    int sum=0;
    for(int i=0;i<n;i++){
       // cout<<((lmax[i]>=rmax[i])?rmax[i]:lmax[i])-A[i]<<" ";
        sum+=((lmax[i]>=rmax[i])?rmax[i]:lmax[i])-A[i];
    }
    return sum;
    }
};
