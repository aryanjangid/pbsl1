// Aryan Jangid
#include <bits/stdc++.h>
using namespace std;


void printBoard(vector<string> vec)
{
    for (auto i : vec)
    {
        cout << i << endl;
    }
}


bool check(int col,int row,vector<string>&vec,int n){
        int tr=row;
        int tc=col;
        while(col>=0 && row>=0){
            if(vec[row][col]=='Q'){
                return false;
            }
            col--;
            row--;
        }
        row=tr;
        col=tc;
        
        while(col>=0){
              if(vec[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=tr;
        col=tc;
        while(col>=0 && row<n){
              if(vec[row][col]=='Q'){
                return false;
            }
            col--;
            row++;
        }
        return true;
}


void dfs(int col,int n,vector<string>&vec,vector<vector<string>>&ans){
    // cout<<col<<endl;
    if(col==n){
        ans.push_back(vec);
        return;
    }
    for(int row=0;row<n;row++){
        if(check(col,row,vec,n)){
            vec[row][col]='Q';
            dfs(col+1,n,vec,ans);
            vec[row][col]='.';
        }
    }
}

void solve()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> vec;
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        vec.push_back(s);
    }

    dfs(0, n, vec, ans);

    for(auto i:ans){
        for(auto k:i){
            cout<<k<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}