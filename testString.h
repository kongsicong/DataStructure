#pragma once
#pragma execution_character_set("utf-8")

#ifndef _TEST_STRING_H_
#define _TEST_STRING_H_
#include "string/string.h"
using namespace string;
void testString();

void testStringWithFixedLen();

void testStringWithHeapAlloc();

void testStringIndex();


void CreateString(SString &S);
void PrintString(SString S);


void CreateString(HString &S);
void PrintString(HString S);

#endif //_TEST_STRING_H_