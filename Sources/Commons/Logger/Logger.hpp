/*
** EPITECH PROJECT, 2021
** B-CPP-500-NAN-5-1-babel-romain.gabet
** File description:
** Logger.hpp
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "ILogger.hpp"

/**
 * \class Logger class
 * 
 * \brief Used to store log in a file.
 */
class Logger : public ILogger {

    public:

       /*!
        * @brief Create a log file
        * @param Name of the log file
        */
        explicit Logger(std::string fileName);

        
        /**
         * \fn virtual ~Logger()
         * 
         * \brief Close a log file
         */
        virtual ~Logger();
        
        /*!
        * @brief log message into a file
        * @param message to log
        */
        void log(std::string message) override;
        
        /*!
        * @brief log message into a file and and an endline
        * @param message to log
        */
        void logln(std::string message) override;

        /*!
        * @brief Add a message to the log file // Same as log()
        * @param Content to add
        */
        void operator<<(std::string buffer) override;

    
    private:
    
        std::ofstream _file; /*! File containing the logs*/
};

#endif /* !LOGGER_HPP_ */
