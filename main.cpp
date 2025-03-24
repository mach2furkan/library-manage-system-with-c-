#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <queue>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isBorrowed; // Track if the book is borrowed
    int borrowCount; // Track how many times the book has been borrowed
    string category; // Category/Genre of the book
    string reservedBy; // User ID of the user who reserved the book
    time_t dueDate; // Due date for returning the book
    unordered_map<string, int> ratings; // User ratings for the book
    vector<string> feedbacks; // User feedback for the book
    string donor; // Donor of the book (if donated)
    string series; // Series name (if applicable)
    queue<string> reservationQueue; // Queue of users waiting to reserve the book
    double rentalFee; // Rental fee for the book
    string coverImagePath; // Path to the book's cover image

public:
    // Constructor
    Book(const string& title = "", const string& author = "", const string& isbn = "", const string& category = "")
            : title(title), author(author), isbn(isbn), isBorrowed(false), borrowCount(0), category(category),
              reservedBy(""), dueDate(0), donor(""), series(""), rentalFee(0.0), coverImagePath("") {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool getIsBorrowed() const { return isBorrowed; }
    int getBorrowCount() const { return borrowCount; }
    string getCategory() const { return category; }
    string getReservedBy() const { return reservedBy; }
    time_t getDueDate() const { return dueDate; }
    double getAverageRating() const {
        if (ratings.empty()) return 0.0;
        int total = 0;
        for (const auto& pair : ratings) {
            total += pair.second;
        }
        return static_cast<double>(total) / ratings.size();
    }
    string getDonor() const { return donor; }
    string getSeries() const { return series; }
    queue<string> getReservationQueue() const { return reservationQueue; }
    double getRentalFee() const { return rentalFee; }
    string getCoverImagePath() const { return coverImagePath; }

    // Setters
    void setTitle(const string& newTitle) { title = newTitle; }
    void setAuthor(const string& newAuthor) { author = newAuthor; }
    void setIsBorrowed(bool status) { isBorrowed = status; }
    void incrementBorrowCount() { borrowCount++; }
    void setCategory(const string& newCategory) { category = newCategory; }
    void setReservedBy(const string& userId) { reservedBy = userId; }
    void setDueDate(time_t newDueDate) { dueDate = newDueDate; }
    void addRating(const string& userId, int rating) { ratings[userId] = rating; }
    void addFeedback(const string& feedback) { feedbacks.push_back(feedback); }
    void setDonor(const string& donorName) { donor = donorName; }
    void setSeries(const string& seriesName) { series = seriesName; }
    void addToReservationQueue(const string& userId) { reservationQueue.push(userId); }
    void setRentalFee(double fee) { rentalFee = fee; }
    void setCoverImagePath(const string& path) { coverImagePath = path; }

    // Display book details
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available")
             << ", Borrow Count: " << borrowCount << ", Category: " << category
             << ", Average Rating: " << getAverageRating();
        if (!reservedBy.empty()) {
            cout << ", Reserved By: " << reservedBy;
        }
        if (dueDate > 0) {
            cout << ", Due Date: " << ctime(&dueDate);
        }
        if (!donor.empty()) {
            cout << ", Donated By: " << donor;
        }
        if (!series.empty()) {
            cout << ", Series: " << series;
        }
        if (rentalFee > 0.0) {
            cout << ", Rental Fee: $" << rentalFee;
        }
        if (!coverImagePath.empty()) {
            cout << ", Cover Image: " << coverImagePath;
        }
        cout << "\n";
    }
};

class User {
private:
    string name;
    string id;
    string email; // Email address of the user
    vector<string> borrowedBooks; // List of ISBNs of borrowed books
    vector<string> reservedBooks; // List of ISBNs of reserved books
    vector<string> wishlist; // List of ISBNs of books in the wishlist
    vector<string> activityLog; // Log of user activities
    time_t membershipExpiry; // Membership expiry date
    vector<string> notifications; // Notifications for the user

public:
    // Constructor
    User(const string& name = "", const string& id = "", const string& email = "")
            : name(name), id(id), email(email), membershipExpiry(0) {}

