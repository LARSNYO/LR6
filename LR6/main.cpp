#include "include.h"

int FractionNumber::operationsCount = 0;

int main() {
	try {
		FractionNumber f1(0, 4);
		FractionNumber f2(1, 6);

		FractionNumber result = f1 + f2;
		std::cout << "Addition result: " << result;

		result = f1 - f2;
		std::cout << "Subtraction result: " << result;

		result = f1.multiply(f2);
		std::cout << "Multiplication result: " << result;

		result = f1.divide(f2);
		std::cout << "Division result: " << result;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit(1);
	}

	try {
		FractionNumber f3;
		std::cout << "Enter a fraction (format: a/b): ";
		std::cin >> f3;
		std::cout << "You entered: " << f3;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit(1);
	}

	try {
		FractionNumber f4(5, 8);
		f4.saveToFile("fraction.txt");
		FractionNumber f5;
		f5.loadFromFile("fraction.txt");
		std::cout << "Loaded fraction from file: " << f5;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit(1);
	}

	try {
		FractionNumber f6(7, 9);
		f6.saveToBinaryFile("fraction.bin");
		FractionNumber f7;
		f7.loadFromBinaryFile("fraction.bin");
		std::cout << "Loaded fraction from binary file: " << f7;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		exit(1);
	}

	try {
		// Создание объектов различных классов
		std::shared_ptr<FractionNumber> frac1 = std::make_shared<FractionNumber>(3, 4);
		std::shared_ptr<FractionNumber> frac2 = std::make_shared<CalculatedFraction>(5, 6);
		std::shared_ptr<FractionNumber> frac3 = std::make_shared<MixedFraction>(2, 7, 8);

		// Добавление элементов в дек
		Deque deque;
		deque.addFront(frac1);
		deque.addRear(frac2);

		// Попытка вставки элемента на индекс 1
		try {
			deque.insertAt(1, frac3);
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Insert error: " << e.what() << std::endl;
		}

		// Отображение элементов дека
		std::cout << "Deque after adding elements: " << std::endl;
		deque.displayAll();

		// Удаление элемента из начала дека
		try {
			deque.removeFront();
			std::cout << "\nDeque after removing front element: " << std::endl;
			deque.displayAll();
		}
		catch (const std::runtime_error& e) {
			std::cerr << "Remove front error: " << e.what() << std::endl;
		}

		// Удаление элемента по индексу
		try {
			deque.removeAt(1); // Изменено на корректный индекс 1
			std::cout << "\nDeque after removing element at index 1:" << std::endl;
			deque.displayAll();
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Remove at error: " << e.what() << std::endl;
		}

		// Поиск элемента по индексу
		try {
			std::shared_ptr<FractionNumber> found = deque.find(0);
			if (found) {
				std::cout << "\nElement found at index 0:" << std::endl;
				found->display();
			}
			else {
				std::cerr << "Find error: Element not found at index 0." << std::endl;
			}
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Find error: " << e.what() << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Deque operation error: " << e.what() << std::endl;
		exit(1);
	}
}