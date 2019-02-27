// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.

void GetCombinationSums(vector<vector<int>>& combinationSums, const vector<int>& candidates, vector<int>& intVec, int index, int sum)
{
  intVec.emplace_back(candidates[index]);
  sum -= candidates[index];

  if (sum == 0)
  {
    combinationSums.emplace_back(intVec);
    return;
  }
  else if (sum < 0)
  {
    return;
  }

  for (int i = index; i < candidates.size(); ++i)
  {
    GetCombinationSums(combinationSums, candidates, intVec, i, sum);
    intVec.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
  vector<vector<int>> combinationSums;

  if (candidates.empty())
    return combinationSums;

  sort(candidates.begin(), candidates.end());

  vector<int> intVec;

  for (int i = 0; i < candidates.size(); ++i)
  {
    GetCombinationSums(combinationSums, candidates, intVec, i, target);
    intVec.clear();
  }

  return combinationSums;
}
