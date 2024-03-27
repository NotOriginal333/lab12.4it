#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.4it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Node* head = nullptr;

            append(head, 1);
            append(head, 2);
            append(head, 3);

            Assert::AreEqual(head->data, 1);
            Assert::AreEqual(head->next->data, 2);
            Assert::AreEqual(head->next->next->data, 3);
        }
    };
}
