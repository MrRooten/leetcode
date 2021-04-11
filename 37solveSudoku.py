class Solution:
    def solveSudoku(self, board):
        empyts = []
        for irow in range(len(board)):
            for icol in range(len(board[irow])):
                if board[irow][icol] == ".":
                    empyts.append([irow,icol])

        dictSet = set(['1','2','3','4','5','6','7','8','9'])
        for pos in empyts:
            x = pos[0]
            canUseNums = set()
            _ = set()
            for col in board[x]:
                canUseNums.add(col)
            
            canUseNums = dictSet and _

            y = pos[1]
            _ = set()
            for row in board:
                _.add(board[row][y])

            canUseNums = canUseNums and _

            x1 = int(x / 3)
            y1 = int(y / 3)
            _ = set()
            for row in range(x1*3,x1*3+3):
                for col in range(y1*3,y1*3+3):
                    _.add(board[row][col])

            canUseNums = canUseNums and _
            if len(canUseNums) == 1:
                board[x][y] = canUseNums.pop()
