class Solution
{
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
  {
    //sorting in decreasing order of highest units per box, i.e., 2nd value
    sort(boxTypes.begin(), boxTypes.end(), [](auto& v1, auto& v2) {
      return v1[1] > v2[1];
    });
    int maxUnits = 0;
    for(auto& box: boxTypes)
    {
      int numBoxes = min(truckSize, box[0]);
      maxUnits += numBoxes*box[1];
      truckSize-=numBoxes;
      if(truckSize == 0)
        break;
    }
    return maxUnits;
  }
};