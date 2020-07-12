#include <bits/stdc++.h> //works like magic, but at cost.
using namespace std;

#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 

void beautify(ll w , ll n , ll t[][1000]){
	ll i,j;
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
bool isvalid(vector<ll>a,ll students,ll max_pages){
	ll pages=0;ll i=0;
	ll result = 0;
	ll bacche =1;
	fo(i,a.size()){
		if(pages<max_pages){
			pages +=a[i];
			//deb(a[i]);
			// deb(pages);
		}

		if(pages>max_pages and bacche<=students){
			bacche++;
			// deb(bacche);
			pages = a[i];
			
		}
		if(bacche>students){
			return false;
		}
	}
return true;

}



ll solve(vector<ll> a , ll k){
ll i;
ll maxi = 0; ll sum =0;
fo(i,a.size()){
maxi = max(a[i],maxi);
sum = sum + a[i];
}
ll result = 0;
ll s = maxi;
ll e = sum;

ll mid =0;
// bool tempans = isvalid(a,2,112);
// deb(tempans);
while(s<=e){
	 mid  = s + (e-s)/2;
	// if(mid == 113){
	// 	deb(s);
	// 	deb(e);
	// }
	bool tempans = isvalid(a,k,mid);

	if(tempans){
		result = mid;
		e= mid-1;
	}
	else{
		s = mid + 1;
	}
}

 


return result;
}


int main() {
	// 1. C++ Productivity Tips
	// 2. To be used while Coding llerview Prep
	// 3. Solving Problems can take time
	// 4. Writing for loops, reading multiple variables is boring.
	// 5. Debugging Tools are not present in Coding llerviews.
	
	OJ;

	//make a folder for the question --->bot
	//then make 2 txt file 
	// set cmd to that location
	//(cs..) previous directory  (cd filename) new directory
	//use snippet or templete 
	ll k; cin>>k;	
	ll i, n;
	cin >> n;
//watch for inequalities
	vector<ll> a(n, 0);
	fo(i, n)
		cin >> a[i];

    

	
    ll ans = solve(a,k);
	cout<<"optimal answer idx = "<<ans;
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}