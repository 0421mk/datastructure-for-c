#ifndef __ARRAY_LIST_H__ // __ARRAPY_LIST_H__ 어떤 문자로 대체해도 상관없음, 단 #define도 같이 바꿔줘야 함 
#define __ARRAY_LIST_H__ // 이렇게 하면 컴파일러가 컴파일시 ArrayList.h 파일이 추가되어있는지 확인 후 추가되어있지 않다면 전처리하고 추가되어 있다면 #endif로 건너뛰어 불필요한 컴파일러 검사를 방지 
#include "NameCard.h"

#define TRUE 1 // 참 
#define FALSE 0 // 거짓 

#define LIST_LEN 100 // 전체 데이터 크기 
typedef NameCard * LData; // int형 데이터 저장을 위한 선언 

typedef struct __ArrayList
{
	// int 형으로 된 arr 배열 선언, 크기는 LIST_LEN 
	LData arr[LIST_LEN];
	int numOfData; // 저장된 데이터의 수 
	int curPosition; // 데이터 참조 위치(LData의 위치) 
} ArrayList;

typedef ArrayList List; // ArrayList는 (배열기반)List로 부른다. 
// 추후 링크드 리스트에는 typedef LikendList List로 사용 

void ListInit(List * plist); // 데이터 초기화 
void LInsert(List * plist, LData data); // 데이터 저장

int LFirst(List * plist, LData * pdata); // 첫 데이터 참조 
int LNext(List * plist, LData * pdata); // 두번째 이후 데이터 참조

LData LRemove(List * plist); // 참조 데이터 삭제
int LCount(List * plist); // 저장된 데이터 수 변환

#endif 
