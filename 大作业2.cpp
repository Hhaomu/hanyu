/*
 * ʵ��һ��list������ΪMyList���书����python�������ơ�����������ʵ�֣�Ҳ����������ʵ�֡�
 * ����ʹ��template <class T>��������ʹ��<iostream>����Ŀ⡣
 * ��Ҫʵ�ֵĹ�������Դ�����¡�����ظ����ÿһ������壬����ʲôʱ����Ҫ����Ԫ����ʲôʱ����Ҫconstʲôʱ����Ҫ&��
 * ��ĳЩ���û������������ܲ�����run time error����popһ�������飬�����һ�������±��Ԫ�أ���
 * ��ʹ��try-catch-throw�������
 * �����ඨ�岻��֤��ȫ��ȷ�������ʵ�������޸ģ���ʵ����������Ϊ����
 */

/* 
 * ����ϰ���漰���������̳У�������ĩ�����ҾͲ�֪���ˡ������ʱ����������ϵ�shape������ϰ��
 */

#include<iostream>
using namespace std;
template<class T>
class MyList;

template<class T>
MyList<T> operator +(const MyList<T> &l1, const MyList<T> &l2){
	MyList<T> list(l1);
	for(int i=0;i<l2.final;++i)	list.push(l2.a[i]);
	return list;	
}

template<class T>
MyList<T> operator +(const MyList<T> &l1, const T &item){
	MyList<T> list(l1);
	list.push(item);
	return list;
}

template<class T>
ostream & operator<<(ostream &os, const MyList<T> &obj){
	os << endl;
	for(int j=0;j<obj.final;++j) os << obj.a[j] << '\t';
	return os;
}

template<class T>
class MyList{
	friend MyList<T> operator + <>(const MyList<T> &, const MyList<T> &);//�ϲ�����MyList��
    friend MyList<T> operator + <>(const MyList<T> &, const T &); //ͬpush(T item)�������޸�l1������һ���������
    friend ostream& operator << <>(ostream &, const MyList<T> &);//���T�ǿ���ֱ��cout����Ļ�������int������Python����ĸ�ʽ���MyList�е�ÿһ��Ԫ�أ����磺
    // [1, 2, 5, 4, 1]��

private:
	int final;
	T *a;
	int size;

	void double_space(){                                           //�����С������ʱ�������С�����Ĳ�������
		size = size * 2;
		T *b;
		b = new T[size];
		for(int i=0;i<size/2;++i)    b[i] = a[i];
		for(int i=size/2;i<size;++i) b[i] = 0;
		delete [] a;
		a = b;
	}


	
public:
	MyList(){
		size = 100;
		a = new T [size];
		final=0;
	}
	MyList(int num, const T &item){                                     //��item�ظ�num�����������С��� 
		size = num;
		a = new T [num];
		final = num;
		for(int i=0;i<num;++i) a[i] = item;
	}
	MyList(const MyList &l){                                            //��������һ��MyList����
		size = l.final;
		a = new T [l.final];
		final = l.final;
		for(int i=0;i<l.final;++i) a[i] = l.a[i];
	}
    MyList(T *arr, int len){                                            //��arr��ǰlen��Ԫ�ع������� ��
    	size = len;
		a = new T [len];
    	final = len;
		for(int i=0;i<len;++i) a[i] = arr[i];
	}

	void push(const T &item){                                           //��item�����MyList��󡣡�
		if(final >= size) double_space();
		a[final] = item;
		++final;
	}
	
	T pop(){                                                             //��MyList�����һ��Ԫ��ɾ�������������ɾ����Ԫ�ء���
		int s=a[final];
		a[final] = 0;
		--final;
		return s;
	}
	void insert(int index, const T &item){                               //��item���뵽place������
		try{
			if(index >= (-1)*final&&index <= final){
				if (final>=size) double_space();
				for(int i=final;i>index;--i) a[i] = a[i-1];
				a[index] = item;
				++final;
			}
				else throw 1;
		}
		catch(int) {cout << "Out of Range!" << endl;}
	}
	void clean(){                                                        //������顣��
		delete [] a;
		a = new T[0];
		final = 0;
	}
	int get_size(){                                                      //����MyList��Ԫ�ص���������
		return final;
	}
	void erase(int start, int end){                                      //ɾ��MyList�е�start����endλ��Ԫ�أ��������ߡ���
		try	{
		 	if(start >= (-1)*final && start < final && end >= (-1) * final && end < final){
				int i;
				for(i=start;i<final-end+start-1;++i) a[i] = a[i+end-start+1];
				int x = i;
				for(i=x;i<final;++i) a[i] = NULL;
				final = final - (end - start + 1);
			}
			else throw 1;
		}
		catch(int) {cout << "Out of range!!" << endl;}
	}
	