    // Getters
    string getName() const { return name; }
    string getId() const { return id; }
    string getEmail() const { return email; }
    vector<string> getBorrowedBooks() const { return borrowedBooks; }
    vector<string> getReservedBooks() const { return reservedBooks; }
    vector<string> getWishlist() const { return wishlist; }
    vector<string> getActivityLog() const { return activityLog; }
    time_t getMembershipExpiry() const { return membershipExpiry; }
    vector<string> getNotifications() const { return notifications; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setEmail(const string& newEmail) { email = newEmail; }
    void setMembershipExpiry(time_t expiry) { membershipExpiry = expiry; }

    // Borrow a book
    void borrowBook(const string& isbn) {
        borrowedBooks.push_back(isbn);
        activityLog.push_back("Borrowed book with ISBN: " + isbn);
    }

    // Return a book
    void returnBook(const string& isbn) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), isbn);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            activityLog.push_back("Returned book with ISBN: " + isbn);
        }
    }

    // Reserve a book
    void reserveBook(const string& isbn) {
        reservedBooks.push_back(isbn);
        activityLog.push_back("Reserved book with ISBN: " + isbn);
    }

    // Cancel reservation
    void cancelReservation(const string& isbn) {
        auto it = find(reservedBooks.begin(), reservedBooks.end(), isbn);
        if (it != reservedBooks.end()) {
            reservedBooks.erase(it);
            activityLog.push_back("Cancelled reservation for book with ISBN: " + isbn);
        }
    }

    // Add to wishlist
    void addToWishlist(const string& isbn) {
        wishlist.push_back(isbn);
        activityLog.push_back("Added book with ISBN: " + isbn + " to wishlist");
    }

    // Remove from wishlist
    void removeFromWishlist(const string& isbn) {
        auto it = find(wishlist.begin(), wishlist.end(), isbn);
        if (it != wishlist.end()) {
            wishlist.erase(it);
            activityLog.push_back("Removed book with ISBN: " + isbn + " from wishlist");
        }
    }

    // Add notification
    void addNotification(const string& message) {
        notifications.push_back(message);
    }

    // Display user details
    void display() const {
        cout << "User Name: " << name << ", ID: " << id << ", Email: " << email << "\n";
        cout << "Borrowed Books: ";
        if (borrowedBooks.empty()) {
            cout << "None\n";
        } else {
            for (const auto& isbn : borrowedBooks) {
                cout << isbn << " ";
            }
            cout << "\n";
        }
        cout << "Reserved Books: ";
        if (reservedBooks.empty()) {
            cout << "None\n";
        } else {
            for (const auto& isbn : reservedBooks) {
                cout << isbn << " ";
            }
            cout << "\n";
        }
        cout << "Wishlist: ";
        if (wishlist.empty()) {
            cout << "None\n";
        } else {
            for (const auto& isbn : wishlist) {
                cout << isbn << " ";
            }
            cout << "\n";
        }
        cout << "Notifications:\n";
        if (notifications.empty()) {
            cout << "No notifications.\n";
        } else {
            for (const auto& notification : notifications) {
                cout << "- " << notification << "\n";
            }
        }
        cout << "Activity Log:\n";
        for (const auto& log : activityLog) {
            cout << "- " << log << "\n";
        }
        if (membershipExpiry > 0) {
            cout << "Membership Expiry: " << ctime(&membershipExpiry);
        }
    }
};

