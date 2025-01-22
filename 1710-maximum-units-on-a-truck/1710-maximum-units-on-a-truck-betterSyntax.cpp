class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& v1, auto& v2) -> bool {
            return v1[1] > v2[1];
        });
        int unitsCount = 0;
        for (auto& box : boxTypes) {
            int numBox = min(truckSize, box[0]);
            truckSize -= numBox;
            unitsCount += numBox*box[1];
            if (truckSize == 0)
                break;
        }
        return unitsCount;
    }
};