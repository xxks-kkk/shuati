/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description
 *          
 * [Problem Description]
 *          
 * Given a string, you need to reverse the order of characters in each word within
 * a sentence while still preserving whitespace and initial word order.
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Note:
 * In the string, each word is separated by single space and there will not be any
 * extra space in the string.
 *          
 * [Comments]
 *          
 *          
 *          
 * [Companies]
 */          


void reverse(int b, int e, char *s){
  while(b < e) {
    s[b] ^= s[e];
    s[e] ^= s[b];
    s[b] ^= s[e];
    b++;
    e--;
  }
}

char* reverseWords(char* s)
{
  int i,
    len = strlen(s),
    index = 0;

  for(i = 0; i <= len; i++) {
    if((s[i] == ' ') || (s[i] == '\0')){
      reverse(index, i - 1, s);
      index = i + 1;
    }
  }
  return s;
}
