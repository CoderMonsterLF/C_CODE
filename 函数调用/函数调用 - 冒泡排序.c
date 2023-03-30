//冒泡排序
void bubble_sort(int arr[],int sz) {
	int i = 0;
	//冒泡排序总次数
	for (i = 0; i < sz - 1; i++) {
		//一次冒泡排序的过程
		for (int j = 0; j < sz - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main() {
	int arr[] = { 1,3,2,4,6,5,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	
	int i = 0; 
	for (i = 0; i < sz; i++) {
		printf("%d", arr[i]);
	}
	
	return 0;
}