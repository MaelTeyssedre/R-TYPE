/**
 * @file ILogger.hpp
 * 
 * @brief Interface for the logger lib
 */

#ifndef ILOGGER_HPP_
    #define ILOGGER_HPP_

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <mutex>
    #include <exception>
    #include <ctime>

    /**
    * \class Logger class
    * \brief Used to store log in a file.
    */
    class ILogger {
        public:
            /**
            * \brief Close a log file
            */
            virtual ~ILogger() = default;
            
            /**
            * \fn virtual auto log(std::string message) -> void = 0
            * 
            * \brief log message into a file
            * 
            * \param message to log
            */
            virtual auto log(std::string message) -> void = 0;
            
            /**
            * \fn virtual auto logln(std::string message) -> void = 0
            * 
            * \brief log message into a file and and an endline
            * 
            * \param message to log
            */
            virtual auto logln(std::string message) -> void = 0;

            /**
            * \fn virtual auto operator<<(std::string buffer) -> void = 0
            * 
            * \brief Add a message to the log file // Same as log()
            * 
            * \param Content to add
            */
            virtual auto operator<<(std::string buffer) -> void = 0;
    };

#endif /* !LOGGER_HPP_ */
