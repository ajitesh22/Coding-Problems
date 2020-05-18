//https://practice.geeksforgeeks.org/problems/skip-the-work/0

#include <iostream>
using namespace std;
int solve(){
    int n;cin>>n;
	  
	  int arr[n];
	  for(int i=0;i<n;i++)cin>>arr[i];
	  
	  if(n==1)return 0;
	  if(n==2)return min(arr[0],arr[1]);
	  
	  int taken1=arr[0],notTaken1=0;   
	  int taken2=arr[1],notTaken2=arr[0];
	  
	  for(int i=2;i<n;i++){
	      
	      int takeCurrent = arr[i] + min(taken2,notTaken2);
	      int notTakeCurrent = taken2; 
	      taken1 = taken2;notTaken1=notTaken2;
	      taken2 = takeCurrent;
	      notTaken2 = notTakeCurrent;
	  }
	  return min(taken2,notTaken2);   
}

int main() {
	int t;cin>>t;
	while(t--){
	    cout<<solve()<<endl;
	}
	return 0;
}
