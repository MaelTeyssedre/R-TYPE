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

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class JsonWrapper
         * 
         * \brief wrapper for the json of the map
         * 
         */
        class JsonWrapper : public IJsonWrapper {
            public:
                /**
                 * \struct object_s
                 * 
                 * \brief caracteristics of an object in the map
                 * 
                 */
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

                /**
                 * \fn std::shared_ptr<Player> createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type)
                 * 
                 * \brief Create a Player object
                 * 
                 * \param id id of player
                 * \param pos position of player
                 * \param strength strength of player
                 * \param hp life of player
                 * \param type type of player
                 * 
                 * \return std::shared_ptr<Player> shared pointer of created player
                 */
                std::shared_ptr<Player> createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type);

                /**
                 * \fn std::shared_ptr<Wall> createWall(std::pair<int, int> pos, std::string type)
                 * 
                 * \brief Create a Wall object
                 * 
                 * \param pos position of the wall
                 * \param type type of type
                 * \return std::shared_ptr<Wall> shared pointer of the created wall 
                 */
                std::shared_ptr<Wall> createWall(std::pair<int, int> pos, std::string type);

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
                 * \fn std::vector<AMonster *> &getMonsterList()
                 * 
                 * \brief Get the Monster List object
                 * 
                 * \return std::vector<AMonster *>& list of pointer of monster
                 */
                std::vector<AMonster *> &getMonsterList();

                /**
                 * \fn std::vector<std::shared_ptr<Player>> &getPlayerList()
                 * 
                 * \brief Get the Player List object
                 * 
                 * \return std::vector<std::shared_ptr<Player>>& list of pointer of player
                 */
                std::vector<std::shared_ptr<Player>> &getPlayerList();

                /**
                 * \fn std::vector<std::shared_ptr<Wall>> &getWallList()
                 * 
                 * \brief Get the Wall List object
                 * 
                 * \return std::vector<std::shared_ptr<Wall>>& list of pointer of wall
                 */
                std::vector<std::shared_ptr<Wall>> &getWallList();

                /**
                 * \fn nlohmann::json strToJson(std::string &toConvert)
                 * 
                 * \brief convert a string to json
                 * 
                 * \param toConvert string to convert
                 * 
                 * \return nlohmann::json converted json
                 */
                nlohmann::json strToJson(std::string &toConvert);

            private:
                LibLoader _loader; /*! libLoader */
                std::string _filename;  /*! name of the json file */
                nlohmann::json _json; /*! a json file */
                std::vector<AMonster *> _monsterList; /*! list of monster */
                std::vector<std::shared_ptr<Wall>> _wallList; /*! list of wall */
                std::vector<std::shared_ptr<Player>> _playerList; /*! list of player */
                std::vector<std::string> _typeList; /*! type list */
                std::vector<std::pair<std::string, object_t>> _params; /*! params getted in the map */
        };
    }

#endif /* !IJSONWRAPPER_HPP_ */
