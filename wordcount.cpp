/*#include<stdio.h>
int main(){
	int chars=0;
	int words=0;
	int ch=0;
	int judge=0;
	FILE *fpr;
	char name[100]={0};
	char type[2];
	printf("请输入需要执行的指令（-c，-w）\n"); 
	gets(type);    
	printf("请输入文件路径：");
	scanf("%s",name);
    if((fpr = fopen(name,"r")) == NULL)
    {
        printf("没有找到此文件 %s\n",name);
        return 0;
    }
	
	if(type[1]=='c'){
		while((ch = fgetc(fpr)) != EOF){
			if((ch>=48 &&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==10 || ch==9 || ch==32)
				chars++;
			}
		printf("一共有%d个字符",chars);
	}
	else if(type[1]=='w'){
		while((ch = fgetc(fpr)) != EOF){
			if((ch>=48 &&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==10 || ch==9){
				if(judge==0){
					words++;
					judge++;
				}
			}
			else if(ch==32 || ch==44){
				judge=0;
			}
		}
		printf("一共有%d个单词",words);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int countc(char *file) //返回文件的字符数 
{   FILE *f;
    f = fopen(file, "r");
    char a;
    int cchar=0;
    if(NULL==(f=fopen(file,"r")))
    	{
        		printf("file is NULL");
    	}
    else
    while (!feof(f)) 
		{ 
			a=fgetc(f); 
			if (a != ' '&&a != '\n'&&a != '\t') cchar++; 
		} 
	fclose(f);
	printf("字符数：%d ",cchar); 
}
int countw(char *file)//返回文件词的数目 
{   FILE *f;
    f=fopen(file,"r");
    char ch;
    int aword=0;
    int cword=0;
    if(NULL==(f=fopen(file,"r")))
    	{
     		printf("file is NULL");
    	}	
    else
    while(!feof(f)) 
	{ 
		ch=fgetc(f); 
		if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_') aword=1; 
		else if (aword) { cword++; aword=0; } 
	} 
	fclose(f); 
	printf("单词数：%d ",cword); 
}
int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        	{  
        		printf("FileNull\n\n\n");
        		scanf("%s%s%s",argv[0],argv[1],argv[2]); continue; 
			} 
		else if(!strcmp(argv[1],"-w")) {
		countw(argv[2]);} 
		else if(!strcmp(argv[1],"-c")) {
		countc(argv[2]);} 
		else printf("NullPoint\n"); 
		printf("\n\n"); 
		scanf("%s%s%s",argv[0],argv[1],argv[2]); 
	} 
	return 0; 
}

	
	
	
	
	
	