	T get_item(int index){                                               //���ص�index��Ԫ�ء���
		try	{
			if(index >= (-1)*final && index < final) return a[index];
			else throw 1;
		}
		catch(int) {cout << "0ut of range!!!" << endl;}		
	}
	
	MyList get_item(int start, int end){                                 //����MyList�е�start����endλ��Ԫ�أ��������ߡ��˴���Ҫ��pythonһ�����ܸ�������������Դ��롣��
		try	{
			if(start>= (-1)*final && start < final && end >= (-1)*final && end < final){
				if (start<0)	start = final + start;
				if (end<0)		end = final + end;
				if (start>end){
					T tmp[0];
					MyList tmp1(tmp,0);
					return tmp1;
				}
				T tmp[end-start+1];
				for (int i=0;i<end-start+1;++i) tmp[i] = a[start+i];
				MyList tmp1(tmp,end-start+1);
				return tmp1;
			}
			else throw 1;
		}
		catch (int) {cout << "Out of range!!!!" << endl;}
	}
	int count(const T &item){                                            //����MyList�к�item��ȵ�Ԫ�صĸ�������
		int counter;
		for(int i=0;i<final;++i){
			if (a[i] == item) ++counter;
		}
		return counter;
	}
	void remove(const T &item){                                          //ɾ��MyList�е�һ����item��ȵ�Ԫ�ء���
		bool flag = false;
		int i;
		for(i = 0;i<final;++i){
			if(a[i] == item){
				flag = true;
				break;
			}
		}
		if(!flag) return;
		else{
			int del=i;
			for(i=del;i<final-1;++i) a[i] = a[i+1];
			--final;
			return;
		}
	}

	MyList &operator = (const MyList &l){                                 //��ֵ��
		if (this == &l) return *this;
		final = l.final;
		delete [] a;
		a = new T [final];
		for (int i=0;i<final;++i) a[i] = l.a[i];
		return *this;
	}
	
	MyList &operator += (const T &item){                                   //ͬpush(T item)��
		if (final>=size) double_space();
		a[final] = item;
		++final;
		return *this;
	}
	
	MyList &operator += (const MyList &l){                                 //��һ��MyList���뵽����MyList֮�󡣡�
		int m=final,i;
		final = l.final + m;
		for(i=m;i<final;++i){ 
			if (final >= size) double_space();
			a[i] = l.a[i-m];
		}
		return *this;
	}
	
	T &operator [](int index){                                              //���ص�index��Ԫ�ء���
		return a[index];
	}


	int divide (int a[],int low,int high){
		T m = a[low];
		do{
			while (low < high && a[high] >= m) --high;
			if(low < high) {a[low] = a[high];++low;}
			while (high > low && a[low]  <= m) ++low;
			if(low < high) {a[high] = a[low];--high;}
		}while(low < high);
		a[low] = m;
		return low;
	}
	void quicksort (int a[],int low,int high){
		int mid;
		if (low >= high) return;
		mid = divide (a,low,high);
		quicksort (a,low,mid-1);
		quicksort (a,mid+1,high);
	}
	//void quicksort (int a[],int low,int high){
		//int i,j;
		//T temp=a[low];
		//for(j=0;j<final;j++){
  			//for(i=j+1;i<final;i++){
				//if(a[j]>=a[i]){
  					//temp=a[j];
  					//a[j]=a[i];
  					//a[i]=temp;
				//}
  			//}
 		//}
	//}	
	void sort(bool less=true){                                              //ʵ��һ�����������鲢���򣬶�֧�ֱȽ��������>=<������������򡣡�
		quicksort (a,0,final);
		if(!less){
			int a1[final];
			for (int i=0;i<final;++i)	a1[i] = a[final-i];
			for (int i=0;i<final;++i)	a[i] = a1[i];
		}
	}

	void reverse(){                                                         //��MyList��Ԫ�ص���������
		T *a1;
		a1 = new T[final];
		for(int i=0;i<final;++i)	a1[i] = a[final-i];
		delete [] a;
		a = a1;
	}

	~MyList(){delete [] a;}
};



int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i);
    // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	a.sort(); // a = [0, 1, 2, 4, 15]
	a.reverse(); // a = [15, 4, 2, 1, 0]
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a[i]<<endl;
    b = a.get_item(4, -3); // b = [] *��start > end�����ؿ�����
	b = a.get_item(3, -1); // b = [1, 0, 12] 
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean(); // b = []
	cout<<b.get_size()<<endl;
	a.erase(2, 5); // a = [15, 4, 0, 12]
	b = a + a; // b = [15, 4, 0, 12, 15, 4, 0, 12]
	b.insert(3, 116); // b = [15, 4, 0, 116, 12, 15, 4, 0, 12]
	b.remove(4); // b = [15, 0, 116, ...]
	cout<<b<<endl;
	MyList<double> c(10, 3.14);
	for (i=0; i<100; ++i)
		c.push(1.1*i);
	cout<<c.get_item(100, 105)<<endl;
	
	return 0;
}

