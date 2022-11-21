//Aryan Jangid
#include <bits/stdc++.h>
using namespace std;



void dfs(int curr, map<int,vector<int>>&mp,vector<int>&vis,vector<int>&ans){
    if(vis[curr]==1){
        return;
    }
    ans.push_back(curr);
    vis[curr]=1;
    for(auto i:mp[curr]){
        if(vis[i]!=1){
            dfs(i,mp,vis,ans);
        }
    }
    return;
}

void bfs(int curr, map<int, vector<int>>&mp,vector<int>&ans,int nodes){
    queue<int>q;
    q.push(curr);
    vector<int>vis(nodes+1,0);
    while(!q.empty()){
        int currentNode=q.front();
        q.pop();
        ans.push_back(currentNode);
        vis[currentNode]=1;
        for(auto i:mp[currentNode]){
            if(vis[i]!=1){
                q.push(i);
            }
                vis[i]=1;
        }
    }
    return;
}

void solve(){
    int nodes=7;
    vector<pair<int,int>>vec={{1,2},{1,3},{2,4},{2,5},{3,6},{3,7},{2,3},{4,5}};
    map<int,vector<int>>mp;
    for(auto i:vec){
        mp[i.first].push_back(i.second);
    }
    for(auto i:mp){
        cout<<i.first<<": ";
        for(auto k:i.second){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    vector<int>vis(nodes+1,-1);
    vector<int>dfsVector;
    int start=1;
    dfs(start,mp,vis,dfsVector);
    vector<int>bfsVector;
    bfs(start,mp,bfsVector,nodes);


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
return 0;
}