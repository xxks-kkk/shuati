#!/usr/bin/env python3.6
# -*- coding: utf-8 -*-

# Quick hackerrank scraper
#
# Generate the source file of the question and pre-fixed head comment
# 
# Supported extension: .java, .c, .sql, .py

from bs4 import BeautifulSoup
import requests
import operator
import os
import re

def hackerrankScraper(url, extension):
    """ scraper for hackerrank
    """
    
    commentBlock = "*"
    pythonMode = False
    if extension == ".py":
        commentBlock = "#"
        pythonMode = True
        
    r = requests.get(url)
    data = r.text
    soup = BeautifulSoup(data, "lxml")

    # produce the directory name based upon leetcode question title
    # 
    title_corp = soup.find_all("div", class_="clearfix")
    print("{:s}".format(title_corp))
