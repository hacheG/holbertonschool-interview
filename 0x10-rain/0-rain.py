#!/usr/bin/python3
''' Trapping rain water problem '''


def rain(walls):
    '''
    Function to calculate how much water can be trapped
    @walls: Walls
    Return: Amount of water which can be trapped
    '''
    left, right = 0, len(walls) - 1
    water = 0
    level = 0
    while left < right:
        if walls[left] < walls[right]:
            cur_lvl = walls[left]
            left += 1
        else:
            cur_lvl = walls[right]
            right -= 1
        level = max(level, cur_lvl)
        water += level - cur_lvl
    return water
