#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Textbook
{
    string author;
    string title;
    int positiveReviews;
    Textbook* prev;
    Textbook* next;
};

typedef Textbook* TextbookPtr;

void Insert(TextbookPtr& head, TextbookPtr& tail, const string& author, const string& title, int positiveReviews);
void PrintList(TextbookPtr head);
void FilterList(TextbookPtr& head, TextbookPtr& tail, int minPositiveReviews);

int main()
{
    TextbookPtr head = nullptr;
    TextbookPtr tail = nullptr;

    ifstream inputFile("D:\\АП\\Лабораторні роботи\\Lab_12\\Lab_12.8\\books.txt");
    if (inputFile.is_open())
    {
        string author, title;
        int positiveReviews;

        while (inputFile >> author >> title >> positiveReviews)
        {
            Insert(head, tail, author, title, positiveReviews);
        }

        inputFile.close();

        cout << " Input List:" << endl;
        PrintList(head);

        int minReviews;
        cout << "\n Enter the minimum number of positive reviews: ";
        cin >> minReviews;

        FilterList(head, tail, minReviews);

        cout << "\n Output List:" << endl;
        PrintList(head);
    }
    else
    {
        cout << " Failed to open the input file." << endl;
    }

    return 0;
}

void Insert(TextbookPtr& head, TextbookPtr& tail, const string& author, const string& title, int positiveReviews)
{
    TextbookPtr newNode = new Textbook;
    newNode->author = author;
    newNode->title = title;
    newNode->positiveReviews = positiveReviews;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void PrintList(TextbookPtr head)
{
    TextbookPtr current = head;

    while (current != nullptr)
    {
        cout << " Author: " << current->author << ", Title: " << current->title
            << ", Positive Reviews: " << current->positiveReviews << endl;

        current = current->next;
    }
}

void FilterList(TextbookPtr& head, TextbookPtr& tail, int minPositiveReviews)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->positiveReviews < minPositiveReviews)
    {
        TextbookPtr temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        delete temp;

        FilterList(head, tail, minPositiveReviews);
    }
    else
    {
        FilterList(head->next, tail, minPositiveReviews);
    }
}
