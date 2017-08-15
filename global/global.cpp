#include <iostream>
#include <sys/time.h>

using namespace std;

long get_time();

class A {
	long i;
public:
	void add(){ i++; }
};


long k = 0;

class B {
public:
	void add(){ k++; }
};

void add(){ k++; }


int main(){
	// test1
	int i = 0;
	long begin = get_time();
	for (long j = 0; j < 1000 * 1000 * 1000; j++) i++;
	long end = get_time();
	cout<<"Test1:"<<end-begin<<endl;

	// test2
	A a;
	begin = get_time();
	for (long j = 0; j < 1000 * 1000 * 1000; j++) a.add();
	end = get_time();
	cout<<"Test2:"<<end-begin<<endl;

	// test3
	B b;
	k = 0;
	begin = get_time();
	for (long j = 0; j < 1000 * 1000 * 1000; j++) b.add();
	end = get_time();
	cout<<"Test3:"<<end-begin<<endl;

	// test4
	k = 0;
	begin = get_time();
	for (long j = 0; j < 1000 * 1000 * 1000; j++) add();
	end = get_time();
	cout<<"Test4:"<<end-begin<<endl;
}

long get_time(){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}
