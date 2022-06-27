class Solution {
public:
    int minPartitions(string n) {
      int maxDigit = -1;
      for(int i=0; i<n.length(); i++)
      {
        if(n[i]-'0' > maxDigit)
          maxDigit = n[i]-'0';
      }
      return maxDigit;
    }
};