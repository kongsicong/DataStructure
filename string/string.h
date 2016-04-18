#ifndef _STRING_H_
#define _STRING_H_
namespace string {
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int Status;
	/*the string with fixed length*/
#define MAXSTRLEN 255
	typedef unsigned char SString[MAXSTRLEN + 1];

	Status StrCopy(SString &T, SString S);

	Status StrConcat(SString &T, SString S1, SString S2);

	Status SubString(SString &Sub, SString S, int pos, int len);

	Status StrAssign(SString &T, char *chars);

	Status StrCompare(SString S1, SString S2);

	int StrLength(SString S);

	Status ClearString(SString &S);



	/*return the position of substring T in the mian string S after positon pos*/
	int Index(SString S, SString T, int pos);

	int Index_KMP(SString S, SString T, int pos);

	void get_next(SString T, int next[]);

	void get_nextval(SString T, int nextval[]);

	/*the string with heap allocation*/
	typedef struct {
		char *ch;
		int length;
	}HString;

	Status StrConcat(HString &T, HString S1, HString S2);

	Status SubString(HString &Sub, HString S, int pos, int len);

	Status StrAssign(HString &T, char *chars);

	Status StrCompare(HString S1, HString S2);

	int StrLength(HString S);

	Status ClearString(HString &S);
}
#endif //_STRING_H_