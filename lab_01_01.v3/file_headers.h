#pragma once

#include "framework.h"

#include "my_list.h"

#define MAX_WORD_LEN_DEFAULT 12
#define WORD_COUNT_DEFAULT 10
#define STR_COUNT_DEFAULT 5
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define FILES_PATH_DEFAULT "D://WORK//C-C++Projects//Files//"

MyList files_creater(
	int filesCount,
	int wordMaxLen,
	int wordCount,
	int strCount,
	std::string fileNamePrototype,
	std::string filePath
);

void files_word_sort(MyList& fileNamesList);
