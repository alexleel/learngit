#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
using namespace std;

#define FILELEN 256

void DirTree(const char* dir_name, int level)
{
	if (!dir_name)
	{
		cout << "No parameter input!!" << endl;
		return;
	}
	// check parameter dir_name
	DIR *dirp = opendir(dir_name);
	if(!dirp)
	{
		perror("opendir error!\n");
		return;
	}
	struct stat st;
	struct dirent *dir_entry;
	char fullpath[FILELEN];
	
	//read file from dir  
	while((dir_entry = readdir(dirp)) != NULL)
	{
		// consider . and .. dir or there will be dead loop
		// if "." or "..", continue
		if(!strcmp(dir_entry->d_name, ".")||
			!strcmp(dir_entry->d_name, ".."))
		{
			continue;
		}
		for (int i=0; i<level; i++)
		{
			cout << "\t";
		}
		cout << "|";
		cout << "--";
		
		sprintf(fullpath, "%s/%s", dir_name,dir_entry->d_name);
		cout << fullpath << endl;
		if(lstat(fullpath, &st) < 0)
		{
			perror("lsat error\n");
			continue;
		}
		if(S_ISDIR(st.st_mode))
		{
			DirTree(fullpath,level+1);
		}
	}
	closedir(dirp);
}

int main(int argc, char** argv)
{
	DirTree(argv[1],0);
	return 0;
}


