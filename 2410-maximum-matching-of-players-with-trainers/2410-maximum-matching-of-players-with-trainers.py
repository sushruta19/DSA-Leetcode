class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        i,j,ans = 0,0,0
        while i < len(players) and j < len(trainers):
            if players[i] <= trainers[j]:
                ans += 1
                i += 1
            j += 1
        return ans