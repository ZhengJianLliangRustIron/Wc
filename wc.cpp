// wc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<fstream>
#include<stdio.h>
#include<string.h>
#include <io.h>
#include <direct.h>  
#include <string>  
#include <iostream>  
using namespace std;
int n_char(FILE *fp)
{
	int num = 0;
	char s[20];
	while(!feof(fp))
	{
		fscanf(fp, "%s", s); //读取字符串
		num += strlen(s); //叠加字符数
	}
	printf("字符数（不计空格和回车）有%d个\n",num);
	rewind(fp); //绕回文件指针
	return num;
}
int n_world(FILE *fp)
{
	char s[20];
	int n = 0, num = 0;
	while(!feof(fp))
	{
		if(fscanf(fp, "%s", s) && !(s[0] >='0' && s[0] <='9'))
			n++;
		else
			num++;
	}
		printf("单词数有%d个，数字有%d个\n",n,num);
		rewind(fp);
	return n;
}
int n_row(FILE *fp)
{
	int n = 1;
	char ch;
	while(!feof(fp))
	{
		if((ch = fgetc(fp) == '\n'))
		n++;
	}
	printf("有%d行\n", n);
	rewind(fp);
	return n;
}
void sss(string curr)
{	
	int LINE_LENGTH = 100; 
	char line[100];
	int amount = 0;
	char ch;
	int i=0;
	int c=0;
	ifstream fin(curr);
	while(fin.getline(line,LINE_LENGTH))  
	{
		amount++;
		if(line!="")
		{
			char kk[100];
			for(int j=0;j!='\0';j++)
			{
				bool v=true;
				kk[j]=0;
				if(kk[j]!=1&&((line[j]>='A'&& line[j]<='Z')||(line[j]>='a'&& line[j]<='z')))
				{
					i++;
					kk[j]=1;
				}
				if(line[j]=='\x5c'&&line[j-1]=='\x5c')
					c++;
				 
			}			
				 
	cout<<"File :"<<curr<<endl;
	printf(" 有代码行：%d\n",i);
	printf(" 有注释行：%d\n",c);
	printf(" 有空行：%d\n",amount-i);
	c=0;i=0;
	free(fin);
}
	}
}
void filesearch(string path, string mode)  
{   
    struct _finddata_t filefind;   
    string curr = path + "\\*.*";                           // 修改此处改变搜索条件  
    int done = 0, i, handle;   
    if((handle = _findfirst(curr.c_str(), &filefind)) != -1)  
    {  
        while(!(done = _findnext(handle, &filefind)))  
        {   
            if(strcmp(filefind.name, "..") == 0)  
                continue;   
			curr = path + "\\" + filefind.name;
			/*cout<<filefind.name<<curr<<endl;*/
            if((_A_SUBDIR == filefind.attrib))              // 是目录  
            {               
                  
                filesearch(curr, mode);                  // 递归遍历子目录  
            }  
            if(strstr(filefind.name,mode.c_str()))       
			{
				
				sss(curr);
			} 
			
        }  
        _findclose(handle);  
    }  
}  

void main(int argc,char * argv[])
{	

	/*string path,mode;   
	path="d:\\a";
	mode="txt"; 
	filesearch(path,mode);  */
	FILE *fp;
	char s[100];
	strcpy(s,argv[0]);//去exe
	for(int i=strlen(s); i>0 ; i--)
	{
		if( s[i] == '\\')
				{
					s[i]='\0';
					break;
				}
	}	
	string mode ,rts;
	string ss(s);
	cout<< ss<<endl;
	cout<< "输入文件类型:"<<endl;
	cin>>mode;
	mode=mode.substr(1,10);
	filesearch(ss, mode);
	rts=ss+"\\"+mode;
	cin>>mode;
	//strcat(s,mode); //合并两个参数
	
	//fp = fopen(rts.c_str(), "r"); //打开文件//d:\\aaa.txt
	//while(!feof(fp))
	//{
	//	cout<<"zhengchang"<<endl;
	//}
	//n_char(fp);
	//n_world(fp);
	//n_row(fp);
	////expandRowFunction(buf);
	//fclose(fp);







	//FILE *fp; 
	//char lk[100];
	//string Dir;
	//char s[100];
	//char s1[100];
	//
	//strcpy(s,argv[0]);//去exe
	//for(int i=strlen(s); i>0 ; i--)
	//{
	//	if( s[i] == '\\')
	//			{
	//				s[i]='\0';
	//				break;
	//			}
	//}
	//	
	//	strcpy(s1,argv[0]);//去exe
	//for(int i=strlen(s1); i>0 ; i--)
	//{
	//	if( s1[i] == '\\')
	//			{
	//				s1[i]='\0';
	//				break;
	//			}
	//}
	//for (int in=argc;in<1;in--)
	//{	
	//	string Aar;
	//	char *ar;
	//	//ar=argv[in];
	//	//Aar=ar.substr(1,10);// 去*
	//	strcat(s,argv[in]); //合并两个参数
	//	string str=argv[in];
	//	if((str)=="-s"||(str)=="-a")
	//	{
	//		string Ss1,Aargv;
	//		Ss1=s1;
	//		Aargv=Aar;
	//		filesearch(Ss1, Aargv);

	//	}
	//	if(str=="-c")
	//	{
	//		fp = fopen(s, "r");
	//		n_char(fp);
	//	}
	//	if(str=="-w")
	//	{
	//		fp = fopen(s, "r");
	//		n_world(fp);
	//	}
	//	if(str=="-w")
	//	{
	//		fp = fopen(s, "r");
	//		n_row(fp);
	//	}

	//}
	//把路径保存到字符串s里
	
		
	
		
  //      fp = fopen(buffer, "r"); //打开文件//d:\\aaa.txt
		//n_char(fp);
		//n_world(fp);
		//n_row(fp);
		//expandRowFunction(buffer);
		//fclose(fp); 
  //      free(buffer);  
         
	
	/*char str[100];
	gets(str);*/
	//fp = fopen(buf, "r"); //打开文件//d:\\aaa.txt
	//n_char(fp);
	//n_world(fp);
	//n_row(fp);
	//expandRowFunction(buf);
	//fclose(fp);

	
}
