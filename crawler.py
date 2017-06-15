#!/usr/bin/env python3.6
# -*- coding: utf-8 -*-

# Quick leetcode crawler
#
# Generate the source file of the question and pre-fixed head comment
# 
# Usage: crawler.py [leetcode question url]

from bs4 import BeautifulSoup
import requests
import sys
#from sys import argv
import re
#from urllib.parse import urlparse
import validators
import operator
import os

if __name__ == "__main__":

    script, url = sys.argv
    #print('url is {:s}'.format(url))

    if not validators.url(url):
        print("Please enter a valid url!")
        sys.exit()
        
    #url = "https://leetcode.com/problems/reverse-integer/"
    #url = "https://leetcode.com/problems/reverse-linked-list-ii/#/description"
    r = requests.get(url)
    data = r.text
    soup = BeautifulSoup(data, "lxml")

    title_corp = soup.find_all("div", class_="question-title")
    title_raw = title_corp[0].h3.get_text()
    title_lines = title_raw.split('\n')
    title_lines = list(filter(operator.methodcaller('strip'), title_lines)) # https://stackoverflow.com/questions/8449454/remove-strings-containing-only-white-spaces-from-list
    title_rdy = title_lines[0].lstrip(' ').replace(".", "-").split(' ')
    #print(title_rdy)
    title = "".join(title_rdy)
    #print(title)
    
    path = "./leetcode/" + title
    os.mkdir(path)
    
    extension = ".c"
    pat = re.compile(r"^(\d+)-")
    m = re.search(pat, title)
    filename=title[:m.start()] + title[m.end():]
    filename=filename[0].lower() + filename[1:]
    #print(filename)
    target = open(path+"/"+filename+extension, "w")
    
    letters = soup.find_all("div", class_="question-content")
    #print(letters[0])

    rawText = letters[0].get_text()

    lines = rawText.split('\n') # Split into lines: https://stackoverflow.com/questions/172439/how-do-i-split-a-multi-line-string-into-multiple-lines
    lines = list(filter(None, lines)) # Removes empty strings: https://stackoverflow.com/questions/3845423/remove-empty-strings-from-a-list-of-strings

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
                # Remove CLR, "\n" if appears
                line = line.replace("\r", "").replace("\n", "")
                #print(line)
                target.write(" * " + line + "\n") # https://stackoverflow.com/questions/31137552/unicodeencodeerror-ascii-codec-cant-encode-character-at-special-name
        else:
            break
    target.write(" *          \n")
    target.write(" * [Companies]\n");
    target.write(" */          \n")
    target.write("\n\n")
    
    target.close()
