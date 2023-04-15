#include <stdio.h>
#include <stdlib.h>

//定义字符串节点结构
typedef struct String{
	char* data;
	int len;
}String;

String* initString(){
	String* string = (String*)malloc(sizeof(String));
	string -> data = NULL;
	string -> len = 0;

	return string;
}

void stringAssign(String* string, char* data){

	if(string -> data){

		free(string -> data);
	}

	int len = 0;
	char* s = data;

	while(*s){
		len++;
		s++;
	};

	if(len == 0){

		string -> data = NULL;
		string -> len = 0;

	}else{

		s = data;
		string -> len = len;
		string -> data = (char*)malloc(sizeof(char) * (len + 1));
		int i;
		for(i = 0; i < len; i++, s++){
			string -> data[i] = *s;
		}

	}
}

//遍历字符串
void printString(String* string){

	int i;
	for (i = 0; i < string -> len; i++){
		/* code */
		printf("%c", string -> data[i]);
	}
	printf("\n");
}

//KMP算法


//得到next数组
int* getNext(String* string){
	int* next = (int*)malloc(sizeof(int) * string -> len);
	int i = 0;
	int j = -1;
	next[i] = j;
	while( i < string -> len - 1){
		if( j == -1 || string -> data[i] == string -> data [j]){
			i ++;
			j++;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
	return next;
}


//遍历next数组
void printNext(int* next, int len){
	int i;
	for(i = 0;i < len; i++){
		printf("%d ", next[i]);
	}
	printf("\n");
}

//进行KMP匹配
void kmpMatchString(String* stringMain, String* stringSce, int* next){

	int i = 0;
	int j = 0;

	while(i < stringMain -> len && j < stringSce -> len){

		if( j == -1 || stringMain -> data[i] == stringSce -> data[j]){

			i++;
			j++;

		}else{

			j = next[j];
		}
	}

	if (j == stringSce -> len){

		/* code */
		printf("匹配成功1\n");

	}else{

		printf("匹配失败0\n");
	}
}



int main(int argc, char const *argv[])
{
	/* code */

	String* stringMain = initString();
	String* stringSce = initString();

	stringAssign(stringMain, "HELLOWORLD");
	stringAssign(stringSce, "LLOWO");

	printString(stringMain);
	printString(stringSce);

	int* next = getNext(stringSce);

	printNext(next, stringSce -> len);

	kmpMatchString(stringMain, stringSce, next);

	return 0;
}

















