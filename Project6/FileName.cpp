#include <iostream>
#include <vector>

using namespace std;

// Шаблонна функція для обчислення середнього значення
template <typename T>
double findAverage(T a[], int size) // Функція, що обчислює середнє значення елементів
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    return static_cast<double>(sum) / size;
}

// Шаблонний клас для перетворення масиву з типу T в тип U
template <typename T, typename U>
class ArrayConverter
{
private:
    T* sourceArray;
    U* resultArray;
    int size;

public:
    ArrayConverter(T* srcArr, U* resArr, int s) : sourceArray(srcArr), resultArray(resArr), size(s) {}

    void convert() // Метод  для конвертації елементів вхідного масиву 
    {
        for (int i = 0; i < size; i++)
        {
            resultArray[i] = static_cast<U>(sourceArray[i]);  // Конвертує кожен елемент з типу T в тип U і записує у масив
        }
    }

    void printConvertedArray() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << resultArray[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Ukrainian");

    int intArr[] = { 10, 20, 30, 40, 50 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    double doubleArr[] = { 1.5, 2.5, 3.5, 4.5 };
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    cout << "Середнє значення масиву цілих чисел: " << findAverage(intArr, intSize) << endl;
    cout << "Середнє значення масиву дійсних чисел: " << findAverage(doubleArr, doubleSize) << endl;

    int intArray[] = { 65, 66, 67, 68, 69 };
    int size = sizeof(intArray) / sizeof(intArray[0]);

    vector<char> charArray(size);

    ArrayConverter<int, char> converter(intArray, charArray.data(), size);
    converter.convert();

    cout << "\nРезультат перетворення з int в char: ";
    converter.printConvertedArray();

    cout << "Масив int: ";
    for (int i = 0; i < size; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    return 0;
}