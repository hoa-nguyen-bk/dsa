#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Book
{
private:
  char *title;
  char *authors;
  int publishingYear;

public:
  Book()
  {
    /*
     * STUDENT ANSWER
     * TODO: set zero publishingYear and null pointer
     */
    this->publishingYear = 0;
    this->authors = nullptr;
    this->title = nullptr;
  }

  Book(const char *title, const char *authors, int publishingYear)
  {
    /*
     * STUDENT ANSWER
     */
    //+1 cho kí tự kết thúc, ko có nó biết kết thúc chỗ mô
    this->title = new char(strlen(title) + 1);
    strcpy(this->title,title);
    
    this->authors = new char(strlen(authors) +1);
    strcpy(this->authors,authors);
    this->publishingYear=publishingYear;
  }

  Book(const Book &book)
  {
    /*
     * STUDENT ANSWER
     * TODO: deep copy constructor
     */
    this->authors=new char(strlen(book.authors) + 1);
    strcpy(this->authors,book.authors);

    this->title=new char(strlen(book.title) + 1);
    strcpy(this->title,book.title);
    this->publishingYear=book.publishingYear;
  }

  void setTitle(const char *title)
  {
    this->title=new char(strlen(title)+1);
    strcpy(this->title,title);
  }

  void setAuthors(const char *authors)
  {
    this->authors=new char(strlen(authors)+1);
    strcpy(this->authors,authors);
  }

  void setPublishingYear(int publishingYear)
  {
    this->publishingYear = publishingYear;
  }

  char *getTitle() const
  {
    return this->title;
  }

  char *getAuthors() const
  {
    return this->authors;
  }

  int getPublishingYear() const
  {
    return this->publishingYear;
  }

  ~Book()
  {
    delete[] this->authors;
    delete[] this->title;
  }

  void printBook()
  {
    printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
  }
};

int main()
{
  Book book1("Giai tich 1", "Nguyen Dinh Huy", 2000);
  book1.printBook();
  // Giai tich 1
  // Nguyen Dinh Huy
  // 2000
  // Book book1("Giai tich 1", "Nguyen Dinh Huy", 2000);
  // Book book2 = book1;
  // book2.printBook();
  // Giai tich 1
  // Nguyen Dinh Huy
  // 2000
  return 0;
}
