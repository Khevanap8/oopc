#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <exception>
using namespace std;

class LibraryException : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "LibraryException occurred.";
    }
};

class BookNotFoundException : public LibraryException
{
public:
    const char* what() const noexcept override
    {
        return "Error: Book not found in the library.";
    }
};

class MemberNotFoundException : public LibraryException
{
public:
    const char* what() const noexcept override
    {
        return "Error: Member ID not found.";
    }
};

class OverdueBookException : public LibraryException
{
public:
    const char* what() const noexcept override
    {
        return "Error: Member has overdue books.";
    }
};

map<int, string> books = {
    {101, "The Alchemist"},
    {102, "1984"},
    {103, "To Kill a Mockingbird"}
};

map<int, string> members = {
    {1, "Alice"},
    {2, "Bob"}
};

queue<pair<int, int>> borrowRequests;

map<int, bool> overdueStatus = {
    {1, false},
    {2, true}
};

void processBorrowRequest(int memberId, int bookId)
{
    cout << "\nProcessing borrow request - Member ID: " << memberId << ", Book ID: " << bookId << endl;
    if (members.find(memberId) == members.end())
        throw MemberNotFoundException();
    if (books.find(bookId) == books.end())
        throw BookNotFoundException();
    if (overdueStatus[memberId])
        throw OverdueBookException();
    cout << members[memberId] << " borrowed \"" << books[bookId] << "\" successfully.\n";
}

const int MAX_BOOKS = 3;
const int MAX_MEMBERS = 2;
int bookIds[MAX_BOOKS] = {201, 202, 203};
string bookTitles[MAX_BOOKS] = {"C++ Primer", "Clean Code", "Data Structures"};
int memberIds[MAX_MEMBERS] = {10, 20};
string memberNames[MAX_MEMBERS] = {"Charlie", "Dana"};
bool overdueStatusArray[MAX_MEMBERS] = {false, false};

int findBookIndex(int id)
{
    for (int i = 0; i < MAX_BOOKS; ++i)
        if (bookIds[i] == id) return i;
    return -1;
}

int findMemberIndex(int id)
{
    for (int i = 0; i < MAX_MEMBERS; ++i)
        if (memberIds[i] == id) return i;
    return -1;
}

void manualBorrow(int memberId, int bookId)
{
    cout << "\n[Array Mode] Processing borrow request - Member ID: " << memberId << ", Book ID: " << bookId << endl;
    int mIndex = findMemberIndex(memberId);
    if (mIndex == -1)
        throw MemberNotFoundException();
    int bIndex = findBookIndex(bookId);
    if (bIndex == -1)
        throw BookNotFoundException();
    if (overdueStatusArray[mIndex])
        throw OverdueBookException();
    cout << memberNames[mIndex] << " borrowed \"" << bookTitles[bIndex] << "\" successfully.\n";
}

int main()
{
    try
    {
        processBorrowRequest(1, 101);
        processBorrowRequest(2, 103);
    }
    catch (const LibraryException& e)
    {
        cerr << "STL Exception: " << e.what() << endl;
    }

    try
    {
        manualBorrow(10, 202);
        manualBorrow(11, 202);
    }
    catch (const LibraryException& e)
    {
        cerr << "Array Exception: " << e.what() << endl;
    }

    return 0;
}
