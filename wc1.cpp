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

	
	
	
	
	
	
