# Google 2018 OA
# http://www.1point3acres.com/bbs/thread-438475-1-1.html

def emailProcessing(emailList):
    def processLocal(local):
        # we get rid of '.' in local
        local_cand = ''.join(local.split('.'))
        for i, c in enumerate(local_cand):
            if c == '+':
                return local_cand[:i]
        return local_cand

    # key: the email address after processing
    # val: the counts of the email address
    table = {}
    res = 0
    for emailAddress in emailList:
        local, domain = emailAddress.split('@')
        print(f'local: {local}')
        print(f'domain: {domain}')
        local_processed = processLocal(local)
        key = '@'.join([local_processed, domain])
        if key in table:
            table[key]+=1
        else:
            table[key] = 1
    for key in table:
        if table[key] > 1:
            res+=1
    return res

def test(pfcn):
    emailList = ['a.b@example.com', 'dupli......cate@example.com', 'd.u.p.l.i.c.a.t.e@example.com',
                 'ab+work@example.com']
    assert emailProcessing(emailList) == 2

if __name__ == "__main__":
    test(emailProcessing)