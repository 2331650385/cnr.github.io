#include<stdio.h>
#include<limits.h>

int matrix_chain_order(int p[], int n){
	int m[n][n],i,j,k,L,q;
	// 初始化对角线 
	for(int i = 1;i < n;i++){
		m[i][i] = 0;                                                   
	}
	// L是要计算的子问题长度 
	for (L = 2;L<n;L++){
		// i 是子问题的起始索引 
		for(i = 1;i<n-L+1;i++){
			// j 是子问题的起始索引 
			j = i + L -1;
			
			// 初始化最小值为最大整数值 
			m[i][j] = INT_MAX;
			// 遍历所有可能的括号位置，计算最小乘法次数 
			for (k = i;k<j; k++){
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if (q < m[i][j]){
					m [i][j] = q;
				}
			}
		}
	 
	}
	// 打印矩阵
	printf("这是我的矩阵:\n");
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
	printf("\n\t最小矩阵连乘数量：%d",matrix_chain_order(arr,size));
	return 0;
}
