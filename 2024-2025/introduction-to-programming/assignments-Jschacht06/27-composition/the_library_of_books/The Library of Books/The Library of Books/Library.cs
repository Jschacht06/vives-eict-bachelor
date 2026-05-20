using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Library_of_Books
{
    public class Library
    {
        //attributes
        private string name;
        private List<BookShelf> bookShelves;
        //properties
        public List<BookShelf> BookShelves
        {
            get { return bookShelves; }
            set { bookShelves = value; }
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        //constructor
        public Library()
        {
            bookShelves = new List<BookShelf>();
        }
    }
}
