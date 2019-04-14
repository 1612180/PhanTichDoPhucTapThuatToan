#include "file_getter.h"

FileGetter::FileGetter(string folder){       
	folderStar = folder + "\\*.*";
	hfind = FindFirstFileA(folderStar.c_str(),&found);
	//skip .
	FindNextFileA(hfind,&found);        
}

int FileGetter::getNextFile(string& fName){
	//skips .. when called for the first time
	chk=FindNextFileA(hfind,&found);
	if (chk)
		fName = string(found.cFileName);
	return chk;
}