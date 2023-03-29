#include <stdio.h>
#include <string.h>
#include <ctype.h>

char MostUsed(char* string){
	int alphabet[26]= {};
	int len = strlen(string), max=0, index=0, count=0, i;
	
	for (i=0; i<len; i++){
		int tmp = (int)toupper(string[i]) - 65;
		if (max < ++alphabet[tmp]){
			max = alphabet[tmp];
			index = tmp;
		}
	}
	
	for (i=0; i<26; i++){
		if (alphabet[index] == alphabet[i])
			count++;
	}
	
	if (count > 1) return '?';
	else return (char)(index+65);
}

int main()
{
	char string[1000000];
	scanf("%s", string);
	printf("%c\n", MostUsed(string));
	return 0;
}