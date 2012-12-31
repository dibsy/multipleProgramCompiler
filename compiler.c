/*
  						Project    : C Program Compiler
							Team       : OpenSoft  Solutions
							Developer  : Dibyendu Sikdar (indi-hex-coder)
							Version    : 2.0

*/

#include<stdio.h>//include the header file for Input Output Operations
#include<string.h>//including for string operations
#include<ctype.h>
/*
compile()  Its work will be to compile the program. Take input from a file and direct the output to an error file.
There will be 2 cases. Output wfile will be empty if ne errors found or it will contain the errors in it.
*/
 
char filename[20];

void copyFile();
void compile();
void checkERRORS();
void readList();
void execute();

void compile()
{
	system("gcc -Wall  temp.c &> error.txt ");
	system("gcc temp.c -o temp.out ");
}

/*
checkERRORS() searches for the word error in the file error.txt
error.txt contains the details of the output generated during compilation
It may be empty or not.

*/

void checkERRORS()
{
	FILE *ptr;
	ptr=fopen("error.txt","r");
	char c;
	int i=0;
	char output[1000];
	
	while((c=fgetc(ptr))!=EOF)
	{
		output[i]=c;
		i++;
	
	}
	
	fclose(ptr);
	output[--i]='\0';
	
	char errors[7]="error";
	char *ch;

	ch=strstr(output,"error");
	/*
	int found=0;
	int k;
	for(i=0;i<994;i++)
	{
		if((output[i]=='e')&&(output[i+1]=='r')&&(output[i+2]=='r')&&(output[i+3]=='o')&&(output[i+4]=='r'))
			found=1;
	}
	*/
	
	if(ch==NULL)
	{
		
		printf("--okk------>");
		printf("\t%s",filename);
		printf("\n");
		execute();
	}
	else
	{
		printf("--not ok--->");
		printf("\t%s",filename);
		printf("\n");
	}
	
}

/*
execute() It will execute the the .out file if no error is found in the .c program.
It will call the checkERRORS() function to check if there is any error or not.
*/
void execute()
{
	system("./temp.out");
}

/*
readProgramList() It will read the program names from program list
which will contain program name.This file must be provided. 
>./a.out<filename.txt 

*/
void readProgramList()
{
	
//	extern char filename[];	
	char c=getchar();
	int i=0;
	while(c!=EOF)
	{
		filename[i]=c;
		i++;
		c=getchar();
	}
	filename[--i]='\0';
	//printf("%s",filename);
	return;
}

void readList()
{
	char c=getchar();
	int i=0;
	while(c!=EOF)
	{
		if(c=='\n')
		{
			filename[i]='\0';
			i=0;
			c=getchar();
			printf("%s",filename);
			copyFile();
			compile();
			checkERRORS();
			//execute();
			
		}

		filename[i]=c;
		i++;
		c=getchar();
	}
}
	

/* 
copyFiles()  It will copy the contents from the C file to a temp file which
we will compile .
*/
void copyFile()
{
	char fname[20];
	strcpy(fname,filename);
	FILE *fread;
	FILE *fwrite;

	fread=fopen(filename,"r");
	fwrite=fopen("temp.c","w");

	char c;
	while((c=fgetc(fread))!=EOF)
	{
		//printf("%c",c);
		fputc(c,fwrite);
	}
	fclose(fread);
	fclose(fwrite);

	return;
}
main()
{
	//readProgramList();
	//printf("%s",filename);
	//printf("%d",strlen(filename));
	//copyFile();
	//compile();
	//checkERRORS();
	//execute();
	readList();
 
}
