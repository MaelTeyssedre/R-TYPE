/**
 * \file UpdateGraph.hpp
 *
 * \brief file where the update graph system is defined
 */

#ifndef UPDATEGRAPH_HPP_
    #define UPDATEGRAPH_HPP_

    #include "Registry.hpp"
    #include "Constants.hpp"
    #include "MouseStateComponent.hpp"
    #include "KeyStateComponent.hpp"
    #include "GraphicalLib.hpp"

    /**
     * \class UpdateGraph UpdateGraph.hpp 
     * 
     * \brief class that contain the system UpdateGraph
     */
    class UpdateGraph {
        public:
            /**
             * \fn UpdateGraph()
             *
             * \brief ctor UpdateGraph
             */
            UpdateGraph();
            /**
             * \fn virtual ~UpdateGraph() = default
             *
             * \brief dtor UpdateGraph
             */
            ~UpdateGraph() = default;

            /**
             * \fn void operator()(Registry &r,  SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates)
             *
             * \brief To be used by the ECS
             * 
             * \param r A reference to the registry
             * 
             * \param mouseStates a reference to a sparceArray of mouse state components
             * 
             * \param keyStates a reference to a sparceArray of key state components
             */
            void operator()(Registry &r,  SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates);

            /**
             * \fn void setupGame(Registry &r)
             *
             * \brief To setup the game
             */
            void setupGame(Registry &r);

            /**
             * \fn void setupMenu(Registry &r)
             *
             * \brief To setup the menu 
             */
            void setupMenu(Registry &r);

        private:
            /**
             * \fn void updateEvent(SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates)
             *
             * \brief To update event
             * 
             * \param mouseStates a reference to a sparceArray of mouse state components
             * 
             * \param keyStates a reference to a sparceArray of key state components
             */
            void updateEvent(SparseArray<components::mouseState_t> &mouseStates, SparseArray<components::keyState_t> &keyStates); 
            rtype::IGraphicalLib *_graphicalLib; /*! A graphical client */
    };

#endif /* !UPDATEGRAPH_HPP_ */
