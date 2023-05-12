// BrowserHistory visit visit visit back back forward visit forward back back
// hufs.ac.kr google.com naver.com youtube.com 1 1 1 linkedin.com 2 2 7


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH	21

// DO NOT MODIFY //
struct Node {
    char url[MAX_URL_LENGTH]; // value
    struct Node* prev;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* cursor;
} BrowserHistory;
// DO NOT MODIFY //

BrowserHistory* browserHistoryCreate(char* homepage) { // ����

    BrowserHistory* history;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // �� ��� ����

    newNode->next = NULL;
    newNode->prev = NULL;

    history->head = newNode;
    history->cursor = newNode;
   
    return history;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) { // �湮
    
    obj->cursor;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) { // �ڷ� ����

}

char* browserHistoryForward(BrowserHistory* obj, int steps) { // ������ ����

}

void browserHistoryFree(BrowserHistory* obj) { // ����

}

// DO NOT MODIFY //
int main() {
    int i = 0, count = 0;
    char arg1[500]; // �Է¹��� ���ڿ� 1
    char arg2[500]; // �Է¹��� ���ڿ� 2
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];

    fgets(arg1, 500, stdin); // ������ ���� ���ö�����, �Է¹޴´�. arg1
    fgets(arg2, 500, stdin); // ������ ���� ���ö�����, �Է¹޴´�. arg2
    arg1[strlen(arg1) - 1] = '\0'; // ���� NULL�� �ƴ� ������ �־��ش�.
    arg2[strlen(arg2) - 1] = '\0'; // NULL ��� ���� ä��.

    char* token = strtok(arg1, " "); // �������� ���ڿ� ������


    while (token != NULL) {
        strcpy(cmd[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " "); // NULL�� �������� �ٲپ��ش�. 
        i++;
    }

    count = i; // i �ʱ�ȭ ���� count�� ����

    i = 0; // �ʱ�ȭ
    token = strtok(arg2, " "); // �������� ���ڿ� ������
    while (token != NULL) {
        strcpy(parm[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " "); // NULL�� �������� �ٲپ��ش�. 
        i++;
    }


    BrowserHistory* obj = NULL; // ��ü ����.
    for (i = 0; i < count; i++) {
        if (strcmp(cmd[i], "BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]);
        }
        else if (strcmp(cmd[i], "visit") == 0) { // visit Ŀ�ǵ�
            browserHistoryVisit(obj, parm[i]);
        }
        else if (strcmp(cmd[i], "back") == 0) { // back Ŀ�ǵ�
            printf("%s ", browserHistoryBack(obj, atoi(parm[i])));
        }
        else if (strcmp(cmd[i], "forward") == 0) { // forward Ŀ�ǵ�
            printf("%s ", browserHistoryForward(obj, atoi(parm[i])));
        }
    }
    browserHistoryFree(obj); // �Ҵ� ����
    return 0;
}
// DO NOT MODIFY //