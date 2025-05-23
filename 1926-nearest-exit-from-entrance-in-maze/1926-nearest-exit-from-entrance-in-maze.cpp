class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; //marking it visited
        int steps = 0;
        
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                pair<int, int> temp = que.front();
                que.pop();
                
                if(temp != make_pair(entrance[0], entrance[1]) &&//  The entrance does not count as an exit. 
                   (temp.first == 0 || temp.first == m-1 || temp.second == 0 || temp.second == n-1))
                    return steps;
                
                for(auto &dir : directions) {
                    int i = temp.first  + dir[0];
                    int j = temp.second + dir[1];

                    if(i >= 0 && i < m && j >= 0 && j < n && maze[i][j] != '+') {
                        que.push({i, j});
                        maze[i][j] = '+'; //marking it as visited
                    }
                }
                
            }
            steps++;
        }
        
        return -1;
    }
};  