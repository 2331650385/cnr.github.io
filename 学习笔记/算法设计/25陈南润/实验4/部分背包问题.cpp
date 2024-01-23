#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int value;
	int weight;
	double ratio;
} Item;

// 比较函数，按性价比降序排序物品 
int cmp(const void *a,const void *b){
	Item *ia = (Item *)a;
	Item *ib = (Item *)b;
	return ia->ratio < ib->ratio ? 1:-1; 
}

// 计算背包容量的最大价值 
double fractional_knapsack(int n,Item items[],int C){
	// 计算每个物品的性价比 
	for (int i = 0;i<n;i++){
		items[i].ratio = (double)items[i].value / items[i].weight;
	}
	// 性价比降序排列 
	qsort(items,n,sizeof(Item),cmp);
	double max_value = 0.0;
	for (int i = 0; i<n&&C>0; i++){
		int weight = items[i].weight < C ? items[i].weight :C;
		max_value += (double) items[i].value / items[i].weight;
		C-=weight;
	}
	return max_value;
}

int main(){
	int n,C;
	printf("输入商品数量n");
	scanf("%d",&n);
	Item *items = (Item *)malloc(n * sizeof(Item)); 
	printf("输入商品价值：");
	for(int i = 0;i<n;i++){
		scanf("%d %d",&items[i].value,&items[i].weight);
	}
	printf("输入背包容量C：");
	scanf("%d",&C);
	printf("商品价值的最大值：%.2f\n",fractional_knapsack(n,items,C));
	return 0;
}
