class Solution {
public:
    
    bool check(int col,int row,vector<string>vec,int n){
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
    
    
    void dfs(int col,int n,vector<string>vec,vector<vector<string>>&ans){
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
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>vec;
        string s(n,'.');
        for(int i=0;i<n;i++){
            vec.push_back(s);
        }
        
        dfs(0,n,vec,ans);
        return ans;
    }
};