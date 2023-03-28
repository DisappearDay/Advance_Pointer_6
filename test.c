#include <stdio.h>

void swap(char* buf1,char* buf2,int width) {
	int i = 0;
	for (i = 0; i < width; i++) {
		char temp = 0;
		temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* arr,int sz,int width,int(*cmp_ia)( void*e1, void *e2)) {
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++) {
		for (j = 0; j < sz - 1 - i;j++) {
			if (cmp_ia((char*)arr + j * width, (char*)arr + (j + 1) * width)>0) {
				swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
			}
		}
	}
}

int cmp_ia(const void*e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;
}

void test111() {
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_ia);
	int i = 0;
	for (i = 0; i < sz;i++) {
		printf("%d ", arr[i]);
	}
}

struct Stu
{
	char name[20];
	int age;
};

int  cmp_st_name(const void* e1, const void* e2) {
	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}
int  cmp_st_age(const void* e1, const void* e2) {
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

test222() {
	struct Stu s[3] = { {"sunqingyang",23},{"liuzhou",20},{"chenyujie",21} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_st_age);
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%s ", s[i].name);
		printf("%d ", s[i].age);
	}
}

int main() {
	//test111();
	test222();
	return 0;
}
