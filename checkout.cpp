//Alexis Vergara
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "book.h"
#include "person.h"
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

// You are not obligated to use these function declarations - they're just given as examples
void readBooks(vector<Book *> & myBooks) {
	fstream library;
	int idNum;
	string cover;
	string autho;
	string categor;
	string blank;
	int counter;

	Book * bookPtr;

	library.open("books.txt");
	if (library.is_open()) {
		while (!library.eof()) {
			library >> idNum;
			getline(library, blank);
			getline(library, cover);
			getline(library, autho);
			getline(library, categor);
			getline(library, blank); // in this order

			bookPtr = new Book(cover, idNum, autho, categor);
			myBooks.emplace_back(bookPtr);
			counter++;
		}
	}
	bookPtr = nullptr;
}

//int readPersons(vector<Person *> & myCardholders) {
 //   return 0;
//}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
	for (int i = 0; i < myBooks.size(); i++) {
		if (myBooks[i]->getPersonPtr != nullptr)
			cout << "Rentals: " << endl;
	}
	return;
}

void openCard(vector<Person *> & myCardholders, int nextID) {
	string fName;
	string lName;

	cout << "Enter first name: " << endl;
	cin >> fName;
	cout << "Enter last name: " << endl;
	cin >> lName;

	Person *tmpP = new Person(nextID, 0, fName, lName);
	myCardholders.emplace_back(tmpP);

	cout << "CARD ID NUMBER: " << nextID << "ACTIVE ID" << endl;
	cout << "NAME ON ACCOUNT: " << fName + " " + lName << endl;
	tmpP = nullptr;
	
}

Book * searchBook(vector<Book *> myBooks, int id) {
	int librarySearch;

	for (int i = 0; i < myBooks.size(); i++) {
		if (id == myBooks[i]->getId()){
			librarySearch = i;
	}
}
	return myBooks[librarySearch];
}


int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;
	int cardNumber;
	int bookID;
	int customers;
	int newNumber;
	int lastNumber;
	char selection;
	int cards = 0;
    int choice;

	readBooks(books);

	for (int i = 0; i < cardholders.size(); i++) {
		lastNumber = cardholders[i]->getId();
		cout << lastNumber << endl;
	}
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
				//Book checkout
				cout << "Enter the Card Number:" << endl;
				cin >> cardNumber;
				for (int i = 0; i < cardholders.size(); i++) {
					if (cardNumber == cardholders[i]->getId()) {
						cards = i;
						cout << "Cardholder: " << cardholders[cards]->fullName() << endl;
					else
						cout << "TRY AGAIN" << endl;
					}
				}
				cout << "Enter the book ID: ";
				cin >> bookID;
				cout << "Book Name: " << librarySearch(books, bookID) << endl;
                break;
			

            case 2:
                // Book return
				cout << "Enter the bookID: " << endl;
				cin >> bookID;

				cout << "Book Name: " << endl;
				librarySearch(books, bookID);
				break;

            case 3:
                // View all available books
				for (int i = 0; i < books.size(); i++) {
					if (books[i]->getPersonPtr() == nullptr)
					{
						cout << "Book ID: " << books[i]->getId() << endl;
						cout << "Book Name: " << books[i]->getTitle() << endl;
						cout << "Author: " << books[i]->getAuthor() << endl;
						cout << "Book Category: " << books[i]->getCategory() << endl;
						cout << endl;
					}
				}
                break;

            case 4:
                // View all outstanding rentals
				cout << "THESE RENTALS HAVE AN OUTSTANDING BALANCE: " << endl;
                break;

            case 5:
                // View outstanding rentals for a cardholder
				cout << "Outstanding rentals for cardholder: " << endl;
                break;

            case 6:
                // Open new library card
				customers = cardholders.size();
				lastNumber += 0;
				openCard(cardholders, lastNumber);
                break;

            case 7:
                // Close library card
				cout << "Enter the card number: " << endl;
				cin >> cardNumber;

				for (int j = 0; j < cardholders.size(); j++) {
					if (cardNumber == cardholders[j]->getId())
					{

						cards = j;

					}
				}

                break;
                
            case 8:
                // Must update records in files here before exiting the program
				cout << "Records Updating...." << endl;
				break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
