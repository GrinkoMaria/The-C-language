#include <iostream>
using Load = int;
using CommandCount = int;
enum class Command : int { Exit = 0, Status = 1, Start = 2, Finish = 3 };
enum class State { Idle, Running };
enum class Error { None, AlreadyRunning, InvalidLoad, NotRunning };
enum class ExitCode { Ok = 0, InputError = 1, InvalidInitialLoad = 2 };
namespace config
{
    constexpr Load minLoad{0};
    constexpr Load maxLoad{10};
    constexpr Load minStartLoad{1};
    constexpr Load maxStartLoad{6};
    constexpr CommandCount maxCommands{5};
}
bool isValidLoad(Load load)
{
    return false; // TODO: допустимая начальная нагрузка.
}
bool isKnownCommand(int code)
{
    return false; // TODO: коды 0–3.
}
Error validateCommand(Command command, State state, Load load)
{
    return Error::None; // TODO: правила таблицы.
}
State executeCommand(Command command, State state)
{
    return state; // TODO: новое состояние.
}
void printError(Error error)
{
    switch (error)
    {
    case Error::AlreadyRunning: std::cout << "Already running\n"; break;
    case Error::InvalidLoad: std::cout << "Invalid load for start\n"; break;
    case Error::NotRunning: std::cout << "Not running\n"; break;
    case Error::None: break;
    }
}
void printResult(Command command, State state)
{
    switch (command)
    {
    case Command::Status: std::cout << "Status\n"; break;
    case Command::Start: std::cout << "Started\n"; break;
    case Command::Finish: std::cout << "Finished\n"; break;
    case Command::Exit: return;
    }
    std::cout << std::boolalpha << "Running: "
              << (state == State::Running) << "\n";
}
ExitCode runSession(Load load)
{
    State state{State::Idle};
    CommandCount completed{};
    while (completed < config::maxCommands)
    {
        int code{};
        if (!(std::cin >> code))
        {
            std::cout << "Input error\n";
            return ExitCode::InputError;
        }
        // TODO: неизвестный код, преобразование, Exit.
        // TODO: валидация, сообщение при отказе, continue.
        // TODO: операция, счётчик и сообщение об успехе.
        break; // TODO: удалить после реализации цикла.
    }
    std::cout << "Completed: " << completed << "\n";
    return ExitCode::Ok;
}
int main()
{
    Load load{};
    if (!(std::cin >> load))
    {
        std::cout << "Input error\n";
        return static_cast<int>(ExitCode::InputError);
    }
    if (!isValidLoad(load))
    {
        std::cout << "Invalid initial load\n";
        return static_cast<int>(ExitCode::InvalidInitialLoad);
    }
    return static_cast<int>(runSession(load));
}
