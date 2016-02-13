int myAtoi(char* str) {
    if (str == NULL) return 0;
    long long result = 0;
    int sign = 1;
    int _sign = 0;
    while (*str && !isdigit(*str)) {
        if (isspace(*str)) {
            if (_sign == 1) return 0;
            str++;
            continue;
        }
        if (_sign != 0) return 0;
        _sign++;
        switch (*str) {
            case '-': sign = -1; break;
            case '+': break;
            default: return 0;
        }
        str++;
    }
    while (*str && isdigit(*str)) {
        result = result * 10 + *str - '0';
        str++;
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
    }
    return result * sign;
}
