error_codes = [
    "E1 More than 2 children", #0
    "E2 Duplicate Edges",      #1
    "E3 Cycle present",        #2
    "E4 Multiple roots",       #3
    "E5 Any other error"       #4 could be the case where a node has multiple parents
]

def SExpression(nodes):
    # keep track of edges we have processed so far
    visited = set()
    # 最多26个node所以只要26*3的array存可能的link
    links = [[None, None, None] for i in range(26)]

    # parse input，为了简化改了input格式，用分号分开各edges，不影响解题
    edges = nodes.split(' ')
    for edge in edges:
        edge = edge.replace('(', '').replace(')', '').replace(' ', '')
        a, b = edge.split(',')
        if (a,b) not in visited:
            visited.add((a,b))
        else:
            return error_codes[1]

        # 把node值转化成index
        a = ord(a) - ord('A')
        b = ord(b) - ord('A')
        if a < 0 or a > 25 or b < 0 or b > 25:
            # 非法输入的exception
            return error_codes[4]

        # 多root Exception
        if links[b][0]:
            return error_codes[3]

        # 记录子节点的父节点
        links[b][0] = a

        # 记录父节点的子节点
        # 如果已经有一个子节点，保证小的子节点在前 (e.g. A: C,B)
        if links[a][1] == None:
            links[a][1] = b
        elif links[a][2] == None:
            if b < links[a][1]:
                links[a][2] = b
            else:
                links[a][2] = links[a][1]
                links[a][1] = b
        elif links[a][1] == b or links[a][2] == b:
            # 重复edge exception
            return error_codes[1]
        else:
            # 多子节点exception
            return error_codes[0]

    # 寻找根节点
    root = None
    for idx in range(26):
        parent, child1, child2 = links[idx]
        if parent == None and (child1 != None or child2 != None):
            if root != None:
                # 多根节点exception
                return error_codes[3]
            root = idx

    # 无根节点exception，意味着有环.
    if root == None:
        return error_codes[2]

    # 防止循环：任意节点不能在同层或者更高层出现
    # 做layer by layer transverse，可以用一个array检查循环
    seen = [False for i in range(26)]
    layer = [root]
    while layer:
        tmpLayer = []
        for node in layer:
            if seen[node]:
                return error_codes[2]
            seen[node] = True
            if links[node][1] != None:
                tmpLayer.append(links[node][1])
                if links[node][2] != None:
                    tmpLayer.append(links[node][2])
        layer = tmpLayer

    # 输出结果
    def sExp(node):
        if links[node][1] == None:
            return "(%s)" % (chr(65 + node))
        tmp = sExp(links[node][1])
        if links[node][2] == None:
            return '(%s%s)' % (chr(65  + node), tmp)
        tmp2 = sExp(links[node][2])
        return '(%s%s%s)' % (chr(65  + node), tmp2, tmp)

    res = sExp(root)
    print(res)
    return res


def test(pfcn):
    nodes = "(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)"
    ans = "(A(B(D(E(G))))(C(F)))"
    assert pfcn(nodes) == ans

    nodes = "(A,B) (A,C) (A,D)"
    ans = "E1 More than 2 children"
    assert pfcn(nodes) == ans

    nodes = "(A,B) (A,B)"
    ans = "E2 Duplicate Edges"
    assert pfcn(nodes) == ans

    nodes = "(A,B) (B,C) (C,A)"
    ans = "E3 Cycle present"
    assert pfcn(nodes) == ans

    nodes = "(A,C) (B,C)"
    ans = "E4 Multiple roots"
    assert pfcn(nodes) == ans

    nodes = "(A,B) (A,C) (B,D) (D,C)"
    ans = "E3 Cycle present"
    print(pfcn(nodes))
    assert pfcn(nodes) == ans

    nodes = "(B,A) (B,C) (A,D)"
    ans = "(B(A(D))(C))"
    assert pfcn(nodes) == ans


if __name__ == "__main__":
    test(SExpression)