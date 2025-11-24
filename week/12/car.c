#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *left;
  int carid;
  char cgrade;
  struct node *right;
} CARTYPE;

CARTYPE *make_bst(CARTYPE *root, int carid, char cgrade) {
  if (root == NULL) {
    CARTYPE *new_node = (CARTYPE *) malloc(sizeof(CARTYPE));
    if (new_node == NULL) return NULL;
    new_node->carid = carid;
    new_node->cgrade = cgrade;
    new_node->left = new_node->right = NULL;
    return new_node;
  }
  CARTYPE *tptr = root, *before = root;
  int cmp = 0;
  while (tptr) {
    if (carid < tptr->carid) {
      before = tptr;
      tptr = tptr->left;
      cmp = -1;
    } else if (carid > tptr->carid) {
      before = tptr;
      tptr = tptr->right;
      cmp = 1;
    } else
      return root;
  }
  CARTYPE *new_node = (CARTYPE *) malloc(sizeof(CARTYPE));
  if (new_node == NULL) return root;
  new_node->carid = carid;
  new_node->cgrade = cgrade;
  new_node->left = new_node->right = NULL;
  if (carid < before->carid) before->left = new_node;
  else before->right = new_node;
  return root;
}

void nonpasscar(CARTYPE *ptr) {
  if (ptr) {
    nonpasscar(ptr->left);
    if (ptr->cgrade != 'A') printf("%d\t%c\n", ptr->carid, ptr->cgrade);
    nonpasscar(ptr->right);
  }
}

void free_tree(CARTYPE *ptr) {
  if (ptr) {
    free_tree(ptr->left);
    free_tree(ptr->right);
    free(ptr);
  }
}

int main(int argc, char **argv) {
  int id;
  int syear;
  char grade;
  CARTYPE *root = NULL;
  FILE *file;

  if ((file = fopen(argv[1], "r")) == NULL) {
    printf("파일 읽기 오류\n");
    exit(1);
  }

  while (fscanf(file, "%d %c", &id, &grade) != EOF) {
    root = make_bst(root, id, grade);
    if (!root) {
      printf("메모리 할당 실패로 종료합니다.\n");
      break;
    }
  }

  printf("등급이 A가 아닌 차\n");
  nonpasscar(root);

  free_tree(root);
  return 0;
}