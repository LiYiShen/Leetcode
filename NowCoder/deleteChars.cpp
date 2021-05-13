#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

// ɾ��first�����г�����second�е��ַ�
char *deleteChars(char *first, char *second) {
	assert((NULL != first) && (NULL != second));
	// ����ַ��Ƿ����ַ���second�г��ֹ�
	const int tableSize = 256;
	bool hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));
	while (*second != '\0') {
		if (!hashTable[*second]) {
			hashTable[*second] = true;
		}
		second ++;
	}
	char *fast = first;
	char *slow = first;
	while (*fast != '\0') {
		if (!hashTable[*fast]) {
			*slow = *fast;
			++ slow;
		}
		++ fast;
	}
	*slow = '\0';
	return first;
}

void test1() { // second�е��ַ�û�г�����first�е�
	cout << "*****test1 second�е��ַ�û�г�����first�е�:*****";
	char text[] = "abcdbbad";
	char *first = text;
	char second[] = "lmni";
	first = deleteChars(first, second);
	cout << first << endl;
}

void test2() { // second�е��ַ��г�����first�е�
	cout << "*****test1 second�е��ַ��г�����first�е�:*****";
	char text[] = "abcdbbad";
	char *first = text;
	char second[] = "adfghb";
	first = deleteChars(first, second);
	cout << first << endl;
}

int main() {
	test1();
	test2();
    system("pause");
	return 0;
}