/*Тема:
Статические переменные-члены и функциичлены, различные способы инициализации

Задание.

Разработать класс String, который в дальнейшем будет
использоваться для работы со строками. Класс должен
содержать:

Конструктор по умолчанию, позволяющий создать
строку длиной 80 символов;

Конструктор, позволяющий создавать строку произвольного размера;

Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.

Необходимо создать деструктор, а также использовать
механизмы делегирования конструкторов, если это возможно.

Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.

Также нужно реализовать статическую функцию - член, которая будет возвращать количество созданных объектов строк

*/
#include <iostream>
using namespace std;

static int strCount = 0;

class String
{
private:
    char* str;
    int length;
public:
    String();
    String(const char* str);
    String(const char* str, int _length);

    ~String();

    const char* getStr()const;
    void createStr(const char* _Str);
    int getCount()const;
    void cinText();

};

String::String(const char* str, int _length)
{

    length = _length + 1;
    this ->str = new char[length];
    for (int i = 0; i <= length; i++)
    {
        this->str[i] = str[i];
    }
    strCount++;
}
String::~String()
{
    if (str != 0)
        delete[] str;
}
const char* String::getStr() const
{
    return str;
}

void String::createStr(const char* _Str)
{
    int strLength = strlen(_Str);
    str = new char[strLength + 1];

    for (int i = 0; i <= strLength; i++)
    {
        str[i] = _Str[i];
    }
}
int String::getCount() const
{
    return strCount;
}

void String::cinText() {
    int len = 5;
    char* tmp = new char[len];

    //bool nig = false;
    char c;
    int i = 0;
    while (cin.get(c)) {
        if (i >= len) {
            len += 5;
            char* tmp2 = new char[len];

            for (int j = 0; j < len - 5; j++)
                tmp2[j] = tmp[j];

            delete[] tmp;
            tmp = tmp2;
        }

        if (c == '\n') {
            tmp[i] = '\0';
            break;
        }

        tmp[i] = c;
        i++;
    }

    str = new char[len];
    length = len;

    for (int i = 0; i < len; i++) {
        str[i] = tmp[i];
    }

    delete[] tmp;
}

String::String()
{
    cout << "Конструктор на произвольное колличество символов создан " << this << "\n\n";
    cinText();
    ++strCount;

};

String::String(const char* str)
{
    cout << "Конструктор на произвольное колличество символов создан " << this << "\n\n";
    createStr(str);
    ++strCount;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    String str("pewpewpewpew");
    String str1;
    String str2("jkwadjklawjdklj");

    //cout << str1.getStr();
    cout << str2.getStr();
    cout << "\n\n";
    cout << str.getStr();
    cout << "\n\n";

    cout << "String objects totaL: " << strCount;
    
}

