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

BrowserHistory* browserHistoryCreate(char* homepage) { // 생성

    BrowserHistory* history;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // 새 노드 형성

    newNode->next = NULL;
    newNode->prev = NULL;

    history->head = newNode;
    history->cursor = newNode;
   
    return history;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) { // 방문
    
    obj->cursor;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) { // 뒤로 가기

}

char* browserHistoryForward(BrowserHistory* obj, int steps) { // 앞으로 가기

}

void browserHistoryFree(BrowserHistory* obj) { // 제거

}

// DO NOT MODIFY //
int main() {
    int i = 0, count = 0;
    char arg1[500]; // 입력받을 문자열 1
    char arg2[500]; // 입력받을 문자열 2
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];

    fgets(arg1, 500, stdin); // 파일의 끝이 나올때까지, 입력받는다. arg1
    fgets(arg2, 500, stdin); // 파일의 끝이 나올때까지, 입력받는다. arg2
    arg1[strlen(arg1) - 1] = '\0'; // 끝에 NULL이 아닌 공백을 넣어준다.
    arg2[strlen(arg2) - 1] = '\0'; // NULL 대신 공백 채움.

    char* token = strtok(arg1, " "); // 공백으로 문자열 나누기


    while (token != NULL) {
        strcpy(cmd[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " "); // NULL을 공백으로 바꾸어준다. 
        i++;
    }

    count = i; // i 초기화 전에 count에 저장

    i = 0; // 초기화
    token = strtok(arg2, " "); // 공백으로 문자열 나누기
    while (token != NULL) {
        strcpy(parm[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " "); // NULL을 공백으로 바꾸어준다. 
        i++;
    }


    BrowserHistory* obj = NULL; // 객체 생성.
    for (i = 0; i < count; i++) {
        if (strcmp(cmd[i], "BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]);
        }
        else if (strcmp(cmd[i], "visit") == 0) { // visit 커맨드
            browserHistoryVisit(obj, parm[i]);
        }
        else if (strcmp(cmd[i], "back") == 0) { // back 커맨드
            printf("%s ", browserHistoryBack(obj, atoi(parm[i])));
        }
        else if (strcmp(cmd[i], "forward") == 0) { // forward 커맨드
            printf("%s ", browserHistoryForward(obj, atoi(parm[i])));
        }
    }
    browserHistoryFree(obj); // 할당 해제
    return 0;
}
// DO NOT MODIFY //