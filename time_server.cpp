#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функции:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля LastFetchedTime
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
        // поместим вызов функции AskTimeServer в try-catch блок
        try {
            last_fetched_time = AskTimeServer();
        }
        catch (const system_error&) {  // ловим только system_error
        }
        // возвращаем значение поля — либо обновлённое, либо нет
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
