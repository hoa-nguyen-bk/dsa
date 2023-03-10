class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        publishingYear = 0;
        title = nullptr;
        authors = nullptr;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
         setTitle(title);
         setAuthors(authors);
         setPublishingYear(publishingYear);
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
         setTitle(book.title);
         setAuthors(book.authors);
         setPublishingYear(book.publishingYear);
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
        //  if(this->title) delete[] this->title;
         this->title = new char[strlen(title) + 1];
         for(int i = 0; i < (int)strlen(title) + 1; i++){
             this->title[i] = title[i];
         }
        //  this->title[strlen(title)] = '\0';
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        //  if(this->authors) delete[] this->authors;
         this->authors = new char[strlen(authors) + 1];
         for(int i = 0; i < (int)strlen(authors) + 1; i++){
             this->authors[i] = authors[i];
         }
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
         this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
         return title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
         return authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
         return publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        if(this->title) delete[] title;
        if(this->authors) delete[] authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};