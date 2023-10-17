#include "framework.h"

#include "file_headers.h"
#include "my_list.h"

int main() {

    MyList fileNamesList;

    fileNamesList.copy_from(files_creater(2, 0, 0, 0, "text_", ""));

    files_word_sort(fileNamesList);

    return 0;
}