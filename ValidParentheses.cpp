// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

bool isValid(string s)
{
  bool result = false;
  char* stack = new char[s.length()];
  int r = 0;

  if (s.length() == 0)
    return true;
  if (s.length() == 1)
    return false;

  for (int i = 0; i < s.length(); ++i)
  {
    switch (s[i])
    {

    case '(':
      stack[r] = '(';
      r++;
      break;

    case '[':
      stack[r] = '[';
      r++;
      break;

    case '{':
      stack[r] = '{';
      r++;
      break;

    case ')':
      if (r == 0) return false;
      if (stack[r - 1] != '(')
        return false;
      else r--;
      break;

    case ']':
      if (r == 0) return false;
      if (stack[r - 1] != '[')
        return false;
      else r--;
      break;

    case '}':
      if (r == 0) return false;
      if (stack[r - 1] != '{')
        return false;
      else r--;
      break;
    }
  }

  if (r == 0)
    return true;
  else
    return false;
}
