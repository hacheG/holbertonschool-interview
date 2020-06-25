#!/usr/bin/python3

'''UTF-8 validator'''


def validUTF8(data):
    '''Checks if UTF-8 is valid'''
    byte_cnt = 0

    for n in data:
        if byte_cnt:
            byte_cnt -= 1
            if (((n & 0xff) >> 6) != 2):
                return False
        elif (n & 0xF0) == 0xF0:  # 4 byte
            byte_cnt = 3
        elif (n & 0xE0) == 0xE0:  # 3 byte
            byte_cnt = 2
        elif (n & 0xC0) == 0xC0:  # 2 byte
            byte_cnt = 1
        elif not (n & 0x80):      # 1 byte
            byte_cnt = 0
        else:
            return False
    return not byte_cnt
