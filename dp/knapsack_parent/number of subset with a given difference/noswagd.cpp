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

int subset_sum(vector<int> a,int n,int sum){

int i,j;
//if call beautify intitialize t(n+1,100)


int t[n+1][1000];
//watch for inequalities in Fo loop 
//base case
Fo(i,0,n+1){
	Fo(j,0,sum+1){
		if(i==0) t[i][j]=0;

		if(j==0) t[i][j]=1;
	}
}

Fo(i,1,n+1){
	Fo(j,1,sum+1){
		if(a[i-1]<=j){
// initialization t(i,j)-->a(i-1)
/*because take every possible case*/  t[i][j] = t[i-1][j-a[i-1]] + t[i-1][j];
		}
		else{
			t[i][j] = t[i-1][j];
		}
		}
}
beautify(sum,n,t);
return t[n][sum];
}


int solve(vector<int> a ,int n){

int i,j;
//if call beautify intitialize t(n+1,100)

int d ; cin>>d;

int arrsum =0;

fo(i,n){
arrsum =arrsum +  a[i];
}

int s = (d+arrsum)/2;

deb(s);

int result = subset_sum(a,n,s);

return result;

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
		
	 int i, n;
 	cin >> n;
//watch for inequalities
	vector<int> a(n, 0);
	fo(i, n)
		cin >> a[i];

   
	

    

	
    int ans = solve(a,n);
	cout<<"optimal answer = "<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}