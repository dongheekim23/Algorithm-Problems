// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

int romanToInt(string s)
{
  int num = 0;
  int i = 0;

  while (i < s.size())
  {
    if (s[i] == 'M')
    {
      num += 1000;
      ++i;
    }
    else if (s[i] == 'D')
    {
      num += 500;
      ++i;
    }
    else if (s[i] == 'C')
    {
      if (i + 1 < s.size() && s[i + 1] == 'M')
      {
        num += 900;
        i += 2;
      }
      else if (i + 1 < s.size() && s[i + 1] == 'D')
      {
        num += 400;
        i += 2;
      }
      else
      {
        num += 100;
        ++i;
      }
    }
    else if (s[i] == 'L')
    {
      num += 50;
      ++i;
    }
    else if (s[i] == 'X')
    {
      if (i + 1 < s.size() && s[i + 1] == 'C')
      {
        num += 90;
        i += 2;
      }
      else if (i + 1 < s.size() && s[i + 1] == 'L')
      {
        num += 40;
        i += 2;
      }
      else
      {
        num += 10;
        ++i;
      }
    }
    else if (s[i] == 'V')
    {
      num += 5;
      ++i;
    }
    else if (s[i] == 'I')
    {
      if (i + 1 < s.size() && s[i + 1] == 'X')
      {
        num += 9;
        i += 2;
      }
      else if (i + 1 < s.size() && s[i + 1] == 'V')
      {
        num += 4;
        i += 2;
      }
      else
      {
        num += 1;
        ++i;
      }
    }
  }

  return num;
}
