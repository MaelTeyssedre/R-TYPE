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
            typedef struct object_s {       /*! An object */
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

            std::shared_ptr<Player> JsonWrapper::createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type);

            std::shared_ptr<Wall> JsonWrapper::createWall(std::pair<int, int> pos, std::string type);


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

            std::vector<AMonster *> &getMonsterList() {return _monsterList;}

            std::vector<std::shared_ptr<Player>> &getPlayerList() {return _playerList;}

            std::vector<std::shared_ptr<Wall>> &getWallList() {return _wallList;}

            nlohmann::json strToJson(std::string &toConvert);
        private:
            LibLoader _loader;
            std::string _filename;  /*! name of the json file */
            nlohmann::json _json; /*! a json file */
            std::vector<AMonster *> _monsterList;
            std::vector<std::shared_ptr<Wall>> _wallList;
            std::vector<std::shared_ptr<Player>> _playerList;
            std::vector<std::string> _typeList; /*! type list */
            std::vector<std::pair<std::string, object_t>> _params;
    };

#endif /* !IJSONWRAPPER_HPP_ */
