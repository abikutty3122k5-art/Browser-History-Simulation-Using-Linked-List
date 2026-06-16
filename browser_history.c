#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;

// Create new node
struct Node* createNode(char url[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Visit new page
void visitPage(char url[]) {
    struct Node* newNode = createNode(url);

    if (current == NULL) {
        current = newNode;
        return;
    }

    current->next = newNode;
    newNode->prev = current;
    current = newNode;
}

// Go Back
void goBack() {
    if (current->prev == NULL) {
        printf("No previous page\n");
        return;
    }

    current = current->prev;
    printf("Moved back to: %s\n", current->url);
}

// Go Forward
void goForward() {
    if (current->next == NULL) {
        printf("No forward page\n");
        return;
    }

    current = current->next;
    printf("Moved forward to: %s\n", current->url);
}

// Show current page
void currentPage() {
    if (current == NULL)
        printf("No page visited\n");
    else
        printf("Current page: %s\n", current->url);
}

// Show full history
void showHistory() {
    struct Node* temp = current;

    while (temp->prev != NULL)
        temp = temp->prev;

    printf("Browser History:\n");
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}

int main() {

    int choice;
    char url[100];

    while (1) {

        printf("\n1.Visit Page\n2.Back\n3.Forward\n4.Current Page\n5.Show History\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                currentPage();
                break;

            case 5:
                showHistory();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}