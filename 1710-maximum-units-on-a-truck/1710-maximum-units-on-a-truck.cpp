class Solution {
public:
    static bool sortBySec(const vector<int>& v1, const vector<int>& v2)
    {
      if(v1[1]>v2[1])
        return true;
      return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(),boxTypes.end(),sortBySec);
      int ans = 0;
      for(auto &x:boxTypes)
      {
        if(truckSize==0)
          break;
        else if(truckSize<=x[0])
        {
          ans+=truckSize*x[1];
          truckSize = 0;
        }
        else
        {
          ans+=x[0]*x[1];
          truckSize-=x[0];
        }
      }
      return ans;
    }
};