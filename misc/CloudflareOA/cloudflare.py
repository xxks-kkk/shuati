#!/bin/python3

import os
import json
import re

#
# Complete the 'evaluateAccess' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. STRING person
#  2. STRING rules
#

# Problem:
# input:
# person JSON object:
# {"name": "Joe Cloud",
#  "groups": ["engineer", "managers"],
#  "email" : "joecloud@cloudflare.com",
#  "ip": "1.1.3.3"
# }
# rules:
# [{
#   "action": "Allow",
#   "rules":[{
#     "type": "email",
#     "match": "^[a-z]+@cloudflare.com$"
#   },{
#     "type": "lastname",
#     "match": "Cloud"
#   }]
# }, {
#   "action": "Deny",
#   "rules": [{
#     "type": "group",
#     "match": "executives"
#   }, {
#     "type": "ip",
#     "match": "1.1.0.0"
#   }]
# }]
#
# The question asks to return [decision, rule index]
# - decision can be 1 ("Allow") or 0 ("deny")
# - rule index is 0-indexed and is the rule that made the decision
# - Deny takes precedence over allow (if allow rule and deny rule match, take deny action)
# - if allowed, rule index should be the first rule matched
# - if none of the rules matched, return deny with -1 as rule index
#
# For above example, should return [1,0]

# Cloudflare Hackerrank OA (Access) 10/02/19

def evaluateAccess(person, rules):
    person_dict = json.loads(person)
    person_firstname, person_lastname = person_dict["name"].split()
    person_dict["firstname"] = person_firstname
    person_dict["lastname"] = person_lastname
    rules_list = json.loads(rules)
    allow_index = -1
    for i, rule_set in enumerate(rules_list):
        rules = rule_set["rules"]
        action = rule_set["action"]
        all_matched = check_match(rules, person_dict)
        if all_matched:
            if action == "Deny":
                return [0, i]
            else:
                if allow_index == -1:
                    allow_index = i
    if allow_index == -1:
        return [0, -1]
    else:
        return [1, allow_index]

def check_match(rules, person_dict):
    for rule in rules:
        if rule["type"] == "group":
            if not rule["match"] in person_dict["groups"]:
                return False
        elif rule["type"] == "firstname":
            if rule["match"] != person_dict["firstname"]:
                return False
        elif rule["type"] == "lastname":
            if rule["match"] != person_dict["lastname"]:
                return False
        elif rule["type"] == "email":
            pattern = rule["match"]
            if not re.match(pattern, person_dict["email"]):
                return False
        elif rule["type"] == "ip":
            if rule["match"] != person_dict["ip"]:
                return False
    return True

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    person = input()

    rules = input()

    result = evaluateAccess(person, rules)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
