# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

bool isVowel(char c) {
    //true为1，false为0
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='y';
}
//字符数组长度可以通过strlen()函数获取
int arraylenth(char *p)
{
    int len = 0;
    while (*p)
    {
        p++;
        len++;
    }
    return len;
}
int maxVowels(char * s, int k){
    //k为规定滑动窗口大小
    int len = strlen(s);
    int vowel_count = 0;
    for(int i=0; i<k; i++) {
        vowel_count += isVowel(s[i]);
    }
    int ans = vowel_count;
    for(int i = k; i<len; i++) {
        vowel_count += isVowel(s[i]) - isVowel(s[i-k]);
        ans = fmax(ans,vowel_count);
    }
    return ans;
}
void fun(int a) {
	a = 10;
	int b = 0;
	int c = 0;
} 
int main() {
	int n = 5;
	char a[] = "rhythms";
	printf("aa"); 
	int c = 1;
	fun(c);
	int d = 1; 
	maxVowels(a,4);
	fun(d);
	return 0;
}

