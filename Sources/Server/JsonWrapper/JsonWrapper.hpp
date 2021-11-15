/*
** EPITECH PROJECT, 2021
** R-TYPE
** File description:
** JsonWRAPPER
*/

/**
 * \file JsonWrapper.hpp
 *
 * \class JsonWrapper 
 * 
 * \brief Manipulate the content of a Json file
 */
#ifndef JSONWRAPPER_HPP_
#define JSONWRAPPER_HPP_

    #include <vector>
    #include "IJsonWrapper.hpp"

    class JsonWrapper : public IJsonWrapper {
        public:
            struct object_s {           /*! An object */
            int id;                     /*! Object id */
            std::pair<int, int> pos;    /*! Object spawn position */
            int strength;               /*! Object strength */
            int hp;                     /*! Object hp */
            std::string type;           /*! Object type */
        };

            /**
             * \fn JsonWrapper(std::string &filename)
             * 
             * \brief Construct the JsonWrapper object
             * 
             * \param filename filename of a json file
             */
            explicit JsonWrapper(std::string &filename);


            /**
             * \fn std::string &jsonToString() override
             * 
             * \brief Convert and return content of a json file as a string
             * 
             * \return std::string & Le contenu du file .json
             */
            std::string jsonToString() override;

            /**
             * \fn void fillComposantList() override
             * 
             * \brief Fill a object list with the content of a JSON file
             */
            void fillComposantList() override;

            /**
             * \fn JsonWrapper::object_s createComposant(int id, std::pair<int, int> pos, int strength, int hp, std::string &type)
             * 
             * \brief Construct a player object
             * 
             * \param id Id of the object
             * \param pos Spawn position of the object
             * \param strength Strength of the object
             * \param hp Hp of the object
             * \param type Type of the object
             * 
             * \return JsonWrapper::object_s a new player object
             */
            JsonWrapper::object_s createComposant(int id, std::pair<int, int> pos, int strength, int hp, const std::string &type);

            /**
             * \fn JsonWrapper::object_s createComposant(std::pair<int, int> pos, std::string &type)
             * 
             * \brief Construct aither an monster object or a wall object
             * 
             * \param pos Spawn position of the object
             * \param type Type of the object
             * 
             * \return JsonWrapper::object_s a new object
             */
            JsonWrapper::object_s createComposant(std::pair<int, int> pos, const std::string &type);

            /**
             * \fn void addPlayer() override
             * 
             * \brief Fill a object list with a player object
             */
            void addPlayer() override;

            /**
             * \fn void addMonster() override
             * 
             * \brief Fill a object list with a monster object
             */
            void addMonster() override;

            /**
             * \fn void addWall() override
             * 
             * \brief Fill a object list with a wall object
             */
            void addWall() override;

            /**
             * \fn bool isNewElementType(std::vector<std::vector<JsonWrapper::object_s>> _objectList, std::string type)
             * 
             * \brief Check if an element exist in the object list
             * 
             * \param _objectList An object list
             * \param type Type of the object
             * 
             * \return bool True if the object is found, false otherwise
             */
            bool isNewElementType(std::vector<std::vector<JsonWrapper::object_s>> _objectList, std::string type);

            /**
             * \fn std::vector<std::vector<JsonWrapper::object_s>> getComposantList() const
             * 
             * \brief Return an object list
             * 
             * \return std::vector<std::vector<JsonWrapper::object_s>> A vector of object list
             */
            std::vector<std::vector<JsonWrapper::object_s>> getComposantList() const;
        private:
            std::string _filename;  /*! name of the json file */
            nlohmann::json _json; /*! a json file */
            std::vector<std::vector<JsonWrapper::object_s>> _objectList; /*! an object list */
    };

#endif /* !IJSONWRAPPER_HPP_ */
