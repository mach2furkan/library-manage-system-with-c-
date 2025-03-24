
# 📚 Library Management System (C++)

![License](https://img.shields.io/badge/license-MIT-green) ![C++](https://img.shields.io/badge/language-C++-blue)

The **Library Management System** is a feature-rich console-based application designed to manage all aspects of a library. Built entirely in C++, this system provides tools for managing books, users, borrowing/returning processes, and advanced analytics. Whether you're running a small personal library or a larger institution, this system has you covered.

**Repository Link**: [https://github.com/mach2furkan/library-manage-system-with-c-](https://github.com/mach2furkan/library-manage-system-with-c-)

---

## 🌟 Features

### Core Features
- **Book Management**: Add, remove, edit, and display books with details like title, author, ISBN, and category.
- **User Management**: Add, update, and display user profiles, including borrowed books and activity logs.
- **Borrowing & Returning**: Borrow, return, reserve, and cancel reservations for books.
- **Search & Filtering**: Search books by title, author, ISBN, partial matches, or advanced filters (e.g., category, availability).
- **Recommendation System**: Recommend books based on borrowing history and user preferences.
- **Fine Calculation**: Calculate fines for late returns dynamically.

### Advanced Features
- **Book Rental System**: Rent books with associated fees.
- **Reservation Queue**: Maintain a queue for reserved books.
- **Wishlist**: Allow users to create and manage wishlists.
- **Donation System**: Track book donations and donors.
- **Analytics Dashboard**: Display library statistics, such as most borrowed categories and overdue trends.
- **User Activity Heatmap**: Visualize user activity with a heatmap.
- **Cover Image Upload**: Simulate uploading cover images for books.
- **Inventory Summary**: Provide a detailed summary of the library's inventory, including total books, categories, and availability percentages.

### Algorithms & Data Structures
- **Sorting Algorithms**: Merge Sort, Quick Sort, Heap Sort.
- **Search Algorithms**: Binary Search, Partial Match Search.
- **Graph Algorithms**: BFS and DFS for recommendations.
- **Clustering**: K-Means for categorizing books.
- **Optimization**: Knapsack problem for budgeting, Dijkstra's algorithm for navigation.

---

## 🛠️ Installation and Setup

### Prerequisites
- A C++ compiler (e.g., `g++`, `clang++`).
- Git (for cloning the repository).

### Steps to Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/mach2furkan/library-manage-system-with-c-.git
   cd library-manage-system-with-c-
   ```

2. **Compile the Code**:
   Use a C++ compiler to compile the code:
   ```bash
   g++ -o library_management_system main.cpp
   ```

3. **Run the Program**:
   ```bash
   ./library_management_system
   ```

4. **Optional: Build with CMake**:
   If you prefer using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ./library_management_system
   ```

---

## 🚀 Usage Examples

### Adding a Book
```plaintext
1. Add a Book
Enter book title: The Great Gatsby
Enter book author: F. Scott Fitzgerald
Enter book ISBN: 978-0743273565
Book added successfully!
```

### Searching for a Book
```plaintext
2. Search by Title
Enter title to search: Great
Title: The Great Gatsby, Author: F. Scott Fitzgerald, ISBN: 978-0743273565
```

### Borrowing a Book
```plaintext
12. Borrow a Book
Enter ISBN of the book to borrow: 978-0743273565
Enter user ID: U123
Book borrowed successfully.
```

### Generating Analytics
```plaintext
39. Display Library Analytics
Category: Fiction, Books Borrowed: 15
Category: Non-Fiction, Books Borrowed: 10
Availability Percentage: 75%
```

---

## 📊 Sample Output

Here’s an example of how the program works:

```plaintext
=== Library Management System ===
1. Add a Book
2. Search by Title
3. Search by Author
4. Remove a Book
5. Display All Books
...
Enter your choice: 5
Title: The Great Gatsby, Author: F. Scott Fitzgerald, ISBN: 978-0743273565, Status: Available
Title: 1984, Author: George Orwell, ISBN: 978-0451524935, Status: Borrowed
```

---


## 📜 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

---

## 🙏 Acknowledgments

- Inspired by modern library management systems.
- Built using C++ for performance and simplicity.
- Thanks to the open-source community for their support and contributions.

---

## 🌐 Future Enhancements

- **Web Interface**: Develop a GUI or web-based frontend.
- **Database Integration**: Use SQLite or MySQL for persistent storage.
- **Multi-Language Support**: Add support for multiple languages.
- **Mobile App**: Create a mobile version of the system.

---

## 📧 Contact

For questions, feedback, or collaboration, feel free to reach out:

- **GitHub**: [@mach2furkan](https://github.com/mach2furkan)
- **Project Repository**: [Library Management System](https://github.com/mach2furkan/library-manage-system-with-c-)

