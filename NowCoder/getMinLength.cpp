/* ����һ����������arr�������Ҫ��������������ĳ��ȣ����������������ʹ�������������򣬼�Ϊ��Ҫ��������顣
���磺arr=[1,5,3,4,2,6,7]����4����Ϊֻ��[5,3,4,2]��Ҫ���� */

int getMinLength(int *arr) {
    if (!arr || arr.size() < 2) return 0;
    int minValue = arr[arr.size() - 1];
    int noMinIndex = -1;
    for (int i = arr.size() - 2; i != -1; i--) {
        if (arr[i] > minValue) {
            noMinIndex = i;
        } else {
            minValue = min(minValue, arr[i]);
        }
    }
    if (noMinIndex == -1) return 0;
    int maxValue = arr[0];
    int noMaxIndex = -1;
    for (int i = 1; i != arr.size(); i++) {
        if (arr[i] < maxValue) {
            noMaxIndex = i;
        } else {
            maxValue = max(maxValue, arr[i]);
        }
    }
    return noMaxIndex - noMinIndex + 1;
}