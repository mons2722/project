#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

#define MAX 1024

void dirwalk(char *dir, void (*f)(char *))
{ DIR *dp;
  struct dirent *entry;
  struct stat buf;
  char name[MAX];

  if((dp=opendir(dir))==NULL)
   {  fprintf(stderr,"\nCan't open %s",dir);
     return;
     }
  else{
  while((entry=readdir(dp))!=NULL)
  {  
     if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
       continue;
      sprintf(name,"%s/%s", dir, entry->d_name);
        if (stat(name, &buf) == -1)
            fprintf(stderr, "fsize: can't access %s\n", name);
        else if (S_ISDIR(buf.st_mode))
            dirwalk(name, f);
     f(name);
  }}
closedir(dp);
}

void fsize(char *name)
{
 struct stat buf;
 if (stat(name,&buf)==-1)
  {  printf("\nCan't access file %s",name);
          return;}

 if(S_ISDIR(buf.st_mode))
         dirwalk(name,fsize);

 printf("\nName:%s",name);
 printf("\nSize:%8ld", buf.st_size);
 printf("\nBlock:%8ld",buf.st_blocks);
printf("\nBlock Size:%8ld",buf.st_blksize);
printf("\nNLINK:%8ld\n",buf.st_nlink);
}

void main(int argc, char *argv[])
{
  if(argc==1)
    fsize(".");
  else 
  { while(--argc>0)
	fsize(*++argv);
  }
}  
