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

            explicit Logger();

            virtual ~Logger();

            auto log(std::string message) -> void override;

            auto logln(std::string message) -> void override;

            auto operator<<(std::string buffer) -> void override;

        private:
            std::string file_name;
            std::ofstream _file; /*! File containing the logs*/
            std::mutex lock;
    };

#endif /* !LOGGER_HPP_ */
