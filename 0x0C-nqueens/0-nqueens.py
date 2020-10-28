#!/usr/bin/python3
"""
comentario random por que toca
"""

import sys


def is_not_safe_position(board, i, j, r):
    """
    comentario random por que toca
    """

    # Is board[i] in line of attack ?
    if (board[i] == j) or (board[i] == j - i + r) or (board[i] == i - r + j):
        return True
    return False


def find_positions(board, row, n):
    """
    comentario random por que toca
    """

    if row == n:
        print_chess_board(board, n)

    else:
        for j in range(n):
            legal = True
            for i in range(row):
                if is_not_safe_position(board, i, j, row):
                    legal = False
            if legal:
                board[row] = j
                find_positions(board, row + 1, n)


def print_chess_board(board, n):
    """
    comentario random por que toca
    """

    b = []

    for i in range(n):
        for j in range(n):
            if j == board[i]:
                b.append([i, j])
    print(b)


def create_chess_board(size):
    """
   comentario random por que toca
    """

    return [0 * size for i in range(size)]


# 1. Read and validate size of the board
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    n = int(sys.argv[1])
except BaseException:
    print("N must be a number")
    exit(1)

if (n < 4):
    print("N must be at least 4")
    exit(1)

# 2. Generate the board
board = create_chess_board(int(n))

# 3. Find the solutions
row = 0
find_positions(board, row, int(n))
