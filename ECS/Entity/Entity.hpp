#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    class Registry;

    /*!
    * \brief class for Entity, constructable only from Registry class
    */
    class Entity {
        public:
            /*!
            * \brief overload of the operator () to be able to cast an Entity in size_t
            */
            operator size_t() const;

            /*!
            * \brief Entity dtor
            */
            ~Entity() = default;

        protected:
            /*!
            * \brief class passed in friend to only be able to be created by it
            */
            friend class Registry;

            /*!
            * \brief ctor
            *
            * \param id id of the entity
            */
            explicit Entity(size_t id);

        private:
            size_t _id; /*! id of the entity */
    };

#endif /* !ENTITY_HPP_ */
