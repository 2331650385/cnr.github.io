#include<stdio.h>
#include<limits.h>

int matrix_chain_order(int p[], int n){
	int m[n][n],i,j,k,L,q;
	// ��ʼ���Խ��� 
	for(int i = 1;i < n;i++){
		m[i][i] = 0;                                                   
	}
	// L��Ҫ����������ⳤ�� 
	for (L = 2;L<n;L++){
		// i �����������ʼ���� 
		for(i = 1;i<n-L+1;i++){
			// j �����������ʼ���� 
			j = i + L -1;
			
			// ��ʼ����СֵΪ�������ֵ 
			m[i][j] = INT_MAX;
			// �������п��ܵ�����λ�ã�������С�˷����� 
			for (k = i;k<j; k++){
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if (q < m[i][j]){
					m [i][j] = q;
				}
			}
		}
	 
	}
	// ��ӡ����
	printf("�����ҵľ���:\n");
	for(i = 1;i<n;i++){
		for(j=1;j<n;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	} 
	return m[1][n-1];
}

int main(){
	int arr[] = {2,3,7,9,5,2,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("\n\t��С��������������%d",matrix_chain_order(arr,size));
	return 0;
}
