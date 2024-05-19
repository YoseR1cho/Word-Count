#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [parameter] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];
    char ch;
    int charCount = 0;
    int wordCount = 0;

    // 打开文件
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件或文件不存在。\n");
        return 1;
    }

    // 根据参数决定统计字符数还是单词数
    if (strcmp(parameter, "-c") == 0) {
        // 统计字符数
        while ((ch = fgetc(file)) != EOF) {
            charCount++;
        }
        printf("字符数：%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        // 统计单词数
        while ((ch = fgetc(file)) != EOF) {
            if (ch == ' ' || ch == ',') {
                wordCount++;
            }
        }
        if (charCount > 0) {
            wordCount++;
        }
        printf("单词数：%d\n", wordCount);
    } else {
        printf("参数错误，必须为 -c 或 -w\n");
        return 1;
    }

    // 关闭文件
    fclose(file);

    return 0;
}
