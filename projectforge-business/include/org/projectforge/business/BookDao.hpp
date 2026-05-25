#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::book {

struct Book {
    int64_t id = 0;
    std::string title;
    std::string author;
    std::string isbn;
    std::string publisher;
    std::string description;
    int32_t publication_year = 0;
    int32_t edition = 0;
    int32_t total_pages = 0;
    int64_t owner_id = 0;
    int64_t borrowed_by = 0;
    int64_t borrowed_date = 0;
    int64_t due_date = 0;
    std::string status; // AVAILABLE, BORROWED, LOST
    std::string category;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    bool e_book = false;
    std::string e_book_path;
};

inline auto make_book_table() {
    using namespace sqlite_orm;
    return make_table("t_book",
        make_column("id", &Book::id, primary_key().autoincrement()),
        make_column("title", &Book::title),
        make_column("author", &Book::author),
        make_column("isbn", &Book::isbn),
        make_column("publisher", &Book::publisher),
        make_column("description", &Book::description),
        make_column("publication_year", &Book::publication_year),
        make_column("edition", &Book::edition),
        make_column("total_pages", &Book::total_pages),
        make_column("owner_id", &Book::owner_id),
        make_column("borrowed_by", &Book::borrowed_by),
        make_column("borrowed_date", &Book::borrowed_date),
        make_column("due_date", &Book::due_date),
        make_column("status", &Book::status),
        make_column("category", &Book::category),
        make_column("created_at", &Book::created_at),
        make_column("updated_at", &Book::updated_at),
        make_column("e_book", &Book::e_book),
        make_column("e_book_path", &Book::e_book_path));
}

class BookDao : public BaseDao<Book> {
public:
    explicit BookDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<Book> findByAuthor(const std::string& author) const;
    std::vector<Book> findByTitle(const std::string& title) const;
    std::optional<Book> findByIsbn(const std::string& isbn) const;
    std::vector<Book> findByCategory(const std::string& category) const;
    std::vector<Book> findByStatus(const std::string& status) const;
    std::vector<Book> findBorrowed() const;
    std::vector<Book> findAvailable() const;
    std::vector<Book> findBorrowedByUser(int64_t userId) const;
    std::vector<Book> findOverdue(int64_t now) const;
    std::vector<Book> search(const std::string& query) const;

    bool borrow(int64_t bookId, int64_t userId, int64_t dueDate);
    bool returnBook(int64_t bookId);
    bool markLost(int64_t bookId);
    bool extendDueDate(int64_t bookId, int64_t newDueDate);

    json toJson(const Book& book) const override;
    Book fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::book
