/**
 * \file Logger.hpp
 * 
 * \brief header for logger lib
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

           /**
            * \fn explicit Logger(std::string fileName)
            * 
            * \brief Create a log file
            * 
            * \param Name of the log file
            */
            explicit Logger(std::string fileName);

            
            /**
             * \fn virtual ~Logger()
             * 
             * \brief Close a log file
             */
            virtual ~Logger();
            
            /**
             * \fn void log(std::string message) override
             * 
             * \brief log message into a file
             * 
             * \param message to log
             */
            void log(std::string message) override;
            
            /**
             * \fn void logln(std::string message) override
             * 
             * \brief log message into a file and and an endline
             * 
             * \param message to log
             */
            void logln(std::string message) override;

            /**
             * \fn void operator<<(std::string buffer) override
             * 
             * \brief Add a message to the log file // Same as log()
             * 
             * \param Content to add
             */
            void operator<<(std::string buffer) override;

        private:
            std::ofstream _file; /*! File containing the logs*/
    };

#endif /* !LOGGER_HPP_ */
