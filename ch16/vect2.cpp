//
// Created by Tarryzking on 2023/5/29.
//
#include "iostream"
#include "string"
#include "vector"

struct Review {
    std::string title;
    int rating{};
};

bool fillReview(Review &review) {
    std::cout << "Enter book title (q to quit): ";
    std::getline(std::cin, review.title);
    if (review.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> review.rating;
    if (!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void showReview(const Review &review) {
    std::cout << review.rating << "\t" << review.title << std::endl;
}

int main() {
    using std::cout;
    using std::vector;

    vector<Review> books;
    Review temp;
    while (fillReview(temp)) {
        books.push_back(temp);
    }
    int num = books.size();
    if (num > 0) {
        cout << "Thank you. You entered the following:\n"
             << "Rating\tBook\n";
        for (int i = 0; i < num; ++i) {
            showReview(books[i]);
        }
        cout << "Reprising:\n"
             << "Rating\tBook\n";
        vector<Review>::iterator ptr;
        for (ptr = books.begin(); ptr != books.end(); ++ptr) {
            showReview(*ptr);
        }
        vector<Review> old_list(books);
        if (num > 3) {
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasure:\n";
            for (ptr = books.begin(); ptr != books.end(); ++ptr) {
                showReview(*ptr);
            }
            books.insert(books.begin(), old_list.begin() + 1, old_list.begin() + 2);
            cout << "After insertion:\n";
            for (ptr = books.begin(); ptr != books.end(); ++ptr) {
                showReview(*ptr);
            }
        }
        books.swap(old_list);
        cout << "Swapping old list with books:\n";
        for (ptr = books.begin(); ptr != books.end(); ++ptr) {
            showReview(*ptr);
        }
    } else
        cout << "Nothing entered, nothing gained.\n";
    return 0;
}
