#include <iostream>
#include <string>

using namespace std;




struct Book
{
	struct Author{
		string name = "Unknown";
		string surname = "Unknown";

	};
	struct Author author;
	string title = "Unknown";
	int year = 0;
	int num_page = 0;
	void display_Book() {
		cout << "Title: " << title << '\n';
		cout << "Author: " << author.name << ' ' << author.surname << '\n';
		cout << "year: " << year << "\n";
		cout << "number of pages: " << num_page << "\n";

	}
};

Book createBooks(string title, string name, string surname, int year, int num_page);

int main() {
	struct Book books[3];
	books[1] = createBooks("War and Peace", "Lev", "Tolstoy", 1873, 1300);
	books[2] = createBooks("And Quiet Flows the Don", "Mihail", "Sholohov", 1940, 720);
	for (int i = 0; i < 3; ++i) {
		books[i].display_Book();
		cout << '\n';
	}

	return 0;

}
Book createBooks(string title, string name, string surname, int year, int num_page) {
	Book res_Book;
	res_Book.title = title;
	res_Book.author.name = name;
	res_Book.author.surname = surname;
	res_Book.year = year;
	res_Book.num_page = num_page;
	return res_Book;
}