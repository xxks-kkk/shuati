## Solution explanation

When dealing with string pattern matching, one common strategy is to maintain a sliding window.
Here, we use a dictionary to help us to quickly identify whether a certain key (10-letter-long substrings)
happens previously. Value corresponding to the key indicate whether we have added the key to the result.
