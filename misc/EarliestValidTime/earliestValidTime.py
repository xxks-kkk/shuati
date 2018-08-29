# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, B, C, D, E, F):
    # write your code in Python 3.6
    d = [A, B, C, D, E, F]
    d = sorted(d)
    if d[4] < 6:
        # 2nd largest digit is smaller 6, we can just fill up
        if 10 * d[0] + d[1] < 24:
            return f'{d[0]}{d[1]}:{d[2]}{d[3]}:{d[4]}{d[5]}'
        else:
            return "NOT POSSIBLE"
    elif d[3] < 6:
        # 3rd largest digit is smaller 6, put 2nd largest in 4th position
        if 10 * d[0] + d[1] < 24:
            return f'{d[0]}{d[1]}:{d[2]}{d[4]}:{d[3]}{d[5]}'
        else:
            return "NOT POSSIBLE"
    elif d[2] < 6:
        # 4th largest digit is smaller 6, put 3rd largest in 2nd position
        if 10 * d[0] + d[3] < 24:
            return f'{d[0]}{d[3]}:{d[1]}{d[4]}:{d[2]}{d[5]}'
        else:
            return "NOT POSSIBLE"
    else:
        return "NOT POSSIBLE"


if __name__ == "__main__":
    assert solution(1,8,3,2,6,4) == '12:36:48'
    assert solution(0,0,0,0,0,0) == '00:00:00'
    assert solution(0,0,0,7,8,9) == '07:08:09'
    assert solution(2,4,5,9,5,9) == 'NOT POSSIBLE'