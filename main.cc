#include <iostream>
#include "null_ptr.h"
#include "my_string.h"
#include "binary_number.h"
#include "schedule_record.h"
#include "linked_list.h"

int main(void)
{
    const const char** binaries = new const char*[5] {
        "0100010",
        "11001",
        "100101011",
        "10421010",
        nullptr
    };

    LinkedList<MyString> list;
    MyString str("Hello, World!");
    MyString str1("Hello, C++!");
    MyString findKeyword("Hello");
    ScheduleRecord record("24.12.2023", "02.01.2023", false);
    list.Add(&str);
    list.Add(&str1);
    list.Add(&record);
    MyString* foundStrings = list.Find(findKeyword);
    for (int i = 0; i < 5; ++i) {
        try {
            BinaryNumber num(binaries[i]);
            list.Add(&num);
            std::cout << "Added binary number \"" << num << "\" into the list." << std::endl;
            std::cout << "String list: " << list << std::endl;
        }
        catch(std::invalid_argument) {
            std::cout << "Invalid binary number detected (\"" << binaries[i] << "\"). Skipping this number..." << std::endl;
            continue;
        }
        catch (null_ptr n) {
            std::cout << n.what() << std::endl;
            continue;
        }
    }
    std::cout << "Found strings: " << std::endl;
    while (foundStrings->GetLength() > 0) {
        std::cout << *foundStrings << std::endl;
        foundStrings++;
    }

    int nums[5] = { 7, 2, 5, 1, 9 };
    LinkedList<int> ints;
    for (int i = 0; i < 5; ++i) {
        ints.Add(&nums[i]);
    }
    std::cout << "Integers list: " << ints << std::endl;

    float flots[5] = { 7.2, 2.1, 3.14, 1.8, 9.6 };
    LinkedList<float> floats;
    for (int i = 0; i < 5; ++i) {
        floats.Add(&flots[i]);
    }
    std::cout << "Floats list: " << floats << std::endl;
}