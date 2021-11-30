/**
 * \file UpdateGraph.hpp
 *
 * \brief file where the update graphical system is defined
 */
#ifndef UPDATEGRAPH_HPP_
    #define UPDATEGRAPH_HPP_

    #include <iostream>
    #include <map>
    #include <chrono>
    #include <thread>
    #include "Registry.hpp"
    #include "Constants.hpp"
    #include <functional>
    #include "Zipper.hpp"
    #include "Components.hpp"
    #include "GraphicalLib.hpp"

    /**
     * \namespace rtype
     * 
     * \brief namespace for the R-Type
     * 
     */
    namespace rtype {
        /**
         * \class UpdateGraph UpdateGraph.hpp 
         * 
         * \brief class that contain the system UpdateGraph
         */
        class UpdateGraph {
            public:
                /**
                 * \fn explicit UpdateGraph() = default
                 *
                 * \brief ctor UpdateGraph
                 */
                UpdateGraph();

                /**
                 * \fn ~UpdateGraph() = default
                 *
                 * \brief dtor UpdateGraph
                 */
                ~UpdateGraph() = default;

                /**
                 * \fn void operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
                 *
                 * \brief operator to be used by the ECS
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param mouseStates reference to a sparseArray of mouseState components
                 * 
                 * \param keyStates reference to a sparseArray of keyState components
                 * 
                 * \param currentScenes reference to a sparseArray of currentScene components
                 */
                void operator()(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);
                
            private:

                /**
                 * \fn void _updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates)
                 *
                 * \brief update the game events
                 * 
                 * \param mouseStates reference to a sparseArray of mouseState components
                 * 
                 * \param keyStates reference to a sparseArray of keyState components
                 */
                void _updateEvent(SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates);

                /**
                 * \fn void _updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes)
                 *
                 * \brief update the game graphicals element
                 * 
                 * \param r A reference to the registry
                 * 
                 * \param mouseStates reference to a sparseArray of mouseState components
                 * 
                 * \param keyStates reference to a sparseArray of keyState components
                 * 
                 * \param currentScenes reference to a sparseArray of currentScene components
                 */
                void _updateGraph(Registry &r, SparseArray<components::mouseState_s> &mouseStates, SparseArray<components::keyState_s> &keyStates, SparseArray<components::currentScene_s> &currentScenes);

            private:

                /**
                 * \fn _setupScenes()
                 *
                 * \brief setup the scene
                 */
                void _setupScenes();

                /**
                 * \fn void _setupExecScene()
                 *
                 * \brief setup the scene execution
                 */
                void _setupExecScene();

                /**
                 * \fn void _setupDeleteScene()
                 *
                 * \brief setup the scene deletion 
                 */
                void _setupDeleteScene();

            private:
                /**
                 * \fn void _setupLoadingMenuScene()
                 *
                 * \brief setup the loading menu scene
                 */
                void _setupLoadingMenuScene();

                /**
                 * \fn void _setupLoadingGameScene()
                 *
                 * \brief setup the loading game scene
                 */
                void _setupLoadingGameScene() {};

                /**
                 * \fn void _setupGameScene()
                 *
                 * \brief setup the game scene
                 */
                void _setupGameScene() {};

                /**
                 * \fn void _setupParamsScene()
                 *
                 * \brief setup the parameter scene
                 */
                void _setupParamsScene() {};

                /**
                 * \fn void _setupMainMenuScene()
                 *
                 * \brief setup the main menu scene
                 */
                void _setupMainMenuScene();
                
            private:
                /**
                 * \fn void _setupExecLoadingMenuScene()
                 *
                 * \brief setup the execution of the loading menu scene
                 */
                void _setupExecLoadingMenuScene();

                /**
                 * \fn void _setupExecLoadingGameScene()
                 *
                 * \brief setup the execution of the loading game scene
                 */
                void _setupExecLoadingGameScene() {};

                /**
                 * \fn void _setupExecGameScene()
                 *
                 * \brief setup the execution of the game scene
                 */
                void _setupExecGameScene() {};

                /**
                 * \fn void _setupExecParamsScene()
                 *
                 * \brief setup the execution of the parameter scene
                 */
                void _setupExecParamsScene() {};

                /**
                 * \fn void _setupExecMainMenuScene()
                 *
                 * \brief setup the execution of the main menu scene
                 */
                void _setupExecMainMenuScene();
                
            private:
                
                /**
                 * \fn void _setupDeleteLoadingMenuScene()
                 *
                 * \brief setup the deletion of the loading menu scene
                 */
                void _setupDeleteLoadingMenuScene();

                /**
                 * \fn void _setupDeleteLoadingGameScene()
                 *
                 * \brief setup the deletion of the loading game scene
                 */
                void _setupDeleteLoadingGameScene() {};

                /**
                 * \fn void _setupDeleteGameScene()
                 *
                 * \brief setup the deletion of the game scene
                 */
                void _setupDeleteGameScene() {};

                /**
                 * \fn void _setupDeleteParamsScene()
                 *
                 * \brief setup the deletion of the parameter scene
                 */
                void _setupDeleteParamsScene() {};

                /**
                 * \fn void _setupDeleteMainMenuScene()
                 *
                 * \brief setup the deletion of the main menu scene
                 */
                void _setupDeleteMainMenuScene();

            private:
                rtype::IGraphicalLib *_graphicalLib; /*! The graphical library */

                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &, SparseArray<components::currentScene_s> &)>> _setupScene; /*! A list of function which setup each scene */
                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &, SparseArray<components::currentScene_s> &currentScenes, GraphicalLib *lib)>> _execScene; /*! A list of function which execute each scene */
                std::map<rtype::constants::SCENE, std::function<void(Registry &, UpdateGraph &, GraphicalLib *)>> _deleteScene; /*! A list of function which delete each scene */


                size_t _background_id;
                size_t _switchId;
        };
    }

#endif /* !UPDATEGRAPH_HPP_ */
