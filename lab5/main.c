#include "lib/list_functions.h"

int main() {
  Student *list = NULL;
  while (1) {
    printf("\e[1;1H\e[2J");
    print(list);
    printf("Choose option: \n");
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Save \n");
    printf("4. Load \n");
	printf("0. Exit \n");

    int choice = 0;
	int exit = 0;
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        insert(new_student(), &list);
        break;
      }
      case 2: {
        printf("Input delete position: ");
        int position = 0;
        scanf("%d", &position);
        delete_element(position - 1, &list);
        break;
      }
      case 3: {
        serialize(list);
        break;
      }
      case 4: {
        deserialize(&list);
        break;
      }
	  case 0: {
        exit = 1;
        break;
      }
      default: {
        printf("ERROR: Wrong input! \n");
      }
    }
	if (exit) break;
  }

  return 0;
}