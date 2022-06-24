​Approach:
- Sort the given array
- Then store only the values of frequencies of integers in `freq[]` array. There is no need to store the integers themselves.
- The size of `freq[]` , i.e., `count+1` will be number of distinct integers.
- Sort `freq[]`
- Then traverse from beginning and decrementing k accordingly and incrementing the `remove` variable
- Unique integers left after k removals is `(count+1) - remove`
