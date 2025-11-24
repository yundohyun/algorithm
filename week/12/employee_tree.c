#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *left;
  int eid;
  int syear;
  char grade;
  struct node *right;
} NODETYPE;

NODETYPE *insert_node(NODETYPE *root, int eid, int syear, char grade) {
  if (root == NULL) {
    NODETYPE *new_node = (NODETYPE *) malloc(sizeof(NODETYPE));
    if (new_node == NULL) return NULL;
    new_node->eid = eid;
    new_node->syear = syear;
    new_node->grade = grade;
    new_node->left = new_node->right = NULL;
    return new_node;
  }
  NODETYPE *tptr = root, *before = root;
  int cmp = 0;
  while (tptr) {
    if (eid < tptr->eid) {
      before = tptr;
      tptr = tptr->left;
      cmp = -1;
    } else if (eid > tptr->eid) {
      before = tptr;
      tptr = tptr->right;
      cmp = 1;
    } else
      return root;
  }
  NODETYPE *new_node = (NODETYPE *) malloc(sizeof(NODETYPE));
  if (new_node == NULL) return root;
  new_node->eid = eid;
  new_node->syear = syear;
  new_node->grade = grade;
  new_node->left = new_node->right = NULL;
  if (cmp < 0) before->left = new_node;
  else before->right = new_node;
  return root;
}

void search(NODETYPE *root, int eid) {
  NODETYPE *tptr = root;
  while (tptr) {
    if (eid < tptr->eid) tptr = tptr->left;
    else if (eid > tptr->eid) tptr = tptr->right;
    else {
      printf("%d\t%d\t%c\n", tptr->eid, tptr->syear, tptr->grade);
      return;
    }
  }
}

void year_search(NODETYPE *ptr, int year) {
  if (ptr) {
    year_search(ptr->left, year);
    if (ptr->syear == year) printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
    year_search(ptr->right, year);
  }
}

void not_a_search(NODETYPE *ptr) {
  if (ptr) {
    not_a_search(ptr->left);
    if (ptr->grade != 'A') printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
    not_a_search(ptr->right);
  }
}

void inorder(NODETYPE *ptr) {
  if (ptr) {
    inorder(ptr->left);
    printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
    inorder(ptr->right);
  }
}

void free_tree(NODETYPE *ptr) {
  if (ptr) {
    free_tree(ptr->left);
    free_tree(ptr->right);
    free(ptr);
  }
}

int main(int argc, char **argv) {
  int eid;
  int syear;
  char grade;
  NODETYPE *root = NULL;
  FILE *file;

  if ((file = fopen(argv[1], "r")) == NULL) {
    printf("파일 읽기 오류\n");
    exit(1);
  }

  while (fscanf(file, "%d %d %c", &eid, &syear, &grade) != EOF) {
    root = insert_node(root, eid, syear, grade);
    if (!root) {
      printf("메모리 할당 실패로 종료합니다.\n");
      break;
    }
  }

  printf("검색의 트리에 저장한 데이터\n");
  inorder(root); 

  printf("\n입사년도 : ");
  scanf("%d", & syear);
  year_search(root, syear);

  printf("\n사원번호 : ");
  scanf("%d", & eid);
  search(root, eid);

  printf("\n인사등급이 A가 아닌 사원\n");
  not_a_search(root);

  free_tree(root);
  return 0;
}