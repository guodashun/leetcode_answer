class Solution {
public:
    typedef pair<int, int> PAIR;
    vector<vector<int>> ans = {{1, 2, 3}, {4, 5, 0}};
    vector<PAIR> cor = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    PAIR findZero(vector<vector<int>>& board){
      int i = 0, j = 0;
      for(i = 0; i < board.size(); i++){
        for(j = 0; j < board[0].size(); j++){
          if(board[i][j] == 0)
            return make_pair(i, j);
        }
      }

      return make_pair(i, j);
    }

    int slidingPuzzle(vector<vector<int>>& board) {
      if(board == ans)
        return 0;

      int res = 0;
      set<vector<vector<int>>> sets;
      queue<vector<vector<int>>> q;
      q.push(board);
      sets.insert(board);

      while(!q.empty()){
        int size = q.size();
        res++;
        for(int i = 0; i < size; i++){
          vector<vector<int>> tmp = q.front();
          q.pop();
          PAIR idx = findZero(tmp);
          for(auto p : cor){
            int x = idx.first + p.first;
            int y = idx.second + p.second;
            if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) 
              continue;
            
            vector<vector<int>> newtmp = tmp;
            swap(newtmp[idx.first][idx.second], newtmp[x][y]);
            if(newtmp == ans){
              return res;
            }
            if(sets.count(newtmp) == 0){
              sets.insert(newtmp);
              q.push(newtmp);
            }
          }
        }
      }

      return -1;
    }
};

// tricky
