// Given a string, find the length of the longest substring without repeating characters.

int lengthOfLongestSubstring(string s) 
{        
  if (s.empty() || s.size() == 1)
    return s.size();

  int left = 0;
  int right = 0;
  int maxLength = 0;

  std::unordered_map<char, int> table;

  while (right < s.size())
  {
    std::unordered_map<char, int>::iterator it
      = table.find(s[right]);

    // If there is no repeatition
    if(it == table.end())
    {
      table.insert(std::pair<char,int>(s[right], right));
      ++right;
    }
    else
    {
      if (table.size() > maxLength)
        maxLength = table.size();

      right = it->second + 1;
      table.clear();
    }
  }

  if (table.size() > maxLength)
    maxLength = table.size();

  return maxLength;
}
