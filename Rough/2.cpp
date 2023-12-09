int isValid(string s) {
    int count = 0;
    int num = 0;
    int len = s.length();
    
    if (len < 7 || len > 15) {
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') {
            if (num > 255 || num < 0 || count == 3) {
                return 0;
            }
            count++;
            num = 0;
        } else if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else {
            return 0;
        }
    }
    
    if (num > 255 || num < 0 || count != 3) {
        return 0;
    }
    
    return 1;
}
