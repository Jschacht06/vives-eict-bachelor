using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Library_of_Books
{
    public class Book
    {
        //attributes
        private string title;
        private string author;
        private int yearPublished;
        //properties
        public string Title
        {
            get { return title; }
            set { title = value; }
        }
        public string Author
        {
            get { return author; }
            set { author = value; }
        }
        public int YearPublished
        {
            get { return yearPublished; }
            set { yearPublished = value; }
        }
        //constructor
        public Book(string title, string author, int yearPublished)
        {
            this.title = title;
            this.author = author;
            this.yearPublished = yearPublished;
        }


    }
}
