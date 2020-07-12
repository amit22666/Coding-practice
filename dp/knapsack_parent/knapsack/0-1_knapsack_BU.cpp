#include <bits/stdc++.h> //works like magic, but at cost.
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<=n; i++)
int w;
void beautify(int w , int n , int t[][100]){
	int i,j;
	cout << "\n-----MAT Begins----\n";
	Fo(i,0,n){
		Fo(j,0,w){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}

	cout << "-----MAT Ends------\n";

}

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

int i,j;
//base case
int t[n+1][100];

fo(i,n){
	fo(j,w){
		if(i==0 || j==0)
		t[i][j]=0;
	}
}

Fo(i,1,n){
	Fo(j,1,w){
		//consider
		if(wt[i-1]<=j)
		t[i][j] = max(t[i-1][j-wt[i-1]]+val[i-1],t[i-1][j]);

		else{
			t[i][j] = t[i-1][j];
		}
	}
}
beautify(w,n,t);


return t[n][w];

}


int main() {
	// 1. C++ Productivity Tips
	// 2. To be used while Coding Interview Prep
	// 3. Solving Problems can take time
	// 4. Writing for loops, reading multiple variables is boring.
	// 5. Debugging Tools are not present in Coding Interviews.
	
	
	
	int i, n;
	cin >> n;
 	w = 0;
	cin>>w;

	vector<int> a(n, 0);
	fo(i, n)
		cin >> a[i];

    vector<int> b(n, 0);
	fo(i, n)
		cin >> b[i];

	
    int ans = solve(a,b,w,n);
	cout<<<"optimal answer = "<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}