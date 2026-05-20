using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Library_of_Books
{
    public class BookShelf
    {
        //attributes
        private int number;
        private List<Book> books;
        //properties
        public List<Book> Books
        {
            get { return books; }
            set { books = value; }
        }
        public int Number
        {
            get { return number; }
            set { number = value; }
        }
        //constructor
        public BookShelf(int number)
        {
            this.number = number;
            books = new List<Book>();
        }
        public void AddBook(Book book)
        {
            books.Add(book);
        }
    }
}
