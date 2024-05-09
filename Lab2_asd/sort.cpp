// sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

void insertionSort(std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
            swaps++;
        }
        arr[j + 1] = key;
        swaps -= 1;
    }
}

void shellSort(std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            comparisons++;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
            comparisons++;
            swaps++;
        }
    }
}

int main() {
    std::vector<int> arr100, arr1000, arr10000;
    srand(time(nullptr));
    for (int i = 0; i < 100; ++i) arr100.push_back(rand() % 1000);
    for (int i = 0; i < 1000; ++i) arr1000.push_back(rand() % 10000);
    for (int i = 0; i < 10000; ++i) arr10000.push_back(rand() % 100000);

    //  arr100
    std::cout << "before sort" << std::endl;
    for (int el : arr100) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    int comparisons = 0, swaps = 0;
    auto start = std::chrono::steady_clock::now();
    insertionSort(arr100, comparisons, swaps);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Insertion sort time for arr100: " << elapsed.count() << " milliseconds\n";
    std::cout << "Insertion sort comparisons for arr100: " << comparisons << std::endl;
    std::cout << "Insertion sort swaps for arr100: " << swaps << std::endl;
    std::cout << "after sort" << std::endl;
    for (int el : arr100) {
        std::cout << el << " ";
    }
    std::cout << std::endl;


    comparisons = 0;
    swaps = 0;
    start = std::chrono::steady_clock::now();
    shellSort(arr100, comparisons, swaps);
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Shell sort time for arr100: " << elapsed.count() << " milliseconds\n";
    std::cout << "Shell sort comparisons for arr100: " << comparisons << std::endl;
    std::cout << "Shell sort swaps for arr100: " << swaps << std::endl;

    //  arr1000
    comparisons = 0;
    swaps = 0;
    start = std::chrono::steady_clock::now();
    insertionSort(arr1000, comparisons, swaps);
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Insertion sort time for arr1000: " << elapsed.count() << " milliseconds\n";
    std::cout << "Insertion sort comparisons for arr1000: " << comparisons << std::endl;
    std::cout << "Insertion sort swaps for arr1000: " << swaps << std::endl;

    comparisons = 0;
    swaps = 0;
    start = std::chrono::steady_clock::now();
    shellSort(arr1000, comparisons, swaps);
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Shell sort time for arr1000: " << elapsed.count() << " milliseconds\n";
    std::cout << "Shell sort comparisons for arr1000: " << comparisons << std::endl;
    std::cout << "Shell sort swaps for arr1000: " << swaps << std::endl;

    //  arr10000
    comparisons = 0;
    swaps = 0;
    start = std::chrono::steady_clock::now();
    insertionSort(arr10000, comparisons, swaps);
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Insertion sort time for arr10000: " << elapsed.count() << " milliseconds\n";
    std::cout << "Insertion sort comparisons for arr10000: " << comparisons << std::endl;
    std::cout << "Insertion sort swaps for arr10000: " << swaps << std::endl;

    comparisons = 0;
    swaps = 0;
    start = std::chrono::steady_clock::now();
    shellSort(arr10000, comparisons, swaps);
    end = std::chrono::steady_clock::now();
    elapsed = end - start;
    std::cout << "Shell sort time for arr10000: " << elapsed.count() << " milliseconds\n";
    std::cout << "Shell sort comparisons for arr10000: " << comparisons << std::endl;
    std::cout << "Shell sort swaps for arr10000: " << swaps << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
