class Solution {
    
  private: 
  
    bool isSafe( int x, int y, int n, vector<vector<int>>visited, vector<vector<int>> maze ){
        
        if( (x>=0 && x<n) && (y>=0 && y<n ) && ( maze[x][y] == 1 ) && ( visited[x][y] == 0 ) ){
            return true;
        }
        else{
            return false;
        }
        
    }
  
    void solve( int x, int  y, int n, vector<vector<int>> maze, vector<vector<int>>visited, string path, vector<string>& ans ){
        
        if( (x==n-1) && (y==n-1) ){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //down
        int newx = x+1;
        int newy = y;
        if( isSafe( newx, newy, n, visited, maze ) ){
            path.push_back('D');
            solve( newx, newy, n, maze, visited, path, ans );
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y-1;
        if( isSafe( newx, newy, n, visited, maze ) ){
            path.push_back('L');
            solve( newx, newy, n, maze, visited, path, ans );
            path.pop_back();
        }
        
        //right
        newx = x;
        newy = y+1;
        if( isSafe( newx, newy, n, visited, maze ) ){
            path.push_back('R');
            solve( newx, newy, n, maze, visited, path, ans );
            path.pop_back();
        }
        
        //up
        newx = x-1;
        newy = y;
        if( isSafe( newx, newy, n, visited, maze ) ){
            path.push_back('U');
            solve( newx, newy, n, maze, visited, path, ans );
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        vector<string>ans;
        string path;
        
        int x = 0;
        int y = 0;
        int n = maze.size();
        
        if( maze[0][0] == 0 ){
            return ans;
        }
        
        vector<vector<int>>visited = maze;
        for( int i=0; i<n; i++ ){
            for( int j=0; j<n; j++ ){
                visited[i][j] = 0;
            }
        }
        
        solve( x, y, n, maze, visited, path, ans );
        
        return ans;
        
    }
};
