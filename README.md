## Leetcode

- `��̬�滮`�ĺ�����������٣���������������ڡ��ص������⡹�����������ٵĻ�Ч�ʻἫ����£�������Ҫ������¼�����ߡ�DP table�����Ż���ٹ��̡�

- ��ȷ base case --> ��ȷ��״̬��--> ��ȷ��ѡ�� --> ���� dp ����/�����ĺ��塣

- ��̬�滮��ܣ�

  ```
  ��ʼ�� base case
  dp[0][0][...] = base
  ����״̬ת��
  for ״̬1 in ״̬1������ȡֵ��
      for ״̬2 in ״̬2������ȡֵ��
          for ...
              dp[״̬1][״̬2][...] = ����ֵ(ѡ��1��ѡ��2...)
  ```


- `��������`��ʵ���Ͼ���һ���������ı������̣������ʾ��˻���һ����ͨ��Լ������, ����ʱ�临�Ӷȡ�

- �����㷨��DFS���Ŀ�ܣ�

  ```
  result = []
  def backtrack(·��, ѡ���б�):
      if �����������:
          result.add(·��)
          return
       for ѡ�� in ѡ���б�:
       	��ѡ��
       	����ѡ���ѡ���б��Ƴ�
      	·��.add(ѡ��)
      	backtrack(·��, ѡ���б�)
      	����ѡ��
      	·��.remove(ѡ��)
      	����ѡ���ټ���ѡ���б�
  ```


- `BFS`���ʣ���һ����㣬�ߵ��յ㣬�����·����

  ```
  // �������� start ���յ� target ���������
  int BFS(Node start, Node target) {
      queue<Node> q; 		// �������ݽṹ
      Set<Node> visited;  // �����߻�ͷ·
  	q.push(start); 		// �����������
  	visited.add(start);
  	int step = 0; 		// ��¼��ɢ�Ĳ���
  	while (q not empty) {
      int sz = q.size();
      /* ����ǰ�����е����нڵ���������ɢ */
      for (int i = 0; i < sz; i++) {
          Node cur = q.pop();
          if (cur is target)	// �ж��Ƿ񵽴��յ�
              return step;
          for (Node x : cur.adj()) // ��cur���ڽڵ����
              if (x not in visited) {
                  q.push(x);
                  visited.add(x);
              }
      }
      step++;		// ���²���
  }
  ```

## Python�﷨��

- `str[::-1]`��ȡ�Ӻ���ǰ���෴����Ԫ��

- `str[len(str)-1::-1]`�� ȡ���±�Ϊ`len(str)-1`��Ԫ�ط�ת��ȡ

- `range(len-1,-1,-1)`������
  `(start,end,step)`����ʼλ�ã�Ĭ��0��������λ�ã�������Ĭ��1��

- `zip()`���ѿɵ���������Ϊ�������������ж�Ӧ��Ԫ�ش����һ����Ԫ�飬������ЩԪ����ɵ��б�

  ```python
  str = ['a', 'b', 'c', 'd', 'e','f']
  print(zip(str[:-1], str[1:]))
  
  [('a', 'b'), ('b', 'c'), ('c', 'd'), ('d', 'e'), ('e', 'f')]
  
  nums = ['flower','flow','flight']
  for i in zip(*nums):
      print(i)
  
  ('f', 'f', 'f')
  ('l', 'l', 'l')
  ('o', 'o', 'i')
  ('w', 'w', 'g')
  ```

- `sorted(iterable, cmp=None, key=None, reverse=False)`

  - `iterable `-- �ɵ�������
  - `cmp` -- �Ƚϵĺ���
  - `key` -- ��Ҫ���������бȽϵ�Ԫ�أ�ֻ��һ������
  - `reverse` -- reverse = False ����Ĭ�ϣ�
  - `sort()`��Ӧ����`list`�ϵķ�����`sorted()`���Զ����пɵ����Ķ���������������
  - `list`��`sort()`�Ƕ��Ѿ����ڵ��б���в������޷���ֵ�����ڽ�����`sorted()`�������ص���һ���µ�`list`��������ԭ���Ļ����Ͻ��еĲ�����

## C++:

- `C++11`������`nullptr`�ؼ��֣���ͬ��`NULL`����궨�塣��`C++`��`NULL`ֱ�Ӷ���Ϊ`0`������`C`�`NULL`����Ϊ`(void*)0`����ΪC���Կ�����ʽת������C++ȴ����Ҫ��ʾ��д������ת�������Ǵ���һ�����⣬һ��`int`���ͱ����ں�������ʱ���ض�����ַ�Ԥ�ڵĽ����
  - `func(NULL) --> int`; `func(nullptr) --> char *`��
- `#include<queue>`��
  - `push()`��`pop()`��`size()`��`empty()`��`front()`��`back()`
- `string.substr(pos, n)`��`pos`Ĭ��ֵ0��`n`Ĭ��ֵ`s.size() - pos`
  - `s.substr(1))`�� ȡ�Ӵ�������ȥ���ַ������ַ�
- `lower_bound()`��`upper_bound()`�������ö��ֲ��ҵķ�����һ���ź���������н��в��ҡ�
  - `lower_bound(begin, end, num)`���������`begin`λ�õ�`end-1`λ�ö��ֲ��ҵ�һ�����ڻ����`num`�����֣��ҵ����ظ����ֵĵ�ַ���������򷵻�`end`��ͨ�����صĵ�ַ��ȥ��ʼ��ַ`begin`���õ��ҵ������������е��±ꡣ
- `map`��`set`�ĵײ�ʵ��Ϊƽ���������`unordered_map`��`unordered_set`�ĵײ�ʵ��Ϊ��ϣ��
- �����`C++98`��׼��`C++11`���͵����ı���Ƕ���` long long`����Ϊ���֣�`long long`��`unsigned long long`����`C++11`�У���׼Ҫ��`long long`���Ϳ����ڲ�ͬƽ̨���в�ͬ�ĳ��ȣ���������`64λ`����`long long`������ص�һ����3����`LONG_MIN`��`LONG_MAX`��`ULONG_MAX`���ֱ����ƽ̨����С��`long long`ֵ������`long long `ֵ���Լ����� `unsigned long long`ֵ��