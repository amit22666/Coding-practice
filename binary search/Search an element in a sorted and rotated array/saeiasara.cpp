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

int min_idx(vector<int> a , int s , int e,int n){


//base condition  

int result = -1;
while(s<=e){

int mid = s + (e-s)/2;

int prev=(n+mid-1)%n;
int next=(mid+1)%n;


if(a[mid]<=a[prev] and a[mid]<=a[next]){
    result = mid;
    break;
}

else if(a[mid]<=a[e]){
  
    e = mid-1;
}
else if(a[mid]>=a[s]){
s = mid+1;
}



}
return result!=-1? result:-1;
}


int bs(vector<int> a , int s , int e,int k){
    while(s<=e){

int mid = s + (e-s)/2;

if(a[mid]==k)
return mid;

else if(a[mid]>k){
    e = mid -1;
}
else {
    s=mid + 1;
}
}
return -1;
}

int solve(vector<int> a , int s , int e,int n,int k){
int idx =  min_idx(a ,s , e,n);

if(a[idx]==k){
return idx;
}

 int idx1 = bs(a,s,idx-1,k);
 int idx2 = bs(a,idx,e,k);

 return idx1!=-1?idx1:idx2;
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
//watch for inequalities
	vector<int> a(n, 0);
	fo(i, n)
		cin >> a[i];

    

	
    int ans = solve(a,0,n-1,n,k);
	cout<<"optimal answer idx = "<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}