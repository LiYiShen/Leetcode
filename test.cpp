#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    const int local = 10;
    int *ptr = (int *)&local;
    printf("%d \n", local);
    cout << local << endl;
    *ptr = 100;
    printf("%d \n", local);
    printf("%d \n", *ptr);
    system("pause");
    return 0;
}

-------------------------------------------
Vscode
���ƶ���Alt + ��/��
�и��ƣ�Shift + Alt + ��/��
��ע�ͣ�Shit + Alt + A
����/��������Ctrl + ]/[
�л�����һ��/��һ���ļ��༭�㣺Alt + �� / ��
��ת����Ӧ����λ�ã�Ctrl + Shift + \
��/�۵���������Ctrl + Shift + [/]
���붨���Ը�����ʽ�����ڵ�ǰҳ���ϣ�Alt + F12
��ת�����붨��λ�ã�F12
�ļ��ڲ���/�滻��Ctrl + F / H
�������ڲ���/�滻��Ctrl + Shift + F / H
�򿪵�����壺Ctrl + Shift + D