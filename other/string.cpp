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

#include <cstring>

using namespace std;
class string {
public:
       string() :data(new char[1]) {
		   data[0] = '\0';
	   }
	   string(const char *str) : data(new char[strlen(str) + 1]) {
		   strcpy(data, str);
	   }
	   string(const string& s1) : data(new char[s1.size() + 1]) {
		   strcpy(data, s1.c_str());
	   }
	   ~string() {
		   delete[] data;
	   }
	   string& operator =(string& rhs) {
		   string tmp(rhs);
		   swap(tmp);
		   return *this;
	   }
	   string& operator=(string&& rhs) {
		   swap(rhs);
		   return *trhis;
	   }
	   size_t size() const {
		   return strlen(data);
	   }
	   const char* c_str() const {
		   return data;
	   }
	   void swap(string& rhs) {
		   using std::swap;
		   swap(data, rhs.data);
	   }
private:
       char *data;	
};

class Vector {
public:
        vector(int size = 0) : theSize(size), capacity(0 + SPACE_CAPACITY) {
			objects = new T[capacity];
		}
		vector(const Vector& rhs) : objects(NULL) {
			operator=(rhs);
		}
		~Vector() {
			delete[] objects;
		}
		
		const vector& operator=(const Vector& rhs) {
			capacity = rhs.capacity;
			theSize = rhs.size;
			objects = new objects[this->capacity];
			for (int i = 0; i < theSize; i++) {
				objects[i] = rhs.objects[i];
			}
			return *this;
		}
		
		 void resize()(the newSize) {
			 if (newSize > capacity) {
				 reserve(newSize*2 + 1);
				 theSize = newSize;
			 }
		 }
		 
		 void reserve(int newCapacity) {
			 if (newCapacity > capacity) {
				 T* tmp = objects;
				 delete[] objects;
				 objects = new objects[newCapacity];
			 }
		 }
		 bool isEmpty() const {
			 return getsize() == 0;
		 }
		 int getCapacity()  const {
			 return capacity;
		 }
		 int getsize()  const {
			 return theSize;
		 }
		 
		 void push_back(T t) {
			 if (theSize == capacity) {
				 reserve(capacity *2 + 1);
			 }
			 objects[theSize++] = t;
		 }
		 void pop_back() {
			 --theSize;
		 }
		 
		 enum {SPACE_CAPACITY = 16};
		
private:
        T* objects;
		int theSize;
		int capacity;
};

int calculate_1(string s) {
	stack<int> signs;
	signs.push(1);
	int sign = 1, num = 0, ans = 0;
	for (auto c : s) {
		if (c >= '0' && c <= '9') {
			num = 10 * num + (c - '0');
		} else if (c == '+' || c == '-') {
			ans += sign * signs.top() * num;
			num = 0;
			sign = (c == '+' ? 1 : -1);
		} else if (c == '(') {
			signs.push(sign * signs.top());
			sign = 1;
		} else if (c == ')') {
			ans += sign * signs.top() * num;
			sign = 1;
			num = 0;
			signs.pop();
		}
	}
	if (num)
		ans += signs.top() *sign * num;
	return ans;
}
 int calculate(string s) {
	 int res = 0, d = 0;
	 char sign = '+';
	 stach<int> nums;
	 for (int i = 0; i < s.size(); i++) {
		 if (s[i] >= '0' && s[i] <= '9') {
			 d = d * 10 + (s[i] - '0');
		 }
		 if (((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i = s.size() - 1) {
			 if (sign == '+') nums.push(d);
			 if (sign == '-') nums.push(-d);
			 if (sign == '*' || sign == '/') {
				 int tmp = sign == '*' ? nums.top() * d : nums.top / d;
				 nums.pop();
				 nums.push(tmp);
			 }
			 sign = s[i];
			 d = 0;
		 }
	 }
	 while (!nums.empty()) {
		 res += nums.top();
		 nums.pop();
	 }
	 return res;
 }