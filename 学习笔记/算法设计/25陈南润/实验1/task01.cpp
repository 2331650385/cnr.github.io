#include <iostream>
using namespace std;
int jc1(int n){
	// 1.1.�ǵݹ���׳����� 
	int cnr = 1;  
	for(int i = 1;i<=n;i++){ //iȡֵ[1,n] 
		cnr *=i; // �۳� 
	}
	return cnr;
}
int jc2(int n){
	// 1.2.�ݹ���׳����� 
	if(n==1){
		return 1;
	}
	return n*jc2(n-1);
}
int fbi1(int n){
	// 2.1 �ݹ���쳲��������� 
	if(n==1||n==2){
		return 1;  //ȷ����ʼֵ��1��1��ʼ��������fbi 
	}
	return fbi1(n-1) + fbi1(n-2);
}
int fbi2(int n){
	// 2.2 �ǵݹ���쳲��������� 
    int a = 0;
    int b= 1;
    for(int i=0;i<n;i++){
    	int c; // �˱���c����a��ֵ 
    	c = a;
    	a = b;
    	b = c+b;
	}
	return a;
}
void han(int a, char x, char y, char z) { //  a�Ǽ��飬xyz��ʾ���� 
	if (a == 1) {
		cout << x << "->" << z << endl;//ʣ��1����ʱ��ֱ�Ӵӿ�ʼ���ƶ���������
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



