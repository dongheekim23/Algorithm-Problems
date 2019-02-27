// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// 1. Each row must contain the digits 1-9 without repetition.
// 2. Each column must contain the digits 1-9 without repetition.
// 3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

bool isValidSudoku(vector<vector<char>>& board)
{
  bool table[9]{ false };

  // Horizontal
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      if (board[i][j] != '.')
      {
        if (table[board[i][j] - 49] == false)
          table[board[i][j] - 49] = true;
        else
          return false;
      }
    }

    memset(table, false, 9 * sizeof(bool));
  }

  // Vertical
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      if (board[j][i] != '.')
      {
        if (table[board[j][i] - 49] == false)
          table[board[j][i] - 49] = true;
        else
          return false;
      }
    }

    memset(table, false, 9 * sizeof(bool));
  }

  for (int k = 0; k < 9; ++k)
  {
    for (int i = 0 + 3 * (k / 3); i < 3 + 3 * (k / 3); ++i)
    {
      for (int j = 0 + (3 * k) % 9; j < 3 + (3 * k) % 9; ++j)
      {
        if (board[i][j] != '.')
        {
          if (table[board[i][j] - 49] == false)
            table[board[i][j] - 49] = true;
          else
            return false;
        }
      }
    }

    memset(table, false, 9 * sizeof(bool));
  }

  return true;
}
