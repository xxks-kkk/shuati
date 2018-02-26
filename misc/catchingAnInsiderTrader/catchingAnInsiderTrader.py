"""
# Problem Statement

Imagine you are working for a small hedge fund, and your mission is to catch
insider traders. You have a new pattern that you think might indicate to you
that something suscipicious like insider trading may be occuring: The profit
made, or loss prevented, by an INDIVIDUAL trade due to changes in the price
of that stock within a 3 day window after the trade was made is greater than
or equal to $500,000.
You want to build an algorithm that is capable of taking the hedge fund's data
as input and generating a list of occurences of this pattern.

As input, for a given stock ticker, you have a pipe-delimited datasource sorted
by day with two primary pieces of information: the price of said stock on each
day and the trades of that stock made by each trader at the hedge fund over time.
The first line of the input, containing the number of lines, will NOT be part
of the array provided to you (it's only used by HackerRank's I/O code). More
specifically, you receive this data as a String Array where each element in the
array is one of:

- Stock price - the value of a stock on a given day
- These elements are simply <DAY>|<PRICE>, where DAY is the integer number of
  days since the fund has opened and price is integer dollar amount value of the stock 
  on that day
- Price is only recoreded when it has changed from the day before, and will 
  always have an entry for day 0
- Trade - the trade made by a specific trader for a stock on a given day
- These elements are of the format <DAY>|<TRADER>|<TRADE_TYPE>|<AMOUNT>, where
  trader TRADER either bought or sold depending on the value of TRADE_TYPE
  an integer AMOUNT number of that stock on the specified day
- TRADE_TYPE will either be "BUY" or "SELL"

Your output is another String Array that can be fed into other systems at
the hedge fund where each String in the array is simply an entry of the format
<DAY>|<TRADER> where DAY is the day said TRADER made the trade that triggered the
alert, not the day that the stock price changed.

This output should be sorted by day and then trader name, and should not include 
duplicates.

# Test Formatting

Input file:

<number-of-lines-n-in-data-feed>
<first-line-of-data-feed>
...
<n th-line-of-data-feed>

Output file:

<first-line-of-output-array>
...
<final-line-of-output>

# Example

Input file:

16
0|20
0|Kristi|SELL|300
0|Will|BUY|500
0|Tom|BUY|5000
0|Shilpa|BUY|150
1|Tom|BUY|150000
3|25
5|Shilpa|SELL|150
8|Kristi|SELL|60000
9|Shilpa|BUY|50
10|15
11|5
14|Will|BUY|10000
15|Will|BUY|10000
16|Will|BUY|10000
17|25

Output file:

1|Tom
8|Kristi

Example Explanation:

In this example, "1|Tom" is considered the only suspicious trade because
- On day 0 the stock price gets set at $20 - "0|20"
- On day 1 Tom buys 150,000 stock "1|Tom|BUY|150000"
- On day 3, 2 days later (i.e., within 3 days), the stock price increases
from $20 to $25 - "3|25"
- This represents a 25 - 20 = 5 difference in stock price
- Tom's trade on day 1 therefore earned him a profit of $5 * 150,000 = $750,000,
which is over our threshold

Also, "8|Kristi" is a suspicious trade because:
- On day 3 the stock price gets set at $25 - "3|25"
- On day 8 Kristi sells 60,000 stock "8|Kristi|SELL|60000"
- On day 10, 2 days later (i.e., within 3 days), the stock price decreases from $25
to $15 - "10|15"
- This represents a 15 -25 = -$10 difference in stock price
- Kristi's trade on day 8 therefore prevented a loss of $10 * 60,000 = $600,000, 
which is over our threshold
- Note that on day 11 (also within 3 days) the stock price decreases again from $15
to $5 = "11|5"
- Compared to day 8, this represents a 5 - 25 = $20 difference in stock price since 
Kristi's purchase, which amounts to preventing a loss of $1.2 million
- However, Kristi's trade on day 8 was already flagged, so we should not add it to
our result set because we do not want duplicates 

Similarly, Will is not considered to have a suspicious trade
- The price of the stock on day 14 is $5 - "11|5"
- He buys 30 thousand total stock betweeen days 14 and 16 inclusive - 
["14|Will|BUY|10000", "15|Will|BUY|10000", "16|Will|BUY|10000"]
- The price of the stock on day 17 increases to $25
- This represents a $20 difference
- Will has profited $20 * 30,000 = $600,000 TOTAL
- The amount of profit earned by any one of his 3 individual trades is only
$20*10,000 = $200,000
- $200,000 is less than the threshold amount of $500,000 for any INDIVIDUAL
trade and thus it is not flagged


Company:
Palantir, Indeed
"""
class Transaction:
    def __init__(self, day, name, buy, amount):
        self.day = day
        self.buy = buy # boolean
        self.name = name
        self.amount = amount

