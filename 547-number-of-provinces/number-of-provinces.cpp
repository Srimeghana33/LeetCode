class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,n,visited,isConnected);
            }
        }
        return provinces;
    }
    void dfs(int node,int n,vector<int>& visited, vector<vector<int>> isConnected){
        visited[node]=1;
        for(int j=0;j<n;j++){
            if(isConnected[node][j]==1 && !visited[j]){
                dfs(j,n,visited,isConnected);
            }
        }
    }
};