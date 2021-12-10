#include "Logger.hpp"

Logger::Logger()
{
    static bool singleton = false;
    if (singleton == true)
        throw std::bad_alloc();
    file_name = "Log";
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    file_name += "_";
    file_name += std::to_string(ti->tm_mday);
    file_name += "-"; 
    file_name += std::to_string(ti->tm_mon);
    file_name += "_";
    file_name += std::to_string(ti->tm_hour);
    file_name += "-";
    file_name += std::to_string(ti->tm_min);
    file_name += "-";
    file_name += std::to_string(ti->tm_sec);
    file_name += ".txt";
    std::cout << file_name << std::endl;
    _file.open(file_name);
    _file.close();
}

Logger::~Logger()
{
}

void Logger::log(std::string message)
{
    lock.lock();
    _file.open(file_name, std::fstream::app);
    _file << message;
    _file.flush();
    _file.close();
    lock.unlock();
}

void Logger::logln(std::string message)
{
    auto tp = std::chrono::system_clock::now();
	auto dur = tp.time_since_epoch();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::thread::id this_id = std::this_thread::get_id();

    lock.lock();
    _file.open(file_name, std::fstream::app);
    _file << time << " : " << std::this_thread::get_id() << " -> ";
    _file << message << std::endl;
    _file.flush();
    _file.close();
    lock.unlock();
}

void Logger::operator<<(std::string buffer)
{
    auto tp = std::chrono::system_clock::now();
	auto dur = tp.time_since_epoch();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::thread::id this_id = std::this_thread::get_id();

    lock.lock();
    _file.open(file_name, std::fstream::app);
    _file << time << " : " << std::this_thread::get_id() << " -> ";
    _file << buffer << std::endl;
    _file.flush();
    _file.close();
    lock.unlock();
}
