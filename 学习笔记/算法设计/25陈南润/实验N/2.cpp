#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,i,j,max,cnt;
	printf("请输入导弹的数量：");
	scanf("%d",&n);
	
	int daodan[n]; // 存储导弹高度的数组 
	int dp[n]; // 动态规划数组，存储以当前导弹结尾的最长不上升子序列长度 
	
	printf("请输入导弹高度（空格分割）:");
	for(i = 0;i<n;i++){
		scanf("%d",&daodan[i]);
	}
	
	// 初始化动态规划数组 
	for(i = 0;i<n;i++){
		dp[i] =1;
		
	}
	
	
	for(i =1;i<n;i++){ // 动态规划过程，计算最长不上升子序列 
		for(j=0;j<i;j++){
			// 导弹高度不高于之前的导弹高度，则尝试改变dp[i] 
			if(daodan[i]<=daodan[j]){ // if语句
				if(dp[j]+1>dp[i])
					dp[i] = dp[j] + 1;
			}
		}
	}
	// 暴力枚举 动态规划数组中的最多能拦截的导弹数量 
	max = dp[0];
	for(i =1;i<n;i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}
	printf("%d(最多能拦截的导弹数)",max);
	return 100;
}
