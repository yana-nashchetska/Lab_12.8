#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.8/Lab_12.8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab128test
{
	TEST_CLASS(Lab128test)
	{
	public:

		TEST_METHOD(TestInsert)
		{
			TextbookPtr head = nullptr;
			TextbookPtr tail = nullptr;

			// Додати елементи до списку
			Insert(head, tail, "Author1", "Title1", 10);
		
			string expected_author1 = "Author1";
			string expected_title1 = "Title1";
			int expected_reviews1 = 10;

			// Перевіряєо чи правильно додались елементи
			Assert::AreEqual(expected_author1, head->author);
			Assert::AreEqual(expected_title1, head->title);
			Assert::AreEqual(expected_reviews1, head->positiveReviews);


		}
	};
}
