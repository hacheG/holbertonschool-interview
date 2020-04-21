#!/usr/bin/python3
#comentario


def canUnlockAll(boxes):
    """comentario de funcion"""
    key = 0
    keychain = [0]
    if len(boxes) is 0:
        return True
    for key in keychain:
        for key in boxes[key]:
            if key in keychain:
                continue
            else:
                if key <= len(boxes) - 1:
                    keychain.append(key)
                else:
                    continue
    if len(boxes) == len(keychain):
        return True
    else:
        return False
