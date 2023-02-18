#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** = number of times c occurs in s.
Example: numberc('a', "aaabbbaccabda") == 6
*/
int numberc(char c, char *s)
{
	if (s[0] == '\0')
	{
		return 0;
	}
	else
	{
		if (s[0] == c)
		{
			return 1 + numberc(c, s + 1);
		}
		else
		{
			return 0 + numberc(c, s + 1);
		}
	}
	return 0;
}

/** = number of chars in s that are not c.
Example: numberNotc('a', "aaabbbaccabda") == 7)
*/
int numberNotc(char c, char *s)
{
	if (s[0] == '\0')
	{
		return 0;
	}
	else
	{
		if (s[0] != c)
		{
			return 1 + numberNotc(c, s + 1);
		}
		else
		{
			return 0 + numberNotc(c, s + 1);
		}
	}
	return 0;
}

/** = a copy of s but with all occurrences of c replaced by d.
Example: replace("abeabe", 'e', '$') = "ab$ab$".
*/
char *replace(char *s, char c, char d)
{
	if (*s == '\0')
	{
		char *result = (char *)malloc(sizeof(char));
		*result = '\0';
		return result;
	}

	char *result = replace(s + 1, c, d);
	int len = strlen(result);

	char *new_result = (char *)malloc((len + 2) * sizeof(char));
	new_result[0] = (*s == c) ? d : *s;
	strcpy(new_result + 1, result);
	free(result);

	return new_result;
}

/** = a copy of s with adjacent duplicates removed.
Example: for s = "abbcccdeaaa", the answer is "abcdea".*/
char *rem1(char *s)
{
	if (*s == '\0')
	{
		char *result = (char *)malloc(sizeof(char));
		*result = '\0';
		return result;
	}

	char *result = rem1(s + 1);
	int len = strlen(result);

	if (*s == *(s + 1))
	{
		char *new_result = (char *)malloc((len + 1) * sizeof(char));
		strcpy(new_result, result);
		free(result);
		return new_result;
	}
	else
	{
		char *new_result = (char *)malloc((len + 2) * sizeof(char));
		new_result[0] = *s;
		strcpy(new_result + 1, result);
		free(result);
		return new_result;
	}
}

/** = number of the digits in the decimal representation of n.
e.g. numDigits(0) = 1, numDigits(3) = 1, numDigits(34) = 2.
numDigits(1356) = 4.
Precondition: n >= 0. */
int numDigits(int n)
{
	if (n / 10 > 0)
	{
		return 1 + numDigits(n / 10);
	}
	else
	{
		return 1;
	}
	return 0;
}

/** = sum of the digits in the decimal representation of n.
e.g. sumDigits(0) = 0, sumDigits(3) = 3, sumDigits(34) = 7,
sumDigits(345) = 12.
Precondition: n >= 0. */
int sumDigits(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return sumDigits(n / 10) + n % 10;
}

/** = a copy of s with to_remove_char removed.
Example: removeChar("abeabe", 'e') = "abab". */
char *removeChar(char *s, char to_remove_char)
{
	if (*s == '\0')
	{
		char *result = (char *)malloc(sizeof(char));
		*result = '\0';
		return result;
	}

	char *result = removeChar(s + 1, to_remove_char);
	int len = strlen(result);

	if (*s == to_remove_char)
	{
		return result;
	}
	else
	{
		char *new_result = (char *)malloc((len + 2) * sizeof(char));
		new_result[0] = *s;
		strcpy(new_result + 1, result);
		free(result);
		return new_result;
	}

	return 0;
}

/** = a copy of s with characters in reverse order.
Example: reverse("abcdefg") = "gfedcba". */
char *reverse(char *s)
{
	// printf("char: %c\n", *s);
	if (*s == '\0')
	{
		char *result = (char *)malloc(sizeof(char));
		*result = '\0';
		return result;
	}
	char *result = reverse(s + 1);
	int len = strlen(result);
	// printf("len: %d\n", len);

	char *new_result = (char *)malloc((len + 2) * sizeof(char));
	strcpy(new_result, result);
	// printf("new_result: %s\n", new_result);
	new_result[len] = *s;
	new_result[len + 1] = '\0';

	free(result);
	return new_result;
}
// char *reverse(char *s)
// {
// 	if (*s == '\0')
// 	{
// 		char *result = (char *)malloc(sizeof(char));
// 		*result = '\0';
// 		return result;
// 	}
// 	char *result = reverse(s + 1);
// 	int len = strlen(result);
// 	char *new_result = (char *)malloc((len + 2) * sizeof(char));
// 	strcpy(new_result, result);
// 	new_result[len] = *s;
// 	new_result[len + 1] = '\0';
// 	free(result);
// 	return new_result;
// }
int numOnes(int n)
{
	if (n / 2 == 0 && n % 2 == 0)
	{
		return 0;
	}
	if (n / 2 == 0 && n % 2 == 1)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return 1 + numOnes(n / 2);
	}
	else
	{
		return numOnes(n / 2);
	}
}

