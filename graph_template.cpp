#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    void dfsRec(vector<int> arr[],int loc,vector<int>& dfs,vector<int>& vis) {
        dfs.push_back(loc);
        vis[loc]=1;
        for(int i=0;i<arr[loc].size();i++) {
            if(!vis[arr[loc][i]]) {
                dfsRec(arr,i,dfs,vis);
            }
        }
    }
public:
    vector<int> bfsGraph(vector<int> arr[],int n) {
        vector<int> bfs;
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            bfs.push_back(x);
            for(int i=0;i<arr[x].size();i++) {
                if(!vis[arr[x][i]]) {
                    q.push(arr[x][i]);
                    vis[arr[x][i]]=1;
                }
            }
        }
        return bfs;
    }
    vector<int> dfsGraph(vector<int> arr[],int n) {
        vector<int> dfs;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) 
                dfsRec(arr,i,dfs,vis);
        }
        return dfs;
    }
};

void print(vector<int> arr) {
    for(int i=0;i<arr.size();i++) 
        cout<<arr[i]<<" ";
    cout<<endl;
}

void addEdge(vector<int> arr[],int u,int v) {
    arr[u].push_back(v);
    arr[v].push_back(u);
}

int main() {
    cout<<"Enter range of vertex : ";
    // int n;
    // cin>>n;
    vector<int> arr[6];
    addEdge(arr,1,2);
    addEdge(arr,1,3);
    addEdge(arr,1,4);
    addEdge(arr,1,5);
    addEdge(arr,2,4);
    addEdge(arr,2,1);
    addEdge(arr,3,1);
    addEdge(arr,4,1);
    addEdge(arr,4,2);
    addEdge(arr,5,1);
    // cout<<"Enter the number of edges : ";
    // int e;
    // cin>>e;
    // cout<<"Enter edges : ";
    // for(int i=0;i<e;i++) {
    //     int u,v;
    //     cin>>u>>v;
    //     addEdge(arr,u,v);
    // }
    Solution ans;
    // vector<int> bfs=ans.bfsGraph(arr,n);
    // print(bfs);
    vector<int> dfs=ans.dfsGraph(arr,6);
    print(dfs);
}