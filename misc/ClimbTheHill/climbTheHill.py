import heapq

def climbTheHill(slope):
    pass

def test(pfcn):
    slope = [0,1,2,5,6,5,7]
    assert pfcn(slope) == 1
    slope = [9,8,7,2,3,3]
    assert pfcn(slope) == 1
    slope = [9,8,9,8,9,8]
    assert pfcn(slope) == 2
    slope = [9,8,7,8,9]
    assert pfcn(slope) == 2
    slope = [5,2,3,5]
    assert pfcn(slope) == 3
    slope = [3,4,2,1,5,7]
    assert pfcn(slope) == 4

if __name__ == "__main__":
    test(climbTheHill)