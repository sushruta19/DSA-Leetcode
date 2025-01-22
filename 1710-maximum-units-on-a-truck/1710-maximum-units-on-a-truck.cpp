class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] > b[1];
        });

        int unitCount = 0;
        for(int i=0; i<boxTypes.size() && truckSize > 0; i++) {
            if (boxTypes[i][0] <= truckSize) {
                unitCount += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                unitCount += truckSize * boxTypes[i][1];
                truckSize -= truckSize;
            }
        }
        return unitCount;
    }
};