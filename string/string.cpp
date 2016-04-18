#include "string.h"
#include <stdlib.h>
namespace string {
	Status StrCopy(SString &T, SString S) {
		T[0] = S[0];
		for (int i = 1; i < S[0]; i++) {
			T[i] = S[i];
		}
		return OK;
	}

	Status StrConcat(SString &T, SString S1, SString S2) {
		if (S1[0] + S2[0] <= MAXSTRLEN) {
			T[0] = S1[0] + S2[0];
			for (int i = 1; i <= S1[0]; i++) T[i] = S1[i];
			for (int i = 1; i <= S2[0]; i++) T[S1[0] + i] = S2[i];
		}
		else {
			T[0] = MAXSTRLEN;
			for (int i = 1; i <= S1[0]; i++) T[i] = S1[i];
			for (int i = 1; i <= MAXSTRLEN - S1[0]; i++) T[S1[0] + i] = S2[i];
		}
		return OK;
	}

	Status SubString(SString &Sub, SString S, int pos, int len){
		if (pos <= 0 || len <= 0) return ERROR;
		if (pos + len - 1 > S[0]) return ERROR;
		Sub[0] = len;
		for (int i = pos; i < pos + len; i++) Sub[i - pos + 1] = S[i];
		return OK;
	}

	Status StrAssign(SString &T, char *chars){
		int i = 0;
		for (char c = chars[0]; c != '\0'; c = chars[++i]) T[i + 1] = c;
		T[0] = i;
		return OK;
	}

	Status StrCompare(SString S1, SString S2)
	{
		int i = 1;
		while (i <= S1[0] && i <= S2[0]) {
			if (S1[i] < S2[i]) return -1;
			else if (S1[i] > S2[i]) return 1;
			else {
				i++;
			}
		}
		if (S1[0] == S2[0]) return 0;
		return S1[0] > S2[0] ? 1 : -1;
	}
	int StrLength(SString S) {
		return S[0];
	}

	Status ClearString(SString &S){
		S[0] = 0;
		return OK;
	}

	int Index(SString S, SString T, int pos) {

		int i = pos;
		int j = 1;
		while (i <= StrLength(S) && j <= StrLength(T)) {
			if (S[i] == T[j]) {
				i++;
				j++;
			}
			else {
				i = i - j + 2;
				j = 1;
			}
		}

		if (j > StrLength(T)) return i - StrLength(T);
		else return 0;
	}

	int Index_KMP(SString S, SString T, int pos) {
		int i = pos;
		int j = 1;
		int *next = (int*)malloc((StrLength(T) + 1)* sizeof(int));
		get_next(T, next);
		while (i <= StrLength(S) && j <= StrLength(T)) {
			if (S[i] == T[j] || j == 0) {
				i++;
				j++;
			}
			else j = next[j];
		}
		free(next);
		if (j > StrLength(T)) return i - StrLength(T);
		else return 0;
	}

	void get_next(SString T, int next[]) {
		int i = 1;
		next[1] = 0;
		int j = 0;
		while (i < StrLength(T)) {
			if (j == 0 || T[i] == T[j]) {
				i++;
				j++;
				next[i] = j;
			}
			else j = next[j];
		}
	}

	void get_nextval(SString T, int nextval[]) {
		int i = 1;
		nextval[1] = 0;
		int j = 0;
		while (i < StrLength(T)) {
			if (j == 0 || T[i] == T[j]) {
				i++;
				j++;
				if (T[i] != T[j]) nextval[i] = j;
				else nextval[i] = nextval[j];
			}
			else j = nextval[j];
		}
	}
	/**************************************************************************************************************************/

	Status StrConcat(HString &T, HString S1, HString S2){
		if (T.ch) free(T.ch);
		T.length = S1.length + S2.length;
		if (!T.ch){ T.ch = nullptr; return OK; }
		T.ch = (char*)malloc(T.length * sizeof(char));
		if (!T.ch) return OVERFLOW;

		for (int i = 0; i < S1.length; i++) T.ch[i] = S1.ch[i];
		for (int i = 0; i < S2.length; i++) T.ch[i + S1.length] = S2.ch[i];
		return OK;
	}

	Status SubString(HString &Sub, HString S, int pos, int len){
		if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1) return ERROR;
		if (Sub.ch) free(Sub.ch);
		if (!len) { Sub.ch = nullptr; Sub.length = 0; return OK; }
		Sub.ch = (char*)malloc(len * sizeof(char));
		if (!Sub.ch) return OVERFLOW;
		for (int i = pos; i < pos + len; i++) Sub.ch[i - pos] = S.ch[i];
		Sub.length = len;
		return OK;
	}

	Status StrAssign(HString &T, char *chars){
		if (T.ch) free(T.ch);
		int i = 0;
		for (char c = chars[0]; c != '\0'; c = chars[++i]);
		if (!i) { T.ch = nullptr; T.length = 0; return OK; }
		T.ch = (char*)malloc(i * sizeof(char));
		if (!T.ch) return OVERFLOW;
		T.length = i;
		i = 0;
		for (char c = chars[0]; c != '\0'; c = chars[++i]) T.ch[i] = c;
		return OK;
	}

	Status StrCompare(HString S1, HString S2){
		for (int i = 0; i < S1.length && i < S2.length; i++) {
			if (S1.ch[i] != S2.ch[i]) return S1.ch[i] - S2.ch[i];
		}
		return S1.length - S2.length;
	}

	int StrLength(HString S){
		return S.length;
	}

	Status ClearString(HString &S){
		S.length = 0;
		return OK;
	}
}
