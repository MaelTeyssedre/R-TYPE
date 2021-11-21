/**
 * @file ILogger.hpp
 * 
 * @brief Interface for the logger lib
 */

#ifndef ILOGGER_HPP_
#define ILOGGER_HPP_

#include <iostream>
#include <fstream>

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
        * \brief log message into a file
        * \param message to log
        */
        virtual void log(std::string message) = 0;
        
        /**
        * \brief log message into a file and and an endline
        * \param message to log
        */
        virtual void logln(std::string message) = 0;

        /**
        * \brief Add a message to the log file // Same as log()
        * \param Content to add
        */
        virtual void operator<<(std::string buffer) = 0;
};

#endif /* !LOGGER_HPP_ */
