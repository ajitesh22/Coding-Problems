#include<bits/stdc++.h>
#define ll long long 

const long long INF64 = 1e18;
const long long N = 1e5+1;
using namespace std;
vector<ll>a(1e5+2,0);


int parent[N] , compSize[N];

int findParent(int i){

	if(parent[parent[i]] != parent[i])
		parent[i] =  findParent(parent[i]);

	return parent[i];
}


void unionNodes(int a , int b) {

	int parentA = findParent(a);
	int parentB = findParent(b);

	if(compSize[parentA]>=compSize[parentB]){
		swap(parentA,parentB);
	}

	compSize[parentB] += compSize[parentA];
	parent[parentA] = parentB ;

}



void  initilizeDsu(int n){
	for(int i=1;i<=n;i++){
		parent[i] = i;
		compSize[i] = 1;
	}
}

/*
  1. 2. 3  4. 5 
  1. 2. 3. 4. 5
  1  1. 1. 1. 1
*/
	
int main() {


	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif 
	int t = 1;//cin>>t;
	while(t--){

		int n = 5;
		initilizeDsu(n);

		unionNodes(1,5);
		unionNodes(2,4);
		unionNodes(4,1);


		for(int i=1;i<=n;i++)
			cout<<findParent(i)<<" ";

		cout<<endl;

		for(int i=1;i<=n;i++)
			cout<<compSize[i]<<" ";



	}


	return 0;
}
