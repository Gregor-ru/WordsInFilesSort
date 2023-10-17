#include "file_headers.h"

string random_word_creater(int wordLength) {
    string word;
    int alphabetLength = sizeof(ALPHABET) - 1;

    mt19937 gen(random_device{}());
    uniform_int_distribution<int> distribution(0, alphabetLength - 1);

    for (int i = 0; i < wordLength; i++) {
        int randomIndex = distribution(gen);
        word += ALPHABET[randomIndex];
    }

    return word;
}

void random_txt_creater(int wordMaxLen, int wordCount, int strCount, string fileFullName) {
    ofstream fStream(fileFullName);

    if (wordMaxLen < 1) wordMaxLen = MAX_WORD_LEN_DEFAULT;
    if (wordCount < 1) wordCount = WORD_COUNT_DEFAULT;
    if (strCount < 1) strCount = STR_COUNT_DEFAULT;

    if (!fStream.is_open())
        cout << "Error, file not created" << endl;
    else {
        mt19937 gen(random_device{}());

        for (int i = 0; i < strCount; i++) {
            int wordCountInStr = int(wordCount / strCount);
            MyList wordsList;

            for (int j = 0; j < wordCountInStr; j++) {
                wordsList.push_back(random_word_creater(uniform_int_distribution<int>(4, wordMaxLen)(gen)));
            }

            for (int j = 0; j < wordsList.get_size(); j++) {
                fStream << wordsList.at(j)->data;
                if (j < wordsList.get_size() - 1) {
                    fStream << " ";
                }
            }

            if (i != strCount - 1) {
                fStream << "\n";
            }
        }

        fStream.close();
    }
}

MyList files_creater(int filesCount,int wordMaxLen,int wordCount,int strCount,string fileNamePrototype,string filePath)
{
    MyList fileNamesList;

    if (filePath.empty()) filePath = FILES_PATH_DEFAULT;

    for (int i = 0; i < filesCount; i++) {
        string fileNameNow = filePath + fileNamePrototype + to_string(i) + ".txt";

        random_txt_creater(wordMaxLen, wordCount, strCount, fileNameNow);

        fileNamesList.push_back(fileNameNow);
       
    }

    return fileNamesList;
}

