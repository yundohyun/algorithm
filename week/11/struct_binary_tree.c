#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  struct node* left;
  char* word;
  struct node* right;
} NODETYPE;

NODETYPE * insert_node(NODETYPE *root, char *word) {
  if (root == NULL) {
    NODETYPE *new_node = (NODETYPE *)malloc(sizeof(NODETYPE));
    if (new_node == NULL) return NULL; 

    new_node->word = (char *)malloc(strlen(word) + 1);
    if (new_node->word == NULL) {
      free(new_node);
      return NULL;
    }
    strcpy(new_node->word, word);
    new_node->left = new_node->right = NULL;
    return new_node;
  }

  NODETYPE *tptr = root, *before = root;
  int cmp = 0;
    
  while (tptr) {
    cmp = strcmp(word, tptr->word);
    if (cmp < 0) {
      before = tptr;
      tptr = tptr->left;
    } else if (cmp > 0) {
      before = tptr;
      tptr = tptr->right;
    } else {
      return root;
    }
  }

  NODETYPE *new_node = (NODETYPE *)malloc(sizeof(NODETYPE));
  if (new_node == NULL) return root; 
    
  new_node->word = (char *)malloc(strlen(word) + 1);
  if (new_node->word == NULL) {
    free(new_node);
    return root;
  }
  strcpy(new_node->word, word);
  new_node->left = new_node->right = NULL;

  if (cmp < 0) before->left = new_node;
  else before->right = new_node;
    
  return root;
}

NODETYPE * search(NODETYPE * root, char *key) {
  NODETYPE * tptr = root;
  while (tptr) {
    int cmp = strcmp(key, tptr->word);
    if (cmp < 0) tptr = tptr->left;
    else if (cmp > 0) tptr = tptr->right;
    else return tptr;
  }
  return NULL;
}

void inorder (NODETYPE * ptr) {
  if (ptr) {
    inorder(ptr->left);
    printf("%s\n", ptr->word);
    inorder(ptr->right);
  }
}

void free_tree(NODETYPE *ptr) {
  if (ptr) {
    free_tree(ptr->left);
    free_tree(ptr->right);
    free(ptr->word);
    free(ptr);
  }
}

int main() {
  char str[100]; 
  NODETYPE * root = NULL; 
    
  printf("검색의 트리에 저장할 단어\n입력을 그만두려면 quit 입력\n");
    
  if (scanf("%99s", str) != 1) {
    printf("입력 오류 발생.\n");
    return 1;
  }
    
  while (strcmp(str, "quit") != 0) {
    root = insert_node(root, str);
    if (!root) {
      printf("메모리 할당 실패로 종료합니다.\n");
      break;
    }
    if (scanf("%99s", str) != 1) break;
  }
    
  if (root) {
    printf("key 찾기 : ");
    if (scanf("%99s", str) != 1) {
      printf("검색 키 입력 오류 발생.\n");
    } else {
      printf("%s is %s this tree.\n", str, search(root, str) ? "in" : "not in");
    }
        
    printf("----------------------------\n");
    printf("In-order 순회 결과 (알파벳 순):\n");
    inorder(root);
  } else {
    printf("트리가 비어있습니다.\n");
  }
    
  free_tree(root); 
    
  return 0;
}