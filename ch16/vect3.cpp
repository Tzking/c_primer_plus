//
// Created by Tarryzking on 2023/5/31.
//
#include <random>

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

struct Review {
    std::string title;
    int rating{};
};

bool operator<(const Review &r1, const Review &r2);

bool worseThan(const Review &r1, const Review &r2);

bool fillReview(Review &r);

void showReview(const Review &r);

int main() {
    using namespace std;
    vector<Review> books;
    Review temp;
    while (fillReview(temp)) {
        books.push_back(temp);
    }
    if (books.size() > 0) {
        cout << "Thank you. You entered the following "
             << books.size() << "ratings:\n"
             << "Rating\tBook\n";
//        for (auto x : books) showReview(x);
        for_each(books.begin(), books.end(), showReview);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), showReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), showReview);

        shuffle(books.begin(), books.end(), std::mt19937(std::random_device()()));
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), showReview);

    } else cout << "No entries. ";
    cout << "Done.\n";
    return 0;
}

bool operator<(const Review &r1, const Review &r2) {
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool worseThan(const Review &r1, const Review &r2) {
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

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