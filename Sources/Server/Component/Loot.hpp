/**
 * \file Loot.hpp
 * 
 * \brief file for Loot component 
 */

#ifndef LOOT_HPP_
    #define LOOT_HPP_

    /**
     * \namespace rtype
     * 
     * \brief global namespace for rtype project
     * 
     */
    namespace rtype {
        /**
         * \namespace components
         * 
         * \brief namespace for ECS component
         * 
         */
        namespace components {
            /**
             * \struct loot_s
             * 
             * \brief loot component
             * 
             */
            struct loot_s {
                bool loot;
            };
        }
    }

#endif /* !LOOT_HPP_ */
