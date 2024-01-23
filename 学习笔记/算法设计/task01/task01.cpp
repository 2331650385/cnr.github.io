#include <iostream>
using namespace std;
int jc1(int n){
	// 1.1.非递归求阶乘问题 
	int cnr = 1;  
	for(int i = 1;i<=n;i++){ //i取值[1,n] 
		cnr *=i; // 累乘 
	}
	return cnr;
}
int jc2(int n){
	// 1.2.递归求阶乘问题 
	if(n==1){
		return 1;
	}
	return n*jc2(n-1);
}
int fbi1(int n){
	// 2.1 递归求斐波那契数列 
	if(n==1||n==2){
		return 1;  //确定初始值是1和1开始用来递推fbi 
	}
	return fbi1(n-1) + fbi1(n-2);
}
int fbi2(int n){
	// 2.2 非递归求斐波那契数列 
    int a = 0;
    int b= 1;
    for(int i=0;i<n;i++){
    	int c; // 此变量c保存a的值 
    	c = a;
    	a = b;
    	b = c+b;
	}
	return a;
}
void han(int a, char x, char y, char z) { //  a是几块，xyz表示塔名 
	if (a == 1) {
		cout << x << "->" << z << endl;//剩余1个的时候直接从开始的移动到结束的
	}
	else {
		han(a - 1, x, z, y);
		cout << x << "->" << z << endl;
		han(a - 1, y, x, z);
	}
}

int main() 
{
	int t = 8;
    cout << jc1(t) << endl; 
    cout << jc2(t) << endl; 
    cout << fbi1(t) << endl; 
	cout << fbi2(t) << endl; 
	han(3, 'a', 'b', 'c');
    return 0;
}



