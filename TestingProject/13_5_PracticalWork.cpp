// создадим небольшую систему, моделирующую электронную библиотеку
// здесь все взаимосвязано, поэтому для удобства не делаю разделений на отдельные файлы

/////// Реализация метода Фасад ///////
#include <iostream>
#include <string>
#include <vector>

class Book
{
public:
    void read()
    {
        std::cout << "Reading a book." << std::endl;
    }
};

class Librarian
{
public:
    void assist()
    {
        std::cout << "Librarian is assisting you." << std::endl;
    }
};

class LibraryFacade
{
private:
    Book book;
    Librarian librarian;
public:
    void visitLibrary()
    {
        librarian.assist();
        book.read();
    }
};

/////// Реализация метода Заместитель ///////
class BookProxy
{
private:
    Book* realBook;
    bool isAvailable;
public:
    BookProxy() : realBook(nullptr), isAvailable(true) {}
    ~BookProxy()
    {
        delete realBook;
    }

    void read()
    {
        if (isAvailable)
        {
            if (realBook == nullptr)
            {
                realBook = new Book();
            }
            realBook->read();
        }
        else
        {
            std::cout << "The book is currently unavailable." << std::endl;
        }
    }

    void setAvailability(bool availability)
    {
        isAvailable = availability;
    }
};

/////// Реализация метода Компоновщик ///////
class LibraryComponent
{
public:
    virtual void showDetails() = 0;
    virtual ~LibraryComponent() {}
};

class BookLeaf : public LibraryComponent
{
private:
    std::string title;
public:
    BookLeaf(const std::string& t) : title(t) {}
    void showDetails() override
    {
        std::cout << "Book Title: " << title << std::endl;
    }
};

class LibraryComposite : public LibraryComponent
{
private:
    std::vector<LibraryComponent*> children;
public:
    ~LibraryComposite()
    {
        for (auto& child : children)
        {
            delete child;
        }
    }

    void add(LibraryComponent* component)
    {
        children.push_back(component);
    }

    void showDetails() override
    {
        for (auto& child : children)
        {
            child->showDetails();
        }
    }
};

/////// Реализация метода Адаптер ///////
class EBook
{
public:
    void open()
    {
        std::cout << "Opening еBook." << std::endl;
    }
};

class EBookAdapter
{
private:
    EBook* eBook;
public:
    EBookAdapter(EBook* eb) : eBook(eb) {}
    ~EBookAdapter()
    {
        delete eBook;
    }

    void read()
    {
        eBook->open();
    }
};

int main() {
    // Фасад
    LibraryFacade library;
    library.visitLibrary();

    // Заместитель
    BookProxy bookProxy;
    bookProxy.read();
    bookProxy.setAvailability(false);
    bookProxy.read();

    // Компоновщик
    LibraryComposite libraryComposite;
    libraryComposite.add(new BookLeaf("C++ Programming"));
    libraryComposite.add(new BookLeaf("Design Patterns"));
    libraryComposite.showDetails();

    // Адаптер
    EBook* eBook = new EBook();
    EBookAdapter eBookAdapter(eBook);
    eBookAdapter.read();

    return 0;
}