namespace The_Library_of_Books
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Library library = new Library();

            BookShelf shelf1 = new BookShelf(1);
            Book book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
            shelf1.AddBook(book1);
            shelf1.AddBook(new Book("The Sun Also Rises", "Ernest Hemingway", 1926));
            shelf1.AddBook(new Book("Of Mice and Men", "John Steinbeck", 1937));
            shelf1.AddBook(new Book("The Scarlet Letter", "Nathaniel Hawthorne", 1850));
            shelf1.AddBook(new Book("Frankenstein", "Mary Shelley", 1818));
            library.BookShelves.Add(shelf1);
            // Shelf 2 with 5 books
            BookShelf shelf2 = new BookShelf(2);
            shelf2.AddBook(new Book("1984", "George Orwell", 1949));
            shelf2.AddBook(new Book("To Kill a Mockingbird", "Harper Lee", 1960));
            shelf2.AddBook(new Book("Moby Dick", "Herman Melville", 1851));
            shelf2.AddBook(new Book("Pride and Prejudice", "Jane Austen", 1813));
            shelf2.AddBook(new Book("The Catcher in the Rye", "J.D. Salinger", 1951));
            library.BookShelves.Add(shelf2);

            // Shelf 3 with 5 books
            BookShelf shelf3 = new BookShelf(3);
            shelf3.AddBook(new Book("The Hobbit", "J.R.R. Tolkien", 1937));
            shelf3.AddBook(new Book("War and Peace", "Leo Tolstoy", 1869));
            shelf3.AddBook(new Book("The Odyssey", "Homer", -800));
            shelf3.AddBook(new Book("Crime and Punishment", "Fyodor Dostoevsky", 1866));
            shelf3.AddBook(new Book("The Divine Comedy", "Dante Alighieri", 1320));
            library.BookShelves.Add(shelf3);

            // Shelf 4 with 5 books
            BookShelf shelf4 = new BookShelf(4);
            shelf4.AddBook(new Book("Brave New World", "Aldous Huxley", 1932));
            shelf4.AddBook(new Book("The Iliad", "Homer", -750));
            shelf4.AddBook(new Book("Don Quixote", "Miguel de Cervantes", 1605));
            shelf4.AddBook(new Book("Jane Eyre", "Charlotte Brontë", 1847));
            shelf4.AddBook(new Book("The Brothers Karamazov", "Fyodor Dostoevsky", 1880));
            library.BookShelves.Add(shelf4);

            // Display the shelves and the books inside
            foreach (var shelf in library.BookShelves)
            {
                Console.WriteLine($"Shelf ID: {shelf.Number}");
                foreach (var b in shelf.Books)
                {
                    Console.WriteLine($"- {b.Title} by {b.Author} ({b.YearPublished})");
                }
            }
        }
    }
}
