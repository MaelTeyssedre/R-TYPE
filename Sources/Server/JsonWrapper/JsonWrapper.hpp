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

    #include "IJsonWrapper.hpp"


    class JsonWrapper : public IJsonWrapper {
        public:
            typedef struct object_s {           /*! An object */
                int id;                     /*! Object id */
                std::pair<int, int> pos;    /*! Object spawn position */
                int strength;               /*! Object strength */
                int hp;                     /*! Object hp */
                std::string type;           /*! Object type */
            } object_t;

        public:
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
            std::shared_ptr<IElement> createPlayer(int id, std::pair<int, int> pos, int strength, int hp,  std::string type);

            /**
             * \fn JsonWrapper::object_s createComposant(std::pair<int, int> pos, std::string &type)
             * 
             * \brief Construct a monster object 
             * 
             * \param pos Spawn position of the object
             * \param type Type of the object
             * 
             * \return JsonWrapper::object_s a new object
             */
            // std::shared_ptr<IElement> createMonster(std::pair<int, int> pos, std::string type);

            /**
             * \fn JsonWrapper::object_s createMonster(std::pair<int, int> pos, std::string &type)
             * 
             * \brief Construct a wall object
             * 
             * \param pos Spawn position of the object
             * \param type Type of the object
             * 
             * \return JsonWrapper::object_s a new object
             */
            std::shared_ptr<IElement> createWall(std::pair<int, int> pos, std::string type);

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
            // bool isNewElementType(std::vector<std::vector<std::shared_ptr<IElement>>> _objectList, std::string type);

            /**
             * \fn std::vector<std::vector<JsonWrapper::object_s>> getComposantList() const
             * 
             * \brief Return an object list
             * 
             * \return std::vector<std::vector<JsonWrapper::object_s>> A vector of object list
             */
            std::vector<std::pair<std::shared_ptr<IElement>, std::string>> &getComposantList();

            nlohmann::json strToJson(std::string &toConvert);
        private:
            std::string _filename;  /*! name of the json file */
            nlohmann::json _json; /*! a json file */
            std::vector<std::pair<std::shared_ptr<IElement>, std::string>> _objectList; /*! an object list */
            std::vector<std::string> _typeList; /*! type list */
            std::vector<std::pair<std::string, object_t>> _params;
    };

#endif /* !IJSONWRAPPER_HPP_ */
