char *strcpy(char *dest, const char *src) {
	assert(NULL != dest && NULL != src);
	char *tmp = dest;
	while ((*tmp++ = *src++) != '\0');
	
	return dest;
}

char *strncpy(char *dest, const char *src, unsigned int n) {
	assert(NULL != dest && NULL != src);
	
	char *tmp = dest;
	while (n-- > 0 && ((*tmp++ = *src++) != \'0');
	while (n-- > 0) *tmp++ = '\0';
	
	return dest;
}

int strcmp(const char *str1, const char *str2) {
	assert(NULL != str1 && NULL != str2);
	
	while (*str1 && *str2 && *str1 == *str2) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

char *strcat(char *dest, const char *src) {
	assert(NULL != dest && NULL != src);
	char *tmp = dest;
	while (*tmp != '\0') tmp++;
	
	while ((*tmp++ = *src++) != '\0');
	
	return dest;
}

void *memset(void *s, int c, size_t n) {
	assert(NULL != s);
	void *tmp = s;
	while (n--) {
		*(char *tmp) = (char) c;
		tmp = (char *)tmp + 1;
	}
	return s;
}

void *memcpy(void *dest, const void *src, size_t n) {
	assert(NULL != dest && NULL != src);
	int i = 0;
	void *tmp = dest;
	while (i < n) {
		*((char *)tmp + i) = *((char *)src + i);
		++i;
	}
	return dest;
}
int strStr(string haystack, string needle) {
	if (needle.size() == 0) return 0;
	int p1, p2, p1_move = haystack.size() - needle.size() + 1;
	for (p1 = 0; p1 < p1_move; p1++) {
		int k = p1;
		p2 = 0;
		while (k < haystack.size() && p2 < needle.size() && haystack[k] == needle[p2]) {
			k++;
			p2++;
		}
		if (p2 == needle.size()) return p1;
	}
    return -1;
 }
 
int myAtoi(string str) {
	//if (str.size() == 0) return 0；
	int i = 0, res = 0;
	while (i < str.size() && str[i] == ' ') i++;
	
	int sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+') i++;
	while (i < str.size()) {
		if (str[i] < '0' || str[i] > '9') break;
		int digit = str[i] - '0';
		if (sign == -1 && res > -((INT_MIN + digit) / 10))
			return INT_MIN;
		else if (sign == 1 && res > ((INT_MAX -digit) / 10))
			return INT_MAX;
		
		res = res * 10 + digit;
		i++;
	}
	return sign * res;
}
	

string longestPalindrome(string s) {
	if (string.empty()) return "";
	if (s.size() == 1) return s;
	int start = 0, len = 0;
	int i = 0;
	while (i < s.size()) {
		int j = i, k = i;
		while (k + 1 < s.size() && s[k+1] == s[k]) ++k;
		i = k+1;
		while (k + 1 < s.size() && j > 0 && s[k+1] == s[j-1]) {
			--j;
			++k;
		}
		int tmp = k - j + 1;
		if (tmp > len) {
			start = j;
			len = tmp;
		}
	}
	return s.substr(start, len);
}