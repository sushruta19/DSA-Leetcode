class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string prefix = "";
      for(int i=0; i<strs[0].length(); i++)
      {
        bool flag = true;
        for(int j=1; j<strs.size(); j++)
        {
          if(strs[j][i] != strs[0][i])
          {
            flag = false; break;
          }
        }
        if(flag)
          prefix+=strs[0][i];
        else break;
      }
      return prefix;
    }
};