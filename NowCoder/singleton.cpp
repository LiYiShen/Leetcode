/* ����ģʽ����ֻ����һ��ʵ��������
 * ���캯��˽�л����ܱ���;
 * ���徲̬����
 * ���徲̬���к���;
 */
// ����ʽ��һ��ʼ�ͽ���ʵ����
class Singleton {
private:
	Singleton(){}
	static Singleton* Instance;
public:
	static Singleton* GetInstance() {
		return Instance;
	}
};
Singleton* Singleton::Instance = new Singleton;  // �ڳ������ǰ��ɵ��������ʼ��


// ����ʽ����һ���õ���ʵ��ʱ��ȥʵ���� (���̲߳���ȫ --> ����ʹ���ٽ���CRITICAL_SECTION�򻥳���MUTEX��ʵ���߳���)
class Singleton {
private:
	Singleton(){}
	static Singleton* Instance;
public:
	static Singleton* GetInstance() {
        // Lock();
		if (Instance == NULL) {
			Instance = new Singleton;
		}
        // UnLock();
		return Instance;
	}
};
Singleton* Singleton::Instance = NULL;

// ��ĳ���߳�Ҫ����ʱ�����������������²���Ҫ���������ġ�
// ���Կ������ж�ʵ���Ƿ���ڣ��ٽ����Ƿ������Ĳ�������˫�����(DCL)˼�롣
static Singleton* GetInstance() {
	if (Instance == NULL) {
        Lock();
        if (Instance == NULL) {
            Instance = new Singleton;
        }
		UnLock();
	}

	return Instance;
}
// ����: m_pInstance = new CSingleton()��仰���Էֳ�����������ִ��:
// 1.������һ��CSingleton���Ͷ�������Ҫ���ڴ档
// 2.�ڷ�����ڴ洦����CSingleton���͵Ķ���
// 3.�ѷ�����ڴ�ĵ�ַ����ָ��m_pInstance��
// ���ܻ���Ϊ�����������ǰ�˳��ִ�е�,��ʵ����ֻ��ȷ������ 1 ������ִ�е�,����2,3ȴ��һ����
// ����ͳ������⡣����ĳ���߳�A�ڵ���ִ��m_pInstance = new CSingleton()��ʱ���ǰ���1, 3, 2��˳���,
// ��ô�ո�ִ���경��3��singleton���ͷ������ڴ�(��ʱm_ instance�Ͳ���nullptr�� )���л������߳�B,
// ����m_pInstance�Ѿ�����nullptr��,�����߳�B��ֱ��ִ��return m_ instance�õ�һ������,���������û�������ı�����! !
// ����bug����ô�����ˡ�

// ��Effective C++��ϵ���鼮������ Meyers�����C++ 11�汾����Ŀ�ƽ̨����
class Singleton {
private:
    Singleton(){}
public:
    static Singleton & GetInstance() {
        static Singleton Instance;  //�ֲ���̬����
        return Instance;
    }
};