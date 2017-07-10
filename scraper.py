#!/usr/bin/env python3.6
# -*- coding: utf-8 -*-

# Quick scraper
#
# Generate the source file of the question and pre-fixed head comment
#
# Supported website: leetcode, hackerrank
#
# Usage: scraper.py [supported website question url] [extension]
#
# Example: scraper.py http://.... .c
#
# Supported extension: .java, .c, .sql, .py

import sys
import os
import validators

# append the search path and then do the import
#
sys.path.append(os.path.abspath('scraper'))
import leetcode

def getSiteName(url):
    """get the site name from a given string

    Returns site name as string.
    
    Possible outputs:

    leetcode - leetcode.com
    hackerrank - hackerrank.com
    """
    candidates = url.split("//")[-1].split("/")[0].split(".")
    if candidates[0] == "www":
        # handle the case: ['www', 'hackerrank', 'com']
        #
        return candidates[1]
    else:
        # handle the case: ['leetcode.com', 'problems', 'island-perimeter', '#', 'description']
        return candidates[0]

if __name__ == "__main__":

    script, url, extension = sys.argv

    if not validators.url(url):
        print("Please enter a valid url!")
        sys.exit()

    sitename = getSiteName(url)

    if sitename == "leetcode":
        leetcode.leetcodeScraper(url, extension)
    if sitename == "hackerrank":
        pass
