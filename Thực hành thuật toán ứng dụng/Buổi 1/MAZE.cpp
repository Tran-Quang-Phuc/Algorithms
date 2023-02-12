// Problem link: https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/MAZE
#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int M = 1000;

typedef pair<int, int> Point;
int d[N][M];

int solve(int MAZE[N][M], int n, int m, int r, int c)
{
    queue<Point> trace;
    trace.push(Point(r, c));
    d[r][c] = 0; MAZE[r][c] = 1;
    int x[] = {0, 0, 1, -1};
    int y[] = {1, -1, 0, 0};

    while(!trace.empty())
    {
        Point cur = trace.front();
        trace.pop();

        for(int i=0; i < 4; i++)
        {
            int R = cur.first + x[i];
            int C = cur.second + y[i];
            
            if(R > n || R < 1 || C > m || C < 1)  
                return d[cur.first][cur.second] + 1;
            
            if(MAZE[R][C] != 1)
            {
                trace.push(Point(R, C));
                d[R][C] = d[cur.first][cur.second] + 1;
                MAZE[R][C] = 1;         
            }
        }
    }

    return -1;
}

int main() {
    int n, m, r, c;
    int MAZE[N][M];
    
    scanf("%d%d%d%d", &n, &m, &r, &c);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &MAZE[i][j]);
    
    int ans = solve(MAZE, n, m, r, c);
    printf("%d\n", ans);
    
    return 0;
}