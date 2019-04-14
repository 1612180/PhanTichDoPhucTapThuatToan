#pragma once

#include <string>
#include <Windows.h>

using namespace std;

class FileGetter{
    WIN32_FIND_DATAA found; 
    HANDLE hfind;
    string folderStar;       
    int chk;
public:
    FileGetter(string folder);
    int getNextFile(string& fName);
};