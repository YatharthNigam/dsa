// https://leetcode.com/problems/word-search/

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // We'll apply DFS to every element of the board.
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, i, j, word))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        // Base cases
        // If word become "" i.e. word if found.
        if (word.size() == 0)
        {
            return true;
        }
        // If i and j goes out of bound or letter doesn't matches the first letter of word.
        if (i == board.size() || j == board[0].size() || i < 0 || j < 0 || word[0] != board[i][j])
        {
            return false;
        }
        // Marking the letter visited by making it *
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        // Visiting all four directions and if found in any direction then continuing there. If one is true, we'll return true.
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        // Changing back the marked visited letter.
        board[i][j] = c;
        return ret;
    }
};