// Main Menu
void displayMenu() {
    cout << "\n=== Library Management System ===\n";
    cout << "1. Add a Book\n";
    cout << "2. Search by Title\n";
    cout << "3. Search by Author\n";
    cout << "4. Remove a Book\n";
    cout << "5. Display All Books\n";
    cout << "6. Edit Book Details\n";
    cout << "7. Sort Books by Title\n";
    cout << "8. Save to File\n";
    cout << "9. Load from File\n";
    cout << "10. Add a User\n";
    cout << "11. Display All Users\n";
    cout << "12. Borrow a Book\n";
    cout << "13. Return a Book\n";
    cout << "14. Generate Report\n";
    cout << "15. Recommend Books\n";
    cout << "16. Display Library Statistics\n";
    cout << "17. Export Data to CSV\n";
    cout << "18. Import Data from CSV\n";
    cout << "19. Reserve a Book\n";
    cout << "20. Cancel Reservation\n";
    cout << "21. Calculate Fine for Late Return\n";
    cout << "22. Search by Partial Match\n";
    cout << "23. Rate a Book\n";
    cout << "24. Display Top-Rated Books\n";
    cout << "25. Leave Feedback for a Book\n";
    cout << "26. Display Book Availability Heatmap\n";
    cout << "27. Extend Due Date\n";
    cout << "28. Check Membership Expiry\n";
    cout << "29. Add Book to Wishlist\n";
    cout << "30. Remove Book from Wishlist\n";
    cout << "31. Donate a Book\n";
    cout << "32. Send Notification\n";
    cout << "33. Advanced Search Filters\n";
    cout << "34. User Dashboard\n";
    cout << "35. Add User to Reservation Queue\n";
    cout << "36. Update User Profile\n";
    cout << "37. Add Library Event\n";
    cout << "38. Waive Fine\n";
    cout << "39. Display Library Analytics\n";
    cout << "40. Rent a Book\n";
    cout << "41. Display Library Inventory Summary\n";
    cout << "42. Display User Activity Heatmap\n";
    cout << "43. Upload Book Cover Image\n";
    cout << "44. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    vector<Book> books;
    vector<User> users;
    string filename = "library.txt";

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 40: {
                string isbn, userId;
                cout << "Enter ISBN of the book to rent: ";
                getline(cin, isbn);
                cout << "Enter user ID: ";
                getline(cin, userId);
                auto bookIt = find_if(books.begin(), books.end(),
                                      [&isbn](const Book& book) { return book.getISBN() == isbn; });
                auto userIt = find_if(users.begin(), users.end(),
                                      [&userId](const User& user) { return user.getId() == userId; });
                if (bookIt == books.end()) {
                    cout << "Book not found.\n";
                } else if (userIt == users.end()) {
                    cout << "User not found.\n";
                } else if (bookIt->getIsBorrowed()) {
                    cout << "Book is currently borrowed.\n";
                } else {
                    bookIt->setIsBorrowed(true);
                    userIt->borrowBook(isbn);
                    cout << "Book rented successfully. Rental Fee: $" << bookIt->getRentalFee() << "\n";
                }
                break;
            }
            case 41: {
                int totalBooks = books.size();
                int availableBooks = count_if(books.begin(), books.end(),
                                              [](const Book& book) { return !book.getIsBorrowed(); });
                int borrowedBooks = totalBooks - availableBooks;

                unordered_map<string, int> categoryCounts;
                for (const auto& book : books) {
                    categoryCounts[book.getCategory()]++;
                }

                cout << "\n=== Library Inventory Summary ===\n";
                cout << "Total Books: " << totalBooks << "\n";
                cout << "Available Books: " << availableBooks << "\n";
                cout << "Borrowed Books: " << borrowedBooks << "\n";
                cout << "Categories:\n";
                for (const auto& pair : categoryCounts) {
                    cout << "- " << pair.first << ": " << pair.second << " books\n";
                }
                cout << "Availability Percentage: "
                     << static_cast<double>(availableBooks) / totalBooks * 100 << "%\n";
                break;
            }
            case 42: {
                cout << "\n=== User Activity Heatmap ===\n";
                for (size_t i = 0; i < users.size(); ++i) {
                    const auto& user = users[i];
                    cout << "User " << i + 1 << " (" << user.getName() << "):\n";
                    for (size_t j = 0; j < user.getActivityLog().size(); ++j) {
                        cout << "*"; // Each '*' represents one activity
                    }
                    cout << " (" << user.getActivityLog().size() << " activities)\n";
                }
                break;
            }
            case 43: {
                string isbn, imagePath;
                cout << "Enter ISBN of the book to upload cover image: ";
                getline(cin, isbn);
                cout << "Enter file path for the cover image: ";
                getline(cin, imagePath);
                auto bookIt = find_if(books.begin(), books.end(),
                                      [&isbn](const Book& book) { return book.getISBN() == isbn; });
                if (bookIt == books.end()) {
                    cout << "Book not found.\n";
                } else {
                    bookIt->setCoverImagePath(imagePath);
                    cout << "Cover image uploaded successfully.\n";
                }
                break;
            }
            case 44: {
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}