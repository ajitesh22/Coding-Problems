//https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
#define ll long long int
#define max(a,b) (a>b)?a:b
class Solution {
public:
    long long numberOfWeeks(vector<int>& ms) {
        
     ll maxElement = -1;  
     ll totalSum  = 0; 
     ll result = 0;
     sort(ms.begin(),ms.end());
     for(int e : ms){
         maxElement = max(maxElement , e);
         totalSum += e;
     }
     cout<<maxElement<<" "<<totalSum<<" ";   
     ll diff = totalSum - maxElement;
	 if((diff + 1) < maxElement) {
		result = (2 * diff) + 1;
	 }
	 else{
		result = totalSum;
	}
     return result;    
    }
};
