class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x : x[1], reverse=True)
        unitsCount = 0
        for box in boxTypes:
            numBox = min(box[0], truckSize)
            unitsCount += numBox * box[1]
            truckSize -= numBox
            if truckSize == 0:
                break
        return unitsCount