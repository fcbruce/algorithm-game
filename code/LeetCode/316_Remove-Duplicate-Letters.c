/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : 7/11/2016 7:10:09 PM
 *
 */
char* removeDuplicateLetters(char* s) {
    int length = strlen(s);
    int count[26];
    char* result = (char *)malloc(sizeof(char) * (length + 1));
    int instack[26];
    int top = -1;
    
    memset(count, 0, sizeof count);
    memset(instack, 0, sizeof instack);
    
    for (int i = 0; i < length; i++) count[s[i] - 'a']++;
    for (int i = 0; i < length; i++) {
        char c = s[i];
        count[c - 'a']--;
        if (instack[c - 'a']) continue;
        while (top >= 0 && result[top] > c && count[result[top] - 'a'] > 0) {
            instack[result[top--] - 'a'] = 0;
        }
        result[++top] = c;
        instack[c - 'a'] = 1;
    }
    result[++top] = 0;
    return result;
}
