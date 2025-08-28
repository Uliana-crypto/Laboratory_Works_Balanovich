#include "operations.h"

void checkFile(std::ifstream& file)
{
    if (!file.good())
    {
        throw std::runtime_error("File does not exist");
    }
    if (!file)
    {
        throw std::runtime_error("The file does not open");
    }
    if (file.peek() == EOF)
    {
        throw std::runtime_error("File is empty");
    }
}

void CheckOutputFile(std::ofstream& fout)
{
    if (!fout.good())
    {
        throw std::runtime_error("File does not exist\n");
    }
    if (!fout)
    {
        throw std::runtime_error("The file does not open\n");
    }
}

void readStudents(std::ifstream& filename, Student* students, int32_t size)
{
    std::string line;
    for (int32_t i = 0; i < size && std::getline(filename, line); ++i) 
	{
        std::stringstream input(line);
        std::string token;

        std::getline(input, token, ';');
        students[i].course = std::stoi(token);
        std::getline(input, token, ';');
        students[i].group = std::stoi(token);

        std::getline(input, students[i].name, ';');
        for (int32_t j = 0; j < 3; ++j) {
            std::getline(input, token, ',');
            students[i].grades[j] = std::stoi(token);
        }
    }
}
void printStudentsToConsole(Student* students, int32_t size) 
{
    for (int32_t i = 0; i < size; ++i) 
	{
        std::cout << "Curse: " << students[i].course << "\n"
            << "Group: " << students[i].group << "\n"
            << "Surname: " << students[i].name << "\n"
            << "Grades: ";
        for (int32_t j = 0; j < 3; ++j) {
            std::cout << students[i].grades[j] << (j < 2 ? ", " : "\n");
        }
        std::cout << '\n';
    }
}
void inputStudents(Student* students, int32_t size) 
{
    for (int32_t i = 0; i < size; ++i)
    {
        std::cout << "Student - " << i + 1 << "\n";

        std::cout << "Curse: ";
        std::cin >> students[i].course;

        std::cout << "Group: ";
        std::cin >> students[i].group;

        std::cout << "Surname: ";
        std::cin.ignore();
        std::getline(std::cin, students[i].name);

        std::cout << "3 marks: ";
        for (int32_t j = 0; j < 3; ++j) 
        {
            std::cin >> students[i].grades[j];
        }
    }
}
void generateRandomStudents(Student* arr, int32_t size)
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

    const std::string maleFirstNames[] = { "Иван", "Пётр", "Алексей" };
    const std::string femaleFirstNames[] = { "Ольга", "Мария", "Елена" };

    const std::string maleLastNames[] = { "Иванов", "Сидоров", "Смирнов" };
    const std::string femaleLastNames[] = { "Петрова", "Кузнецова", "Волкова" };

    for (int32_t i = 0; i < size; ++i)
    {
        bool isMale = std::rand() % 2;

        std::string first = isMale
            ? maleFirstNames[std::rand() % 3]
            : femaleFirstNames[std::rand() % 3];

        std::string last = isMale
            ? maleLastNames[std::rand() % 3]
            : femaleLastNames[std::rand() % 3];

        arr[i].name = first + " " + last;
        arr[i].course = 1 + std::rand() % 4;
        arr[i].group = 100 + std::rand() % 10;

        for (int32_t& grade : arr[i].grades)
            grade = 3 + std::rand() % 3;
    }
}
void writeStudentsToFile(std::ofstream& filename, Student* students, int32_t size) 
{
    for (int32_t i = 0; i < size; ++i) 
    {
        filename << students[i].course << ' ' << students[i].group << ' ' << students[i].name << '\n';
        for (int32_t j = 0; j < 3; ++j) 
        {
            filename << std::setw(3) << students[i].grades[j] << (j < 2 ? ' ' : '\n');
        }
    }
}

void getDirection(char& direction)
{
	std::cout << "Введите +, если хотите ,чтобы сортировка была по возрастанию,и -, если наоборот\n";
	std::cin >> direction;
	if (direction != '+' && direction != '-')
	{
		throw std::invalid_argument("Используйте только '+' или '-'.");
	}
}

void inputSize(int32_t& size)
{
	std::cout << "Введите количество элементов или строк: ";
	std::cin >> size;
}

int32_t countLines(std::string& filename)
{
	std::ifstream fin(filename);
    int32_t count = 0;
    std::string line;
    while (std::getline(fin, line))
    {
        if (!line.empty()) ++count;
    }

    return count;
}
