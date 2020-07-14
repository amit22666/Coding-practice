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
int solver(vector<int> a , int k){
int i;

//complexity reduced from nlogn to nlogk
priority_queue<int>maxh;
fo(i,a.size()){
    maxh.push(a[i]);
    if(maxh.size()>k){
        maxh.pop();
    }
}

return (maxh.top());

}

int solve(vector<int> a , int k1,int k2){
int i;

//complexity reduced from nlogn to nlogk
int val1 = solver(a,k1);
int val2 = solver(a,k2);
deb(val1);
deb(val2);
int sum=0;
fo(i,a.size()){
    if(a[i]>val1 or a[i]<val2)
    sum+=a[i];
}

return (sum);
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
	int k1,k2; cin>>k1>>k2;	
	int i, n;
	cin >> n;
//watch for inequalities
	vector<int> a(n, 0);
	fo(i, n)
		cin >> a[i];

    

	
    int ans = solve(a,k1,k2);
	cout<<"optimal kth smallest  ="<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}