class LargeKey(str):
    def __lt__(x, y):
        rec1 = x.split("|")
        rec2 = y.split("|")
        for i in range(len(rec1)):
            if i == 0:
                if int(rec1[i]) < int(rec2[i]):
                    return True
                if int(rec1[i]) > int(rec2[i]):
                    return False
            else:
                if rec1[i] < rec2[i]:
                    return True
                if rec1[i] > rec2[i]:
                    return False

def findPotentialInsiderTraders(datafeed):
    priceMap = {} # Day: Price
    transactionMap = {} # Day: List of transactions on that day
    res = []
    def initData(input):
        checkpoint = 0
        for record in input:
            fields = record.split("|")
            if len(fields) == 2:
                priceMap[int(fields[0])] = int(fields[-1])
                # Here, we want to fill out the prices when there is no change.
                # Otherwise, we may get keyError
                for i in range(int(fields[0])-1, checkpoint, -1):
                    priceMap[i] = priceMap[checkpoint]
                checkpoint = int(fields[0])
            elif len(fields) == 4:
                trans = Transaction(int(fields[0]), fields[1], fields[2] == 'BUY', int(fields[3]))
                day = int(fields[0])
                if day in transactionMap:
                    transactionMap[day].append(trans)
                else:
                    transactionMap[day] = [trans]
    initData(datafeed)
    for day in sorted(transactionMap):
        ops = transactionMap[day]
        for trans in ops:
            curVal = trans.amount * priceMap[trans.day]
            for i in range(1,4):
                if day + i in priceMap and priceMap[day + i] != priceMap[day]:
                    diff = trans.amount * priceMap[day+i] - curVal
                    if (trans.buy and diff >= 500000) or (not trans.buy and diff <= -500000):
                        res.append(trans)
                        break
    if not res or len(res) == 0:
        return [""]
    arr = [""] * len(res)
    for i in range(len(arr)):
        arr[i] = str(res[i].day) + "|" + res[i].name
    # We use our customized comparator
    arr.sort(key=LargeKey)
    return arr

if __name__ == "__main__":
    with open("input001.txt", 'r') as f:
        content = f.readlines()
        input001 = [line.rstrip('\n') for line in content]
        input001 = input001[1:] # get rid of the first row
    f.close()
    with open("output001.txt", 'r') as f:
        content = f.readlines()
        output001 = [line.rstrip('\n') for line in content]
    f.close()
    assert findPotentialInsiderTraders(input001) == output001

    with open("input002.txt", 'r') as f:
        content = f.readlines()
        input002 = [line.rstrip('\n') for line in content]
        input002 = input002[1:]
    f.close()
    with open("output002.txt", 'r') as f:
        content = f.readlines()
        output002 = [line.rstrip('\n') for line in content]
    f.close()
    assert findPotentialInsiderTraders(input002) == output002

    with open("input003.txt", 'r') as f:
        content = f.readlines()
        input003 = [line.rstrip('\n') for line in content]
        input003 = input003[1:]
    f.close()
    with open("output003.txt", 'r') as f:
        content = f.readlines()
        output003 = [line.rstrip('\n') for line in content]
    f.close()
    assert findPotentialInsiderTraders(input003) == output003