// wc.cpp : �������̨Ӧ�ó������ڵ㡣
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
		fscanf(fp, "%s", s); //��ȡ�ַ���
		num += strlen(s); //�����ַ���
	}
	printf("�ַ��������ƿո�ͻس�����%d��\n",num);
	rewind(fp); //�ƻ��ļ�ָ��
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
		printf("��������%d����������%d��\n",n,num);
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
	printf("��%d��\n", n);
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
	printf(" �д����У�%d\n",i);
	printf(" ��ע���У�%d\n",c);
	printf(" �п��У�%d\n",amount-i);
	c=0;i=0;
	free(fin);
}
	}
}
void filesearch(string path, string mode)  
{   
    struct _finddata_t filefind;   
    string curr = path + "\\*.*";                           // �޸Ĵ˴��ı���������  
    int done = 0, i, handle;   
    if((handle = _findfirst(curr.c_str(), &filefind)) != -1)  
    {  
        while(!(done = _findnext(handle, &filefind)))  
        {   
            if(strcmp(filefind.name, "..") == 0)  
                continue;   
			curr = path + "\\" + filefind.name;
			/*cout<<filefind.name<<curr<<endl;*/
            if((_A_SUBDIR == filefind.attrib))              // ��Ŀ¼  
            {               
                  
                filesearch(curr, mode);                  // �ݹ������Ŀ¼  
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
	strcpy(s,argv[0]);//ȥexe
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
	cout<< "�����ļ�����:"<<endl;
	cin>>mode;
	mode=mode.substr(1,10);
	filesearch(ss, mode);
	rts=ss+"\\"+mode;
	cin>>mode;
	//strcat(s,mode); //�ϲ���������
	
	//fp = fopen(rts.c_str(), "r"); //���ļ�//d:\\aaa.txt
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
	//strcpy(s,argv[0]);//ȥexe
	//for(int i=strlen(s); i>0 ; i--)
	//{
	//	if( s[i] == '\\')
	//			{
	//				s[i]='\0';
	//				break;
	//			}
	//}
	//	
	//	strcpy(s1,argv[0]);//ȥexe
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
	//	//Aar=ar.substr(1,10);// ȥ*
	//	strcat(s,argv[in]); //�ϲ���������
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
	//��·�����浽�ַ���s��
	
		
	
		
  //      fp = fopen(buffer, "r"); //���ļ�//d:\\aaa.txt
		//n_char(fp);
		//n_world(fp);
		//n_row(fp);
		//expandRowFunction(buffer);
		//fclose(fp); 
  //      free(buffer);  
         
	
	/*char str[100];
	gets(str);*/
	//fp = fopen(buf, "r"); //���ļ�//d:\\aaa.txt
	//n_char(fp);
	//n_world(fp);
	//n_row(fp);
	//expandRowFunction(buf);
	//fclose(fp);

	
}
