class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        BOARD_SIZE = 9
        BOX_SIZE = 3;
        seen = set()
        for row in range(9):
            for col in range(9):
                char = board[row][col]
                if char in seen and char != ".":
                    return False
                seen.add(char)
            seen.clear()

        for col in range(9):
            for row in range(9):
                char = board[row][col]
                if char in seen and char != ".":
                    return False
                seen.add(char)
            seen.clear()

        for box_row in range(0, 9, 3):
            for box_col in range(0, 9, 3):
                for row in range(box_row, box_row + BOX_SIZE):
                    for col in range(box_col, box_col + BOX_SIZE):
                        char = board[row][col]
                        if char in seen and char != ".":
                            return False
                        seen.add(char)
                seen.clear()
        return True


    # there are methods that use less time complexity but more space (example one pass but 27 sets(9 for rows, 9 for cols, 9 for boxes))