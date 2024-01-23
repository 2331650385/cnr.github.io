#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int value;
	int weight;
	double ratio;
} Item;

// �ȽϺ��������Լ۱Ƚ���������Ʒ 
int cmp(const void *a,const void *b){
	Item *ia = (Item *)a;
	Item *ib = (Item *)b;
	return ia->ratio < ib->ratio ? 1:-1; 
}

// ���㱳������������ֵ 
double fractional_knapsack(int n,Item items[],int C){
	// ����ÿ����Ʒ���Լ۱� 
	for (int i = 0;i<n;i++){
		items[i].ratio = (double)items[i].value / items[i].weight;
	}
	// �Լ۱Ƚ������� 
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
	printf("������Ʒ����n");
	scanf("%d",&n);
	Item *items = (Item *)malloc(n * sizeof(Item)); 
	printf("������Ʒ��ֵ��");
	for(int i = 0;i<n;i++){
		scanf("%d %d",&items[i].value,&items[i].weight);
	}
	printf("���뱳������C��");
	scanf("%d",&C);
	printf("��Ʒ��ֵ�����ֵ��%.2f\n",fractional_knapsack(n,items,C));
	return 0;
}
