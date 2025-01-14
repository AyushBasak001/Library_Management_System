#include "books.h"

Books::Books(int id, const std::string& t, const std::string& a, int q, int i)
    : bookID(id), title(t), author(a), quantity(q), issued(i) {}

