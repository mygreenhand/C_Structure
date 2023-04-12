#include <stdio.h>
#include <stdlib.h>

//定义字符串结构
typedef struct String{
	char* data;
	int len;
}String;

//初始化子串
String* initString(){

	String* string = (String*)malloc(sizeof(String));
	string -> data = NULL;
	string -> len = 0;

	return string;
}

//对字符串赋值
void stringAssign(String* string, char* data){

	if (string -> data){
		free(string -> data);
	}

	int len = 0;
	char* s = data;

	while(*s){

		len ++;
		s ++;
	}

	if(len == 0){

		string -> data = NULL;
		string -> len = 0;

	}else{

		s = data;
		string -> len = len;

		string -> data = (char*)malloc(sizeof(char) * (len + 1));

		int i;
		for (i = 0; i < len; i++, s++)
		{
			/* code */

			string -> data[i] = *s;

		}
	}
	
}

//遍历字符串
void printString(String* string){

	int i;
	for (i = 0; i < string -> len; i++){
		/* code */
		printf("%c ", string -> data[i]);
	}
	printf("\n");
}

//进行匹配
void stringMatch(String* masterString, String* subString){

	int i = 0;
	int j = 0;

	while(i < masterString -> len && j < subString -> len){
		if(masterString -> data[i] == subString -> data[j]){
			i++;
			j++;
		}else{
			i = i - j + 1;
			j = 0;
		}
	}

	if(j == subString -> len){
		printf("匹配成功1\n");
	}else{
		printf("匹配失败0\n");
	}

}

int main()
{
	/* code */
	//String* string = initString();
	String* masterString = initString();
	String* subString = initString();
	stringAssign(masterString, "HELLOWORLD");
	stringAssign(subString, "HELLOW");

	printString(masterString);
	printString(subString);

	stringMatch(masterString,subString);
	return 0;
}



























