#include <bits/stdc++.h> //works like magic, but at cost.
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)

// template<typename... T>
// void read(T&... args) {
// 	((cin >> args), ...);
// }

// template<typename... T>
// void write(T&&... args) {
// 	((cout << args << " "), ...);
// }

int max_profit = INT_MIN;

int solve(vector<int> wt,vector<int> val,int w,int n){

    if(n==0 || w==0)
    return 0;

    // consider
    if(wt[n-1] <= w)
    return max(solve(wt,val,w-wt[n-1],n-1)+val[n-1],solve(wt,val,w,n-1));

    else if(wt[n-1]>w)
    {
        return solve(wt,val,w,n-1);
    }
    
}



int main() {

	int t ;
	cin>>t;
	while(t--){
	
	int i, n;
	cin >> n;
	
	 int w = 0;
    cin>>w;
    
    vector<int> wt(n, 0);
	fo(i, n)
	cin >> wt[i];
    
    vector<int> val(n, 0);
	fo(i, n)
	cin >> val[i];
		
    int ans = solve(wt,val,w,n);
	
    cout<<ans<<endl;
	}
	return 0;
}