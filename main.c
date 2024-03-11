#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for exit(0)

#define CAPACITY 400 //Maximum number of books that can be stored in the library
#define STRCAPACITY 50 //Maximum number of characters that can be stored in a string

typedef struct {
    char name[STRCAPACITY];
    char author[STRCAPACITY];
    int pages;
    float price;
} book;

book books[CAPACITY]; //Stores books
int size = 0; //number of books

// function to add book information
void addBook();

// function to display  all books with their info
void displayBooks();
// function to list all the books of given author
void listBooksByAuthor();

// function to list the count of books in the library
void listCountOfBooks();

// adds the option to return to the main menu or exit the program
void smallMenu();

// main function
int main() {
    int choice;
    // displaying the menu
    printf("===== E-Book Library Management System =====\n");
    printf("[1] Add book information\n");
    printf("[2] List all books of a given author\n");
    printf("[3] List the count of books in the library\n");
    printf("[4] Display all books\n");
    printf("[5] Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
        case 1:
            system("cls"); //clears the screen
            addBook();
            break;
        case 2:
            system("cls"); //clears the screen
            listBooksByAuthor();
            break;
        case 3:
            system("cls"); //clears the screen
            listCountOfBooks();
            break;
        case 4:
            system("cls"); //clears the screen
            displayBooks();
            break;
        case 5:
            printf("Thank you for using our E-Book Library Management System\n");
            return 0;
        default:
            printf("Invalid choice\n");
            smallMenu();
    }
}

void smallMenu() {
    int choice2;
    printf("\n[1] Main menu\n[2] Exit\nEnter your choice: ");
    scanf("%d", &choice2);

    if (choice2 == 1) {
        system("cls"); //clears the screen
        main();
    }
    else {
        printf("\nThank you for using our E-Book Library Management System\n");
        exit(0); //terminates the program
    }
}

void addBook() {
    if (size <= CAPACITY) { //checks for free space
        book book1;
        printf("Enter Book Name: ");
        getchar(); //to clear the buffer
        fgets (book1.name, STRCAPACITY, stdin);


        printf("Enter Author Name: ");
        fgets (book1.author, STRCAPACITY, stdin);

        printf("Enter Pages: ");
        scanf("%d", &book1.pages);

        printf("Enter Price: ");
        scanf("%f", &book1.price);

        books[size] = book1;
        size++;

        printf("\n");
        printf("Book added successfully!\n");

        smallMenu();
    }
    else {
        printf("Max capacity reached");
        smallMenu();
    }
}

void listBooksByAuthor() {
    printf("Enter the author's name: ");

    char author_name[STRCAPACITY];
    getchar(); //to clear the buffer
    fgets(author_name , sizeof(author_name) , stdin);

    int check = 0 ; //for checking is there an author with this name or not

    system("cls"); //clears the screen

    for (int i = 0 ; i < size ; i++) {
        if (i == 0) 
            printf("Books of the author: %s\n",author_name);
        
        if(strcmp(books[i].author,author_name) == 0) {
            printf("===========================\n");
            printf("Book name: %s",books[i].name);
            printf("No. of pages: %d\n",books[i].pages);
            printf("Price: %.2f $\n",books[i].price);

            check = 1;
        }
    }
    if (check == 1) 
        printf("===========================\n");
    
    else {
        system("cls"); //clears the screen
        printf("There isn't an author named %s ",author_name);
    }
    smallMenu();
}

void listCountOfBooks() {
    if (size > 1)
        printf("There are %d books in the library\n", size);

    else if (size == 0)
        printf("There are no books yet in the library\n");

    else if (size == 1)
        printf("There is one book in the library\n");

    smallMenu();
}
void displayBooks() {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            printf("===========================\n");
            printf("Book name: %s", books[i].name);
            printf("Author: %s", books[i].author);
            printf("No. of pages: %d\n", books[i].pages);
            printf("Price: %.2f $\n", books[i].price);
        }
        printf("===========================\n");
    }
    else 
        printf("There are no books yet in the library\n");
    
    smallMenu();
}
