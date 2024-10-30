#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_08.1-char[]/lab_08.1-char[].cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsForStringFunctions
{
    TEST_CLASS(UnitTestsForStringFunctions)
    {
    public:

        // ���� ��� ������� CountOGOAGA
        TEST_METHOD(TestCountOGOAGA_NoMatches)
        {
            char str[] = "ABCD"; // ���� ����� "OGO" ��� "AGA"
            Assert::AreEqual(0, CountOGOAGA(str));
        }

        TEST_METHOD(TestCountOGOAGA_SingleMatch)
        {
            char str[] = "XOGOZ"; // ���� ����� "OGO"
            Assert::AreEqual(1, CountOGOAGA(str));
        }

        TEST_METHOD(TestCountOGOAGA_MultipleMatches)
        {
            char str[] = "XOGOAGAXOGOA"; // �� ����� "OGO" � ���� "AGA"
            Assert::AreEqual(3, CountOGOAGA(str));
        }

        // ���� ��� ������� ReplaceOGOAGA
        TEST_METHOD(TestReplaceOGOAGA_NoMatches)
        {
            char str[] = "ABCD";
            char expected[] = "ABCD";
            char* result = ReplaceOGOAGA(str);
            Assert::AreEqual(expected, result);
            delete[] result;
        }

        TEST_METHOD(TestReplaceOGOAGA_SingleMatch)
        {
            char str[] = "XOGOZ";
            char expected[] = "X**Z";
            char* result = ReplaceOGOAGA(str);
            Assert::AreEqual(expected, result);
            delete[] result;
        }

        TEST_METHOD(TestReplaceOGOAGA_MultipleMatches)
        {
            char str[] = "XOGOAGAXOGOA";
            char expected[] = "X****X**A";
            char* result = ReplaceOGOAGA(str);
            Assert::AreEqual(expected, result);
            delete[] result;
        }

        TEST_METHOD(TestReplaceOGOAGA_ConsecutiveMatches)
        {
            char str[] = "OGOOGO";
            char expected[] = "**";
            char* result = ReplaceOGOAGA(str);
            Assert::AreEqual(expected, result);
            delete[] result;
        }
    };
}
