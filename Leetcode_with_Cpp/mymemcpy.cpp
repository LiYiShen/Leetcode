/* ����ԭ��:
 * void *memcpy(void *dst, const void *src, size_t n)
 * �Ӵ洢�� src ���� n ���ֽڵ��洢�� dst
 * 1.��Ҫ�ƻ����������βΣ������µ���ʱ����������
 * 2.����ָ�����ͣ���ͬ����ָ�벻��ֱ�� ++ ��ֵ
 * 3.overlap�������Ҫ�Ӹߵ�ַ����ǰcopy
 */
#include <iostream>
#include <cstring>
using namespace std;

void *mymemcpy(void *dst, const void *src, size_t size) {
    if (NULL == dst || NULL == src) return NULL;
    if (dst == src) return dst;
    char *d;
    const char *s;
    int n = static_cast<int>(size);
    if (dst < src || (char *)dst >= ((char *)src + n)) {
        d = (char *)dst;
        s = (char *)src;
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d = (char *)dst + n - 1;
        s = (char *)src + n - 1;
        while (n--) {
            *d-- = *s--;
        }
    }
    return dst;
}

int main() {
    const char src[] = "www.tencent.com";
    char dst[32];
    mymemcpy(dst, src, strlen(src) + 1);
    cout << dst << endl;
    system("pause");
    return 0;
}