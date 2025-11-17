#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>
#include <string.h>

char stack[MAX_SIZE], queue[MAX_SIZE];
int rear = -1, front = -1, top = -1;

void addq(char data) {
  queue[++rear] = data;
}

char delq() {
  return queue[++front];
}

void push(char data) {
  stack[++top] = data;
}

char pop() {
  return stack[top--];
}

int main() {
  char word[MAX_SIZE], sword, qword, i, p = 1;
  printf("Enter Word: ");
  scanf("%s", word);

  for (int i = 0; i < strlen(word); i++) {
    push(word[i]);
    addq(word[i]);
  }

  for (int i = 0; i < strlen(word); i++) {
    sword = pop();
    qword = delq();
    if (sword != qword) {
      printf("false\n");
      p = 0;
      break;
    }
  }

  if (p) printf("true\n"); 
}