void printRecur(int n)
{
	if (n <= 1)
	{
		printf("%d ", n);
		return;
	}
	else
	{
		printRecur(n - 1);
	}
	printf("%d ", n);
	printRecur(n - 1);
}

int main()
{
	char s1[] = "aaabbbaccabda";

	// put all your testcases here
	printf("test numberc() function.\n");
	printf("numberc('a', %s) = %d\n", s1, numberc('a', s1));
	printf("numberc('b', %s) = %d\n", s1, numberc('b', s1));
	printf("numberc('c', %s) = %d\n", s1, numberc('c', s1));
	printf("numberc('d', %s) = %d\n", s1, numberc('d', s1));
	printf("numberc('a', %s) = %d\n", " ", numberc('a', " "));

	printf("test numberNotc() function.\n");
	printf("numberNotc('a', %s) = %d\n", s1, numberNotc('a', s1));
	printf("numberNotc('b', %s) = %d\n", s1, numberNotc('b', s1));
	printf("numberNotc('c', %s) = %d\n", s1, numberNotc('c', s1));
	printf("numberNotc('d', %s) = %d\n", s1, numberNotc('d', s1));
	printf("numberNotc('a', %s) = %d\n", "", numberNotc('a', ""));

	printf("test replace() function.\n");
	printf("replace(%s, a, x) = %s\n", s1, replace(s1, 'a', 'x'));
	printf("replace(%s, a, b) = %s\n", s1, replace(s1, 'a', 'b'));
	printf("replace(%s, x, a) = %s\n", s1, replace(s1, 'x', 'a'));
	printf("replace(%s, b, x) = %s\n", s1, replace(s1, 'b', 'x'));

	char s2[] = "";
	char s3[] = "aaaaaaaaaaaaa";
	char s4[] = "a";
	char s5[] = "ababababababa";
	printf("test rem1() function.\n");
	printf("rem1(%s) = %s\n", s1, rem1(s1));
	printf("rem1(%s) = %s\n", s2, rem1(s2));
	printf("rem1(%s) = %s\n", s3, rem1(s3));
	printf("rem1(%s) = %s\n", s4, rem1(s4));
	printf("rem1(%s) = %s\n", s5, rem1(s5));

	int d1 = 1;
	int d2 = 10;
	int d3 = 911;
	int d4 = 1234;
	int d5 = 10001;
	printf("test numDigits() function.\n");
	printf("numDigits(%d) = %d\n", 1, numDigits(d1));
	printf("numDigits(%d) = %d\n", 10, numDigits(d2));
	printf("numDigits(%d) = %d\n", 911, numDigits(d3));
	printf("numDigits(%d) = %d\n", 1234, numDigits(d4));
	printf("numDigits(%d) = %d\n", 10001, numDigits(d5));

	printf("test sumDigits() function.\n");
	printf("sumDigits(%d) = %d\n", 1, sumDigits(d1));
	printf("sumDigits(%d) = %d\n", 10, sumDigits(d2));
	printf("sumDigits(%d) = %d\n", 911, sumDigits(d3));
	printf("sumDigits(%d) = %d\n", 1234, sumDigits(d4));
	printf("sumDigits(%d) = %d\n", 10001, sumDigits(d5));

	printf("test removeChar() function.\n");
	printf("removeChar(%c) = %s\n", 'a', removeChar(s1, 'a'));
	printf("removeChar(%c) = %s\n", 'b', removeChar(s1, 'b'));
	printf("removeChar(%c) = %s\n", 'c', removeChar(s1, 'c'));
	printf("removeChar(%c) = %s\n", 'd', removeChar(s1, 'd'));
	printf("removeChar(%c) = %s\n", 'e', removeChar(s1, 'e'));

	printf("test reverse() function.\n");
	printf("reverse(%s) = %s\n", s1, reverse(s1));
	printf("reverse(%s) = %s\n", s2, reverse(s2));
	printf("reverse(%s) = %s\n", s3, reverse(s3));
	printf("reverse(%s) = %s\n", s4, reverse(s4));
	printf("reverse(%s) = %s\n", s5, reverse(s5));

	printf("test numOnes() function.\n");
	printf("numOnes(%d) = %d\n", 0, numOnes(0));
	printf("numOnes(%d) = %d\n", 1, numOnes(1));
	printf("numOnes(%d) = %d\n", 2, numOnes(2));
	printf("numOnes(%d) = %d\n", 3, numOnes(3));
	printf("numOnes(%d) = %d\n", 4, numOnes(4));
	printf("numOnes(%d) = %d\n", 5, numOnes(5));
	printf("numOnes(%d) = %d\n", 6, numOnes(6));
	printf("numOnes(%d) = %d\n", 7, numOnes(7));
	printf("numOnes(%d) = %d\n", 8, numOnes(8));
	printf("numOnes(%d) = %d\n", 9, numOnes(9));
	printf("numOnes(%d) = %d\n", 100000, numOnes(100000));

	printf("test printRecur() function.\n");
	printRecur(1);
	printf("\n");
	printRecur(2);
	printf("\n");
	printRecur(3);
	printf("\n");
	printRecur(4);
	printf("\n");
	printRecur(5);
	printf("\n");
	return 0;
}
