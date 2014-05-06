// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Clarification:
// What constitutes a word?
//     A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
//     Yes. However, your reversed string should not contain leading or trailing spaces.
// How about multiple spaces between two words?
//     Reduce them to a single space in the reversed string.

void _deleteOne(char *s, int idx, int end)
{
    for (int i = idx; i < end; ++i)
    {
        s[i] = s[i + 1];
    }
    s[end] = '\0';
}

void _trim(char *s)
{
    int end = strlen(s) - 1;
    int i = 0;
    while(i <= end - 1){
        char x0 = s[i];
        char x1 = s[i + 1];
        if (x0 == ' ' && x1 == ' ')
        {
            _deleteOne(s, i, end);
            end = end - 1;
        }
        else{
            i = i + 1;
        }
    }
    
    int len = strlen(s);
    if(len > 0){
        if(len == 1){
            if(s[0] == ' '){
                _deleteOne(s, 0, len - 1);
                len = len - 1;
            }
        }
        else{
            if(s[0] == ' '){
                _deleteOne(s, 0, len - 1);
                len = len - 1;
            }
            if(s[len - 1] == ' '){
                _deleteOne(s, len - 1, len - 1);
                len = len - 1;
            }
        }
    }
}

void _reverse(char *s, int start, int end){
    int cnt = (end - start + 1) / 2;
    for(int i = 0; i < cnt; ++i){
        char tmp = s[start + i];
        s[start + i] = s[end - i];
        s[end - i] = tmp;
    }
}

void _reverseWords(char *s){
    if(s == NULL){
        return;
    }
    
    _trim(s);
    int len = strlen(s);
    if(len <= 0){
        return;
    }

    _reverse(s, 0, len - 1);

    int idx0 = 0;
    int idx1 = -1;
    for(int i = 0; i <= len; ++i){
        char x = s[i];
        if(x == ' '){
            idx1 = i - 1;
            _reverse(s, idx0, idx1);
            idx0 = i + 1;
        }
        else if(x == '\0'){
            idx1 = len - 1;
            _reverse(s, idx0, idx1);
        }
    }
}

class Solution {
public:
    void reverseWords(string &s) {
        char *cstr = (char*)s.c_str();
        _reverseWords(cstr);
        s.resize(strlen(cstr));
    }
};