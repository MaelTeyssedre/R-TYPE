#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include "SparseArray.hpp"
    #include <map>
    #include <typeindex>
    #include "Entity.hpp"
    #include <any>
    #include <functional>

    /*!
    * \brief Registry of the ECS
    */
    class Registry {
        public:
            /*!
            * \brief default ctor
            */
            explicit Registry() = default;

            /*!
            * \brief ctor with an default number of entities
            */
            explicit Registry(size_t nbEntity);

            /*!
            * \brief default dtor
            */
            virtual ~Registry() = default;

        public:
            /*!
            * \brief boolean function to know if an entity is already killed
            *
            * \param e constant reference to an entity
            * 
            * \return true if e is already killed, false otherwise
            */
            bool isKilled(Entity const &e);

            /*!
            * \brief create a new entity
            *
            * \return the new entity
            */
            Entity spawnEntity();

            /*!
            * \brief getter of an entity from his index
            *
            * \param idx index of the entity we want to get
            * 
            * \return the entity at the specified index
            */
            Entity entityFromIndex(size_t idx);

            /*!
            * \brief kill an intity
            *
            * \param e entity we want to kill
            */
            void killEntity(Entity const &e);

            /*!
            * \brief run all the systems in the order they are stocked
            */
            void run_system();

        public:

            /*!
            * \brief register a component in the registry
            *
            * \param constructor function that will be the default ctor of the component, called at spawnEntity
            * \param destructor function that will be the default dtor of the component, called at killEntity
            * 
            * \return reference to the sparseArray of the component
            */
            template <class Component>
            SparseArray<Component> &registerComponent(std::function<void(Registry &, Entity const &)> constructor, std::function<void(Registry &, Entity const &)> destructor) {
                _componentsArrays.try_emplace(std::type_index(typeid(Component)), std::make_any<SparseArray<Component>>(_entities));
                _constructorArray.insert(std::make_pair(std::type_index(typeid(Component)), constructor));
                _destructorArray.insert(std::make_pair(std::type_index(typeid(Component)), destructor));
                return std::any_cast<SparseArray<Component> &>(_componentsArrays[std::type_index(typeid(Component))]);
            }

            /*!
            * \brief getter for sparseArray of the component
            *
            * \return reference to the SparseArray of the component type 
            */
            template <class Component>
            SparseArray<Component> &getComponents() {
                return std::any_cast<SparseArray<Component> &>(_componentsArrays[std::type_index(typeid(Component))]);
            }

            /*!
            * \brief getter for sparseArray of the component
            *
            * \return constant reference to the SparseArray of the component type 
            */
            template <class Component>
            SparseArray<Component> const &getComponents() const {
                return std::any_cast<SparseArray<Component> const &>(_componentsArrays[std::type_index(typeid(Component))]);
            }

            /*!
            * \brief add a component to a entity
            *
            * \param to constant reference of the entity that will have the component
            * \param c universal reference of the component that will be moved in the sparseArray
            * 
            * \return reference to the sparseArray that contain the moved component
            */
            template <typename Component>
            typename SparseArray<Component>::reference_type addComponent(Entity const &to, Component &&c) {
                return (std::any_cast<SparseArray<Component> &>(_componentsArrays[std::type_index(typeid(Component))])).insertAt(to, c);
            }

            /*!
            * \brief create a nomponent for an specified entity
            *
            * \param to constant reference to the entity that will have the constructed component
            * \param p universal reference of a variadic template arguments to create the new component
            * 
            * \return reference to the SparseArray containing the created component
            */
            template <typename Component, typename ...Params>
            typename SparseArray<Component>::reference_type emplaceComponent(Entity const &to, Params &&...p) {
                return (std::any_cast<SparseArray<Component>>(_componentsArrays[std::type_index(typeid(Component))])).emplaceAt(to, p);
            }

            /*!
            * \brief remove a component of an entity
            *
            * \param from constant reference to the entity where the component will be removed
            */
            template <typename Component>
            void removeComponent(Entity const &from) {
                auto array = std::any_cast<SparseArray<Component> &>(_componentsArrays[std::type_index(typeid(Component))]);
                array.erase(from);
            }

            /*!
            * \brief add a system the the registry
            *
            * \param f universal reference of a function that will be moved inside the registry
            * \param y universal reference of a variadic template for arguments taken by the function passed previously
            */
            template <typename Function, class ...Components>
            void addSystem(Function &&f, Components &&...components) {
                _systems.push_back([&f, &components...](Registry &r) -> void {
                    f(r, components...);
                });
            }

            /*!
            * \brief add a system the the registry
            *
            * \param f universal reference of a function that will be added inside the registry
            * \param y variadic template for arguments taken by the function passed previously
            */
            template <typename Function, class ...Components>
            void addSystem(Function const &f, Components &...components) {
                _systems.push_back([&f, &components...](Registry &r) -> void {
                    f(r, components...);
                });
            }

        private:
            std::map<std::type_index, std::function<void(Registry &, Entity const &)>> _constructorArray; /*! map of default constructor for components, indexed by type */
            std::map<std::type_index, std::function<void(Registry &, Entity const &)>> _destructorArray; /*! map of default desctructor for components, indexed by type */
            std::map<std::type_index, std::any> _componentsArrays; /*! map of components, indexed by type */
            std::vector<std::function<void(Registry &)>> _systems; /*! list of systems that will be executed from the first to the last (the order can be importanrt) */
            size_t _entities; /*! number of entities */
            std::vector<Entity> _killedEntities; /*! list of killed entities */
    };

#endif /* !REGISTRY_HPP_ */
