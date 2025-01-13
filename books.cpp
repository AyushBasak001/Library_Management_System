#include "books.h"

Books::Books(int id, const string& t, const string& a, int q, int i)
    : bookID(id), title(t), author(a), quantity(q), issued(i) {}

