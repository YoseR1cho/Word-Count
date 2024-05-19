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

    // ���ļ�
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ����ļ������ڡ�\n");
        return 1;
    }

    // ���ݲ�������ͳ���ַ������ǵ�����
    if (strcmp(parameter, "-c") == 0) {
        // ͳ���ַ���
        while ((ch = fgetc(file)) != EOF) {
            charCount++;
        }
        printf("�ַ�����%d\n", charCount);
    } else if (strcmp(parameter, "-w") == 0) {
        // ͳ�Ƶ�����
        while ((ch = fgetc(file)) != EOF) {
            if (ch == ' ' || ch == ',') {
                wordCount++;
            }
        }
        if (charCount > 0) {
            wordCount++;
        }
        printf("��������%d\n", wordCount);
    } else {
        printf("�������󣬱���Ϊ -c �� -w\n");
        return 1;
    }

    // �ر��ļ�
    fclose(file);

    return 0;
}
