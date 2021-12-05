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
     * \brief global namespace for the rtype project
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
                 * \fn auto jsonToString() -> std::string override
                 * 
                 * \brief Convert and return content of a json file as a string
                 * 
                 * \return std::string & Le contenu du file .json
                 */
                auto jsonToString() -> std::string override;

                /**
                 * \fn auto fillComposantList() -> void override
                 * 
                 * \brief Fill a object list with the content of a JSON file
                 */
               auto fillComposantList() -> void override;

                /**
                 * \fn auto createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type) -> std::shared_ptr<Player>
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
                auto createPlayer(int id, std::pair<int, int> pos, int strength, int hp, std::string type) -> std::shared_ptr<Player>;

                /**
                 * \fn auto createWall(std::pair<int, int> pos, std::string type) -> std::shared_ptr<Wall>
                 * 
                 * \brief Create a Wall object
                 * 
                 * \param pos position of the wall
                 * \param type type of type
                 * \return std::shared_ptr<Wall> shared pointer of the created wall 
                 */
                auto createWall(std::pair<int, int> pos, std::string type) -> std::shared_ptr<Wall>;

                /**
                 * \fn auto addPlayer() -> void override
                 * 
                 * \brief Fill a object list with a player object
                 */
                auto addPlayer() -> void override;

                /**
                 * \fn auto addMonster() -> void override
                 * 
                 * \brief Fill a object list with a monster object
                 */
                auto addMonster() -> void override;

                /**
                 * \fn auto addWall() -> void override
                 * 
                 * \brief Fill a object list with a wall object
                 */
                auto addWall() -> void override;

                /**
                 * \fn auto getMonsterList() -> std::vector<AMonster *> &
                 * 
                 * \brief Get the Monster List object
                 * 
                 * \return std::vector<AMonster *>& list of pointer of monster
                 */
                auto getMonsterList() -> std::vector<AMonster *> &;

                /**
                 * \fn auto getPlayerList() -> std::vector<std::shared_ptr<Player>> &
                 * 
                 * \brief Get the Player List object
                 * 
                 * \return std::vector<std::shared_ptr<Player>>& list of pointer of player
                 */
                auto getPlayerList() -> std::vector<std::shared_ptr<Player>> &;

                /**
                 * \fn auto getWallList() -> std::vector<std::shared_ptr<Wall>> &
                 * 
                 * \brief Get the Wall List object
                 * 
                 * \return std::vector<std::shared_ptr<Wall>>& list of pointer of wall
                 */
                auto getWallList() -> std::vector<std::shared_ptr<Wall>> &;

                /**
                 * \fn auto strToJson(std::string &toConvert) -> nlohmann::json
                 * 
                 * \brief convert a string to json
                 * 
                 * \param toConvert string to convert
                 * 
                 * \return nlohmann::json converted json
                 */
                auto strToJson(std::string &toConvert) -> nlohmann::json;

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
