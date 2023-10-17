#include "file_headers.h"

MyList split_string(const string& line) {
    MyList words;
    string word;
    for (char c : line) {
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void files_word_sort(MyList& fileNamesList) {
    MyList allWords;

    for (int i = 0; i < fileNamesList.get_size(); i++) {
        ifstream fileNow(fileNamesList.at(i)->data);

        if (!fileNow.is_open()) {
            cerr << "Unable to open file: " << fileNamesList.at(i)->data << endl;
        }

        MyList fileWords;
        string line;

        while (getline(fileNow, line)) {
            MyList words = split_string(line);

            for (int j = 0; j < words.get_size(); j++) {

                MyList::Node* newWordNode = new MyList::Node(words.at(j)->data);

                MyList::Node* it = allWords.begin();
                MyList::Node* prev = nullptr;
                while (it && it->data < words.at(j)->data) {
                    prev = it;
                    it = it->next;
                }

                if (!prev) {
                    allWords.push_front(words.at(j)->data);
                }
                else {
                    allWords.insert_after(prev, words.at(j)->data);
                }

                if (fileWords.get_size() == 0) {
                    fileWords.push_back(words.at(j)->data);
                }
                else {
                    
                    MyList::Node* it = fileWords.begin();
                    MyList::Node* prev = nullptr;
                    while (it && it->data < words.at(j)->data) {
                        prev = it;
                        it = it->next;
                    }

                    if (!prev) {
                        fileWords.push_front(words.at(j)->data); 
                    }
                    else {
                        fileWords.insert_after(prev, words.at(j)->data);
                    }
                }
            }
        }

        fileNow.close();

        cout << fileNamesList.at(i)->data << "\n";
        cout << "______________________________\n";
        int wordCount = 1;
        for (int j = 0; j < fileWords.get_size(); j++) {
            cout << "Word " << wordCount << ": " << fileWords.at(j)->data << "\n";
            wordCount++;
        }
        cout << "______________________________\n";
    }

    cout << "All words:\n";
    cout << "______________________________\n";
    int wordCount = 1;

    for (int i = 0; i < allWords.get_size(); i++) {
        cout << "Word " << wordCount << ": " << allWords.at(i)->data << "\n";
        wordCount++;
    }
    cout << "______________________________\n";
}



