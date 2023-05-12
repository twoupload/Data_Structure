#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH	21

// DO NOT MODIFY //
struct Node {
    char url[MAX_URL_LENGTH];
    struct Node* prev;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* cursor;
} BrowserHistory;
// DO NOT MODIFY //

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* history =(BrowserHistory*)malloc(sizeof(BrowserHistory)); // Ŀ���� ��带 ���� ����ü ������ ����
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // ���ο� ��� ����

    // ���ο� ��忡 ���� �߰�
    strcpy(newNode->url, homepage);

    // ���� ���� ����� ������ ����.
    newNode->prev = NULL; 
    newNode->next = NULL;

    // Ŀ���� ��带 �����ش�. 
    history->head = newNode;
    history->cursor = newNode;

    // �� ��� ��ȯ
    return history;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    struct Node* newNode;
    struct Node* deleteNode;

    newNode = malloc(sizeof(struct Node));

    if (!newNode) {
        perror("Memory Alocation Error"); // ����
        return;
    }

    memset(newNode, 0, sizeof(struct Node));
    strncpy(newNode->url, url, strlen(url));

    newNode->prev = obj->cursor;

    deleteNode = obj->cursor->next;

    obj->cursor->next = newNode;

    while (deleteNode) {
        struct Node* temp = deleteNode;
        deleteNode = deleteNode->next;
        free(temp);
    }

    obj->cursor = obj->cursor->next;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    for (int i = 0; i < steps && obj->cursor->prev; ++i, obj->cursor = obj->cursor->prev);
    return obj->cursor->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    for (int i = 0; i < steps && obj->cursor->next; ++i, obj->cursor = obj->cursor->next);
    return obj->cursor->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    while (obj->head != NULL) {
        struct Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    free(obj);
}

// DO NOT MODIFY //
int main() {
    int i = 0, count = 0;
    char arg1[500];
    char arg2[500];
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];


    fgets(arg1, 500, stdin);
    fgets(arg2, 500, stdin);
    if (arg1[strlen(arg1) - 1] == '\n') {
        arg1[strlen(arg1) - 1] = '\0';
    }
    if (arg2[strlen(arg2) - 1] == '\n') {
        arg2[strlen(arg2) - 1] = '\0';
    }
    char* token = strtok(arg1, " "); // �������� ���ڿ� ������

    while (token != NULL) {
        strcpy(cmd[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i = 0;
    token = strtok(arg2, " "); // �������� ���ڿ� ������
    while (token != NULL) {
        strcpy(parm[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " ");
        i++;
    }


    BrowserHistory* obj;
    for (i = 0; i < count; i++) {
        if (strcmp(cmd[i], "BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]);
        }
        else if (strcmp(cmd[i], "visit") == 0) {
            browserHistoryVisit(obj, parm[i]);
        }
        else if (strcmp(cmd[i], "back") == 0) {
            printf("%s ", browserHistoryBack(obj, atoi(parm[i])));
        }
        else if (strcmp(cmd[i], "forward") == 0) {
            printf("%s ", browserHistoryForward(obj, atoi(parm[i])));
        }
    }
    browserHistoryFree(obj);
    return 0;
}
// DO NOT MODIFY //