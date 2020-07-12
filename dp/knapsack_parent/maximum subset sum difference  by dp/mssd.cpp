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
		if(i==0) t[i][j] =  false;

        if(j==0) t[i][j] =  true;
	}
}

Fo(i,1,n+1){
	Fo(j,1,sum+1){
		//consider
		// initialization t(i,j)-->a(i-1)
        if(a[i-1]<=j){
            t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j] ; 
        }
        else{
            t[i][j] = t[i-1][j];
        }
		}
	}

beautify(sum,n,t);

vector<int> last_row;
fo(i,(sum+1)/2){
    if(t[n][i]==true){
        last_row.push_back(i);
    }
}

cout<<endl;
fo(i,last_row.size()){
    cout<<last_row[i]<<" ";
}
cout<<endl;
//deb(last_row.back());

return last_row.back();

}

int solve(vector<int> a,int n){

int i,j;
//if call beautify intitialize t(n+1,100)
int sum = 0;

fo(i,n){
    sum += a[i]; 
}

int last_row = subset_sum(a,n,sum);
int s1 = last_row;
int s2 = 0 ;
s2  = sum - s1;
deb(s1);
deb(s2);

 int result = abs(s2-s1);

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