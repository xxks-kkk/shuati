import sys
reload(sys)
sys.setdefaultencoding('utf-8') # https://stackoverflow.com/questions/31137552/unicodeencodeerror-ascii-codec-cant-encode-character-at-special-name

from bs4 import BeautifulSoup
import requests
#import re

url = "https://leetcode.com/problems/reverse-integer/"
#url="https://leetcode.com/problems/reverse-linked-list-ii/#/description"
r = requests.get(url)
data = r.text
soup = BeautifulSoup(data, "lxml")

letters = soup.find_all("div", class_="question-content")
print(letters[0])

for element in letters:
    rawText = element.get_text()

lines = rawText.split('\n') # Split into lines: https://stackoverflow.com/questions/172439/how-do-i-split-a-multi-line-string-into-multiple-lines
lines = filter(None, lines) # Removes empty strings: https://stackoverflow.com/questions/3845423/remove-empty-strings-from-a-list-of-strings

target = open("leetcode.test", "w")
target.write("/*          \n")
target.write(" * [Source] \n")
target.write(" *          \n")
target.write(" * " + url + "\n")
target.write(" *          \n")
target.write(" * [Problem Description]\n");
target.write(" *          \n")

for line in lines:
    if "Subscribe" not in line:
        if "click" in line:
            pass
        else:
            target.write(" * " + line + "\n")
    else:
        break
target.write(" *          \n")
target.write(" * [Companies]\n");
target.write(" */          \n")
target.close()
