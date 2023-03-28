#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// Permutation to get numbers
// method: DFS

using namespace std;

vector<string> S;
string s;
vector<char> A = {'0','1','2','3','4','5','6','7','8','9'};

int dfs(int length,int index){
    if(index == length){
        S.push_back(s);
        return 0;
    }
    int start = index==0?1:0;
    for(int i = start;i<10;i++){
        s.push_back(A[i]);
        dfs(length,index+1);
        s.pop_back();
    }
    return 0;
}

int main(){
    int n,i;
    cin >> n; // print 1~10^n-1
    // S.resize(pow(10,n)-1);
    for(i = n;i <= n;i++){ // enumerate length of string
        dfs(i,0); // length = i, index = 0
    }
    for(i = 0;i<S.size();i++){
        cout << S[i] << endl;
        break;
    }
    return 0;
}