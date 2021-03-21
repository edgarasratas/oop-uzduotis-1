#include "Funkcijos.h"

int createDir(string folderName) {
    char currentPath[FILENAME_MAX];

    if (!GetCurrentDir(currentPath, sizeof(currentPath)))
    {
        return errno;
    }

    currentPath[sizeof(currentPath) - 1] = '\0'; /* not really required */
    string createFolder = (string)currentPath + "\\" + folderName;
    int status = _mkdir(createFolder.c_str());
}