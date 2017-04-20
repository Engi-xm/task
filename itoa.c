#include <stdio.h>
#include <stdlib.h>


char* itoa(int num) {
	int sign, temp, n, x;
	char* str;
	x = n = 0;

	if((sign = num) < 0) // if negative
		num = -num; // make positive
	temp = num; // record to temp
	while(temp > 0) {
		n++; // count figures
		temp /= 10; // cycle
	}
	if(sign < 0) {
		str = (char*)malloc((n + 2) * sizeof(char)); // allocate memory
		*str = '-'; // push sign
		while(x < n) {
			*(str + n - x++) = ((num % 10) + '0'); // set char
			num /= 10; // cycle
		}
		*(str + n + 2) = '\0'; // close string
	} else {
		str = (char*)malloc((n + 1) * sizeof(char)); // allocate memory
		while(x < n) {
			*(str + n - ++x) = ((num % 10) + '0'); // set char
			num /= 10; // cycle
		}
		*(str + n + 1) = '\0'; // close string
	}

	return str;
}

int main(void) {
	int a = 5454;
	int b = -154;
	char* ptr_str_a = itoa(a);
	char* ptr_str_b = itoa(b);
	
	printf("int a = %s \n", ptr_str_a);
	printf("int b = %s \n", ptr_str_b);

	free(ptr_str_a);
	free(ptr_str_b);

	return 0;
}
