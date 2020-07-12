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

int answer = INT_MAX;

void wrapper(char *symbols,char *operators,int n){

    solve(symbols,operators,n,0,n-1,true);
	cout<<"optimal answer = "<<answer;
}

unordered_map<string,int>mp;

int solve(char *symbols,char *operators,int n,int i,int j,bool countof_TorF){
//thoda saa theek krna hai ... submit interview bit pr krna hai
// int i,j;
//if call beautify intitialize t(n+1,100)
if(i>j){
return true; 
}
if(i==j){
    if(countof_TorF==true){
        return symbols[i]=='T';
    }
    else{
        return symbols[i]=='F';
    }
}
  

string temp = to_string(i);
temp.push_back(' ');
temp.append(to_string(j));
temp.push_back(' ');
temp.append(to_string(countof_TorF));


if(mp.find(temp)!=mp.end()){
    return mp[temp];
}

int ans=0;
for(int k = i+1;k<=j-1;k=k+2){
    int lt = solve(symbols,operators,n,i,k-1,true);
    int lf = solve(symbols,operators,n,i,k-1,false);
    int rt = solve(symbols,operators,n,k+1,j,true);
    int rf = solve(symbols,operators,n,k+1,j,false);

    if(operators[k]=='&'){
        if(countof_TorF==true){
            ans = ans + lt *rt;
        }
        else{
           ans =  ans + lf * rf + lf * rt + rf * lt;
        }
    }

    if(operators[k]=='|'){
        if(countof_TorF==true){
            ans =  ans + lf * rf + lf * rt + rt * lt;
        }
        else{
            ans =  ans + lf * rf ;
        }
    }

    if(operators[k]=='^'){
        if(countof_TorF==true){
            ans = ans + lt *rf + lf * rt;
        }
        else{
            ans = lt *rt + lf * rf;
        }
    }
}


return ans;

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
		
	int i, n,m;
	cin >> m >> n;
//watch for inequalities
	char symbols[m]; 
    char operators[n]; 
	fo(i, m)
		cin >> symbols[i];

    fo(i,n)
        cin >> operators[i];
	
    mp.clear();
    wrapper(symbols,operators,n);
	// Fo(i, 1, n+1) //shortcut to move a line as well
	// 	cout << arr[i-1] << " " ;
	// cout << endl;
	
	return 0;
}