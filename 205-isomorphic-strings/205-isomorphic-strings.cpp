class Solution {
public:
    bool isIsomorphic(string s, string t) {
      //array to store mapping of ascii chars
      int mapping[256];
      //initialising it to -1
      for(int i=0; i<256; i++)
        mapping[i] = -1;
      
      for(int i=0; i<s.length(); i++)
      {
        //if a new char is encountered, map it to the corresponding char in string t
        if(mapping[int(s[i])] == -1)
          mapping[int(s[i])] = int(t[i]);
        
        //otherwise, check whether it follows the previous mapping rule
        //if it does not, return false
        else if(mapping[int(s[i])]!=int(t[i]))
          return false;
      }
      //there could also be same mappings for more than one char
      //to check it, we would sort the mapping array and find any duplicate values
      sort(mapping,mapping+256);
      for(int i=0; i<255; i++)
      {
        //avoiding -1 values
        if(mapping[i] == -1)
          continue;
        //if duplicate mapping found, return false
        if(mapping[i] == mapping[i+1])
          return false;
      }
      return true;
    }
};