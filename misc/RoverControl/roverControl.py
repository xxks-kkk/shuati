import fileinput
import collections

def roverMove(n, cmds):
    # print(f'n: {n}')
    # print(f'cmds: {cmds}')
    x = 0
    y = 0
    for cmd in cmds:
        if cmd == 'LEFT' and x > 0:
            x -= 1
        elif cmd == 'RIGHT' and x < n-1:
            x += 1
        elif cmd == 'UP' and y > 0:
            y -= 1
        elif cmd == 'DOWN' and y < n -1:
            y += 1
    return y*n + x


if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    cmds = []
    n = int(input_string_list.popleft())
    ncmds = int(input_string_list.popleft())
    while len(input_string_list) > 0:
        cmds.append(input_string_list.popleft())

    assert roverMove(n, cmds) == 8