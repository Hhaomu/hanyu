/*
 * 实现一个list类命名为MyList，其功能与python数组类似。可以用数组实现，也可以用链表实现。
 * 必须使用template <class T>，不允许使用<iostream>以外的库。
 * 需要实现的功能与测试代码见下。请务必搞清楚每一项的意义，比如什么时候需要用友元函数什么时候需要const什么时候需要&。
 * 当某些由用户正常操作可能产生的run time error（如pop一个空数组，或访问一个超出下标的元素），
 * 请使用try-catch-throw处理错误。
 * 以下类定义不保证完全正确，请根据实际需求修改，以实现样例功能为主。
 */

/* 
 * 本练习不涉及到虚类和类继承，但是期末考试我就不知道了。如果有时间可以用书上的shape类来练习。
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
	friend MyList<T> operator + <>(const MyList<T> &, const MyList<T> &);//合并两个MyList√
    friend MyList<T> operator + <>(const MyList<T> &, const T &); //同push(T item)，但不修改l1，返回一个新数组√
    friend ostream& operator << <>(ostream &, const MyList<T> &);//如果T是可以直接cout的类的话（比如int），按Python数组的格式输出MyList中的每一个元素，例如：
    // [1, 2, 5, 4, 1]√

private:
	int final;
	T *a;
	int size;

	void double_space(){                                           //数组大小不够的时候将数组大小翻倍的操作。√
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
	MyList(int num, const T &item){                                     //将item重复num次填入数组中。√ 
		size = num;
		a = new T [num];
		final = num;
		for(int i=0;i<num;++i) a[i] = item;
	}
	MyList(const MyList &l){                                            //复制另外一个MyList。√
		size = l.final;
		a = new T [l.final];
		final = l.final;
		for(int i=0;i<l.final;++i) a[i] = l.a[i];
	}
    MyList(T *arr, int len){                                            //以arr的前len个元素构造数组 √
    	size = len;
		a = new T [len];
    	final = len;
		for(int i=0;i<len;++i) a[i] = arr[i];
	}

	void push(const T &item){                                           //将item添加在MyList最后。√
		if(final >= size) double_space();
		a[final] = item;
		++final;
	}
	
	T pop(){                                                             //将MyList中最后一个元素删除，并返回这个删除的元素。√
		int s=a[final];
		a[final] = 0;
		--final;
		return s;
	}
	void insert(int index, const T &item){                               //将item插入到place处。√
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
	void clean(){                                                        //清空数组。√
		delete [] a;
		a = new T[0];
		final = 0;
	}
	int get_size(){                                                      //返回MyList中元素的数量。√
		return final;
	}
	void erase(int start, int end){                                      //删除MyList中第start到第end位的元素，包括两边。√
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
	
	T get_item(int index){                                               //返回第index个元素。√
		try	{
			if(index >= (-1)*final && index < final) return a[index];
			else throw 1;
		}
		catch(int) {cout << "0ut of range!!!" << endl;}		
	}
	
	MyList get_item(int start, int end){                                 //返回MyList中第start到第end位的元素，包括两边。此处需要像python一样接受负数，具体见测试代码。√
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
	int count(const T &item){                                            //返回MyList中和item相等的元素的个数。√
		int counter;
		for(int i=0;i<final;++i){
			if (a[i] == item) ++counter;
		}
		return counter;
	}
	void remove(const T &item){                                          //删除MyList中第一个和item相等的元素。√
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

	MyList &operator = (const MyList &l){                                 //赋值√
		if (this == &l) return *this;
		final = l.final;
		delete [] a;
		a = new T [final];
		for (int i=0;i<final;++i) a[i] = l.a[i];
		return *this;
	}
	
	MyList &operator += (const T &item){                                   //同push(T item)√
		if (final>=size) double_space();
		a[final] = item;
		++final;
		return *this;
	}
	
	MyList &operator += (const MyList &l){                                 //将一个MyList加入到本个MyList之后。√
		int m=final,i;
		final = l.final + m;
		for(i=m;i<final;++i){ 
			if (final >= size) double_space();
			a[i] = l.a[i-m];
		}
		return *this;
	}
	
	T &operator [](int index){                                              //返回第index个元素。√
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
	void sort(bool less=true){                                              //实现一个快速排序或归并排序，对支持比较运算符（>=<）的类进行排序。√
		quicksort (a,0,final);
		if(!less){
			int a1[final];
			for (int i=0;i<final;++i)	a1[i] = a[final-i];
			for (int i=0;i<final;++i)	a[i] = a1[i];
		}
	}

	void reverse(){                                                         //将MyList的元素倒过来。√
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
    b = a.get_item(4, -3); // b = [] *若start > end，返回空数组
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

