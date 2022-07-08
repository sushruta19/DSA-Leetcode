class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int mapping[256];
      for(int i=0; i<256; i++)
        mapping[i] = -1;
      
      for(int i=0; i<s.length(); i++)
      {
        if(mapping[s[i]-'\0']==-1)
          mapping[s[i]-'\0']=t[i]-'\0';
        else if(mapping[s[i]-'\0']!=t[i]-'\0')
          return false;
      }
      sort(mapping, mapping+256);
      for(int i=0; i<255; i++)
      {
        if(mapping[i]==-1)
          continue;
        else if(mapping[i]==mapping[i+1])
          return false;
      }
      return true;
    }
};