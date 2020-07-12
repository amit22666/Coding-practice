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

pair<int,int> solve(int k,int m  , int n , int a[][4]){
 pair<int,int> result;
 result.first = -1; result.second =-1;
int i=0,j=n-1;
//base condition  



		

        while(i>=0 and j>=0){
            if(a[i][j]==k){
             result = make_pair(i,j);
                break; 
            }
           if(k<a[i][j]){
               j--;
           }
           else{
               i++;
           }     
        
    }

return result.first==-1 ? result:result;

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
	int i,j, n , m;
	cin >> m >> n;
//watch for inequalities
	// vector<int> a(n, 0);

     int a[m][4] ; 
    
    fo(i, m){
        fo(j,n){
            cin >> a[i][j];
        }
    }
		
  //cout<<"x";

    pair<int,int> ans = solve(k,m,n,a);
	cout<<"optimal answer idx = "<<ans.first<<"row "<<ans.second<<"col";
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}