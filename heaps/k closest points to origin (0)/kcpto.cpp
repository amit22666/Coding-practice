#include <bits/stdc++.h> //works like magic, but at cost.
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<int,int>
void beautify(int w , int n , int t[][1000]){
	int i,j;
	cout << "\n-----MAT Begins----\n";
	Fo(i,0,n+1){
		Fo(j,0,w+1){
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

int solve(int a[n][2], int k,int n){
int i; int j;
vector<int>dist;
//complexity reduced from nlogn to nlogk
fo(i,n){
        dist[i] = a[0]*a[0] + a[1]*a[1];
    
}



priority_queue<int>maxh;
fo(i,a.size()){
    maxh.push(dist[i]);
    if(maxh.size()>k){
        maxh.pop();
    }
}

while(maxh.size()>0){
    cout<<maxh.top();
    maxh.pop();
}


return (maxh.top());
//base condition  
}

int main() {
	// 1. C++ Productivity Tips
	// 2. To be used while Coding Interview Prep
	// 3. Solving Problems can take time
	// 4. Writing for loops, reading multiple variables is boring.
	// 5. Debugging Tools are not present in Coding Interviews.
	
	OJ;

	//make a folder for the question --->bot
	//then make 2 txt file 
	// set cmd to that location
	//(cs..) previous directory  (cd filename) new directory
	//use snippet or templete 
	int k; cin>>k;	
	int i, n;
	 cin >> n;
    int a[n][2]; 
//watch for inequalities
	
	fo(i, k){
        fo(j,3){
		cin >> a[i][j];
    }
}

	
    int ans = solve(a,k,n);
	cout<<"optimal kth smallest  ="<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}