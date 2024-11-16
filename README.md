# Лабораторная работа 7

## Теоретическая часть
Ознакомьтесь с циклом статей https://metanit.com/cpp/tutorial/8.2.php и https://metanit.com/cpp/tutorial/8.3.php


### Инструкция
Каждое задание должно быть выполненно в отдельном `.cpp` файле.
Прототипы функции должны быть вынесены в `header.hpp` файл.
Все `.cpp` файлы добавить в `CMakeLists.txt`

### Задание 1
* Реализуйте функцию сохранения массива слов в файл
```cpp
void saveToFile(const std::string& filename, const std::vector<std::string>& data);
```

* Реализуйте функцию загрузки массива слов из файла
```cpp
void loadFromFile(const std::string& filename, std::vector<std::string>& outData);
```

### Задание 2
Есть структура `Book`
```cpp
struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};
```

* Реализуйте функцию сохранения массива книг в файл
```cpp
void saveToFile(const std::string& filename, const std::vector<Book>& data);
```

* Реализуйте функцию загрузки массива книг из файла
```cpp
void loadFromFile(const std::string& filename, std::vector<Book>& outData);
```

### Задание 3
Есть структура `Student`
```cpp
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = std::map<std::string, std::vector<Student>>;
```

* Реализуйте функцию сохранения группы в файл
```cpp
void saveToFile(const std::string& filename, const Groups& groups);
```

* Реализуйте функцию загрузки группы из файла
```cpp
void loadFromFile(const std::string& filename, const Groups& outGroups);
```
