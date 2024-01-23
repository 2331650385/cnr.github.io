#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HuffmanNode{
	char data;
	int freq;
	struct HuffmanNode *left,*right;
} HuffmanNode;

typedef struct MinHeap{
	int size;
	int capacity;
	HuffmanNode **array;
} MinHeap;

HuffmanNode *newNode(char data,int freq){
	HuffmanNode *temp = (HuffmanNode *)malloc(sizeof(HuffmanNode));
	temp->data = data;
	temp->freq = freq;
	temp->left = temp->right = NULL;
	return temp;
}

MinHeap *createMinHeap(int capacity){
	MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (HuffmanNode **)malloc(minHeap->capacity * sizeof(HuffmanNode *));
	return minHeap;
}

void insertMinHeap(MinHeap *minHeap,HuffmanNode *minHeapNode){
	int i =minHeap->size++;
	while(i && minHeapNode -> freq < minHeap->array[(i-1) / 2] -> freq){
		minHeap->array[i] = minHeap->array[(i-1)/2];
		i = (i-1)/2;
	}
	minHeap -> array[i] = minHeapNode;
}

void minHeapify(MinHeap *minHeap,int idx){
	int smallest = idx;
	int left = 2*idx + 1;
	int right = 2* idx + 2;

	if(left<minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if(smallest != idx){
		HuffmanNode *t = minHeap -> array[smallest];
		minHeap->array[smallest] = minHeap -> array[idx];
		minHeap->array[idx] = t;
		minHeapify(minHeap,smallest);
	}
}

HuffmanNode *extractMin(MinHeap *minHeap){
	HuffmanNode *temp=minHeap->array[0];
	minHeap->array[0] = minHeap->array[--minHeap->size];
	minHeapify(minHeap,0);
	return temp;
}

HuffmanNode *Huffman(int freq[],char data[],int n){
	MinHeap *minHeap = createMinHeap(n);
	for(int i =0;i<n;++i){
		insertMinHeap(minHeap,newNode(data[i],freq[i]));
	}
	while (minHeap -> size != 1){
		HuffmanNode *left = extractMin(minHeap);
		HuffmanNode *right = extractMin(minHeap);

		HuffmanNode *top =newNode('$',left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap,top);
	}
	return extractMin(minHeap);
}

void printCodes(struct HuffmanNode *root,int arr[],int top){
	if(root->left){
		arr[top]=0;
		printCodes(root->left,arr,top+1);
	}
	if(root->right){
		arr[top] = 1;
		printCodes(root->right,arr,top+1);
	}
	if(!root->left && !root->right){
		printf("%c: ",root->data);
		for(int i =0;i<top;++i){
			printf("%d",arr[i]);
		}
		printf("\n");
	}
}
int main(){
	char data[] = {'a','b','c','d','e','f'};
	int freq[] = {5,9,12,13,16,45};
	int n = sizeof(data) / sizeof(data[0]);
	HuffmanNode *huffmanTree = Huffman(freq,data,n);
	int arr[100];
	printCodes(huffmanTree,arr,0);
	getchar();
	return 0;
}