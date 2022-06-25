​#### Approach - 
- Traverse the array.
- Count the number of times order breaks
- if its greater than 1, return false
- If order broke only one time, the position(index) where order broke is stored
- If order broke at beginning or end, return true
- Else compare the values surrounding the position(index)
