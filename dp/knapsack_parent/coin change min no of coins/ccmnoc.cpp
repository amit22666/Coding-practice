#include <bits/stdc++.h> //works like magic, but at cost.
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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

int solve(vector<int> wt,int w,int n){

int i,j;
//if call beautify intitialize t(n+1,100)


int t[n+1][1000];
//watch for inequalities in Fo loop 
//base case
Fo(i,0,n+1){
	Fo(j,0,w+1){
		//consider
		// initialization t(i,j)-->a(i-1)
        
        
        if(j==0) t[i][j] = 0;
        if(i==0) t[i][j] = INT_MAX-1;

		}
	}

fo(j,w+1){
    if(j%wt[0]==0){
    t[1][j]=j/wt[0];
    }
    else{
        t[1][j]=INT_MAX-1;
    }
}
Fo(i,1,n+1){
	Fo(j,1,w+1){
        

		if(wt[i-1]<=j){
            t[i][j] =min(t[i][j-wt[i-1]]+1 ,t[i-1][j]);
        }
        else {
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
	
	OJ;

	//make a folder for the question --->bot
	//then make 2 txt file 
	// set cmd to that location
	//(cs..) previous directory  (cd filename) new directory
	//use snippet or templete 
		
	int i, n,w;
	cin >> n;
    cin>>w;
//watch for inequalities
	vector<int> a(n, 0);
	fo(i, n)
		cin >> a[i];


	
    int ans = solve(a,w,n);
	cout<<"optimal answer = "<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}