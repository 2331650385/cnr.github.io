#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i,j,max,cnt;
	printf("�����뵼����������");
	scanf("%d",&n);
	
	int daodan[n]; // �洢�����߶ȵ����� 
	int dp[n]; // ��̬�滮���飬�洢�Ե�ǰ������β��������������г��� 
	
	printf("�����뵼���߶ȣ��ո�ָ:");
	for(i = 0;i<n;i++){
		scanf("%d",&daodan[i]);
	}
	
	// ��ʼ����̬�滮���� 
	for(i = 0;i<n;i++){
		dp[i] =1;
		
	}
	
	
	for(i =1;i<n;i++){ // ��̬�滮���̣������������������ 
		for(j=0;j<i;j++){
			// �����߶Ȳ�����֮ǰ�ĵ����߶ȣ����Ըı�dp[i] 
			if(daodan[i]<=daodan[j]){ // if���
				if(dp[j]+1>dp[i])
					dp[i] = dp[j] + 1;
			}
		}
	}
	// ����ö�� ��̬�滮�����е���������صĵ������� 
	max = dp[0];
	for(i =1;i<n;i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}
	printf("%d(��������صĵ�����)",max);
	return 100;
}
