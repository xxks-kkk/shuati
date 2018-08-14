import collections
import fileinput

def electionWinner(votes):
    print(f'votes: {votes}')
    d = {}
    for vote in votes:
        if vote not in d:
            d[vote] = 1
        else:
            d[vote] += 1
    sorted_d = sorted(d.items(), key=lambda x: (x[1], x[0]), reverse=True)
    return sorted_d[0][0]


if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))

    nvotes = int(input_string_list.popleft())
    votes = []
    while len(input_string_list) > 0:
        votes.append(input_string_list.popleft())

    filename = fileinput.filename()
    if filename == 'input000.txt':
        assert electionWinner(votes) == 'Mary'
    elif filename == 'input001.txt':
        assert electionWinner(votes) == 'Michael'