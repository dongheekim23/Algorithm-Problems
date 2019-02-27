// Given an array of strings, group anagrams together.

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
  vector<vector<string>> answer;

  if (strs.empty())
    return answer;

  int start = 0;
  int i = 0;
  vector<bool> skipTable(strs.size(), false);
  int addCount = 0;

  while (addCount < strs.size())
  {
    start = 0;
    while (skipTable[start] == true)
      ++start;

    answer.emplace_back(vector<string>());
    i = start;
    answer.back().emplace_back(strs[i]);
    ++addCount;
    skipTable[i] = true;

    string sortedWord = strs[i];
    sort(sortedWord.begin(), sortedWord.end());

    while (i < strs.size())
    {
      if (sortedWord.length() == strs[i].length()
        && skipTable[i] == false)
      {
        string sortedWord2 = strs[i];
        sort(sortedWord2.begin(), sortedWord2.end());

        if (sortedWord == sortedWord2)
        {
          answer.back().emplace_back(strs[i]);
          skipTable[i] = true;
          ++addCount;
        }
      }

      ++i;
    }
  }

  return answer;
}
