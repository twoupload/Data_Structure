// BrowserHistory visit visit visit back back forward visit forward back back
// hufs.ac.kr google.com naver.com youtube.com 1 1 1 linkedin.com 2 2 7

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
    BrowserHistory* history = (BrowserHistory*)malloc(sizeof(BrowserHistory)); // 커서와 헤드를 위한 구조체 포인터 생성
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // 새로운 노드 생성

    // 새로운 노드에 값을 추가
    strcpy(newNode->url, homepage);

    // 전과 후의 노드의 내용은 없다.
    newNode->prev = NULL;
    newNode->next = NULL;

    // 커서와 헤드를 맞춰준다. 
    history->head = newNode;
    history->cursor = newNode;

    // 새 노드 반환
    return history;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->next = NULL;

    memset(newNode->url, 0, sizeof newNode->url);
    strncpy(newNode->url, url, strlen(url));

    if (obj->cursor->next == NULL) {

        newNode->prev = obj->cursor; // 새 노드의 이전은 커서

        obj->cursor->next = newNode; // 커서의 다음은 새 노드

        obj->cursor = newNode; // 커서 옮김
    }

    else {
        struct Node* tmp;// 임시 노드

        tmp = obj->cursor->next; // 커서 다음은 임시 노드

        newNode->prev = obj->cursor; // 새 노드 이전이 커서

        obj->cursor->next = newNode; // 현재 지정노드(커서) 다음이 새 노드

        obj->cursor = newNode; // 커서 이동

        while (tmp != NULL) { // temp 포함 커서 이후 모든 노드 삭제
            struct Node* deleteNode = tmp;
            tmp = tmp->next;
            free(deleteNode);
        }
    }
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
    char* token = strtok(arg1, " "); // 공백으로 문자열 나누기

    while (token != NULL) {
        strcpy(cmd[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i = 0;
    token = strtok(arg2, " "); // 공백으로 문자열 나누기
    while (token != NULL) {
        strcpy(parm[i], token); // 나눈 문자열을 배열에 저장하기
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