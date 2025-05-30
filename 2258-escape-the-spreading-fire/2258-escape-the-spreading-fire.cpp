class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    void bfs(vector<vector<int>>& grid, int &minutes) {
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        minutes = 0;
        
        while(!q.empty()){
            int sz = q.size();
            for (int idx = 0; idx < sz; idx++){
                auto u = q.front();
                q.pop();
                int i = u.first, j = u.second;
                if(i == m - 1 && j == n - 1)
                    return;
                for(auto it: dir){
                    int i_ = it[0] + i;
                    int j_ = it[1] + j;
                    if(i_ < m && i_ >= 0 && j_ < n && j_ >= 0 &&
                       !vis[i_][j_] && grid[i_][j_] == 0){
                        q.push({i_, j_});
                        vis[i_][j_] = 1;
                    }
                }
            }
            minutes++;
        }
        if(vis[m-1][n-1] != 1)
            minutes = 0;
    }

    // Precompute the time the fire reaches each cell.
    vector<vector<int>> computeFireTime(vector<vector<int>>& grid) {
        int INF = INT_MAX;
        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        queue<pair<int,int>> fq;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    fireTime[i][j] = 0;
                    fq.push({i, j});
                }
            }
        }
        while(!fq.empty()){
            auto [i, j] = fq.front(); fq.pop();
            for(auto &d : dir){
                int ni = i + d[0], nj = j + d[1];
                if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if(grid[ni][nj] != 0) continue;
                //min time fire reaches to any cell, unweighted so use bfs instead              dijkastra
                if(fireTime[ni][nj] > fireTime[i][j] + 1){
                    fireTime[ni][nj] = fireTime[i][j] + 1;
                    fq.push({ni, nj});
                }
            }
        }
        return fireTime;
    }
    
    // Simulate the person’s escape (starting at delay d) using BFS.
    // For non-destination cells, arrive strictly before fire; at destination, equality is allowed.
    bool canEscape(int d, vector<vector<int>> &grid, vector<vector<int>> &fireTime) {
        if(d >= fireTime[0][0]) return false;
        //As the person takes each step (using BFS), it checks that the arrival time at a cell is strictly less than the fire arrival time for that cell
        vector<vector<int>> personTime(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> pq;
        personTime[0][0] = d;
        pq.push({0,0});
        while(!pq.empty()){
            auto [i, j] = pq.front(); pq.pop();
            if(i == m - 1 && j == n - 1) {
                if(personTime[i][j] <= fireTime[i][j])
                    return true;
            }
            for(auto &dxy : dir){
                int ni = i + dxy[0], nj = j + dxy[1];
                if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if(grid[ni][nj] != 0) continue;
                int nt = personTime[i][j] + 1;
                if(ni == m - 1 && nj == n - 1) {  // destination: allow equality
                    if(nt <= fireTime[ni][nj] && nt < personTime[ni][nj]){
                        personTime[ni][nj] = nt;
                        pq.push({ni, nj});
                    }
                } else {
                    if(nt < fireTime[ni][nj] && nt < personTime[ni][nj]){
                        personTime[ni][nj] = nt;
                        pq.push({ni, nj});
                    }
                }
            }
        }
        return false;
    }
    
    bool multisource(vector<vector<int>> grid, int mid) { // grid passed by value intentionally
        vector<vector<int>> fireTime = computeFireTime(grid);
        return canEscape(mid, grid, fireTime);
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();    // row count
        n = grid[0].size(); // column count
        int minutes = 0;
        bfs(grid, minutes);
        if(minutes == 0) return -1;
        
        // MINIMAL CHANGE: Use 1e9 (1000000000) as the high bound instead of 'minutes'
        int s = 0, e = 1000000000;
        int ans = -1;
        
        if(multisource(grid, e))
            return 1000000000;  // Infinite wait is possible.
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(multisource(grid, mid)){
                ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return ans;
    }
};
