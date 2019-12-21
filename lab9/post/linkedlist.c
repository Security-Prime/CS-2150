// Farid Rajabi Nia , fr2md , 11 am
#include <stdio.h>
#include <stdlib.h>


struct listNode {
    struct listNode *next;
    void *value;
};

struct list {
    struct listNode *tail;
   };

int main() {
    struct list *list1 = (struct list *) malloc(sizeof(struct list));
    struct listNode *temp;
    list1->tail = NULL;
    
    int digit;
    printf("\nHow many elements?\n");
    scanf("%d", &digit);

   // getting values and storing them in LL
    int count=0;
    while (count<digit) {
        temp = (struct listNode *) malloc(sizeof(struct listNode));
        int *val = malloc(sizeof(int));

        printf("Enter a number ");
        scanf("%d", val);
    
    //moving the pointer to accomodate the new value
        temp->value = val;        
        temp->next = list1->tail;
        list1->tail = temp;
        count++;    
    }
  
  // printing the values in LL
    struct listNode *current = list1->tail;
    while ( current != NULL )  {
      printf("%d\n",*((int *)(current->value)));
      current=current->next;
    }
 // destructer in some sense
    free(list1);
    return 0;
}