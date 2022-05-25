class Solution {
public:
    int N, M;
    bool pacific = false;
    bool atlantic = false;
    
    bool visited[201][201] = {false, };
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    void dfs(const vector<vector<int>>& heights, int x, int y){
        visited[x][y] = true;
        if (x == 0 || y == 0)   pacific = true;
        if (x == N - 1 || y == M - 1)   atlantic = true;
        
        if (pacific && atlantic)    return;
            
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0|| ny >= M)  continue;       //나가는 거
            if (visited[nx][ny] == true)                continue;       //이미 들린 거
            if (heights[nx][ny] > heights[x][y])        continue;       //더 높은 곳
            
            dfs(heights, nx, ny);
        }
        
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answers;
        
        N = heights.size();
        M = heights[0].size();
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                pacific = false;
                atlantic = false;
                memset(visited, 0, sizeof(visited));
                
                dfs(heights, i, j);
                if (pacific && atlantic) {
                    vector<int> answer;
                    answer.push_back(i);
                    answer.push_back(j);
                    answers.push_back(answer);
                }
            }
        }
        
        return answers;
    }
};