## Solution explanation

- `NF` is the number of fields in the current input record.
- `NR` is the number of input records awk has processed since the beginning of the program's execution
- `$i` means `i`th field of the input line
- `s[i]` is array in awk. In fact, array in awk is the same as dictionary in Python, which is organized as
key-value pair.
- `END` part will run after it dealt with every line.

After we figure out all the symbols and semantics in awk. The code is very straightforward.

## Reference

- http://www.math.utah.edu/docs/info/gawk_11.html#SEC108 (awk special symbol)
- http://kirste.userpage.fu-berlin.de/chemnet/use/info/gawk/gawk_12.html (awk array)
- http://www.grymoire.com/Unix/Awk.html (`$i` meaning)