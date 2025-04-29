#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Book
struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book* next;
};

struct Book* head = NULL;

// Function to create a new Book node
struct Book* createBook(int id, const char* title, const char* author) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;
    return newBook;
}

// Add book at end
void addBook(int id, const char* title, const char* author) {
    struct Book* newBook = createBook(id, title, author);
    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBook;
    }
    printf("Book added successfully.\n");
}

// Delete book by ID
void deleteBook(int id) {
    struct Book* temp = head;
    struct Book* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Book with ID %d deleted successfully.\n", id);
}

// Search for a book by ID
void searchBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book Found:\n");
            printf("ID: %d\n", temp->id);
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

// Display all books
void displayBooks() {
    struct Book* temp = head;
    if (temp == NULL) {
        printf("No books in the library.\n");
        return;
    }

    printf("Library Book List:\n");
    while (temp != NULL) {
        printf("ID: %d | Title: %s | Author: %s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

// Menu
void menu() {
    int choice, id;
    char title[100], author[100];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar(); // Consume newline
                printf("Enter Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';  // Remove newline
                printf("Enter Author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0';
                addBook(id, title, author);
                break;
            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
