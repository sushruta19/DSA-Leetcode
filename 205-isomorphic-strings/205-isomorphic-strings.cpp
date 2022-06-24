class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int mapping[256];
      for(int i=0; i<256; i++)
        mapping[i] = -1;
      
      for(int i=0; i<s.length(); i++)
      {
        if(mapping[int(s[i])] == -1)
          mapping[int(s[i])] = int(t[i]);
        else if(mapping[int(s[i])]!=int(t[i]))
          return false;
      }
      sort(mapping,mapping+256);
      for(int i=0; i<255; i++)
      {
        if(mapping[i] == -1)
          continue;
        if(mapping[i] == mapping[i+1])
          return false;
      }
      return true;
    }
};