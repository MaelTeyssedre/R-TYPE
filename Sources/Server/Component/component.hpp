#ifndef CONPONENT
    #define CONPONENT

    namespace rtype {
        struct healPoint_s {
            size_t healPoint;
        };

        struct fireFrequence_s {
            size_t fireFrequence;
        };

        struct weapon_s {
            size_t weapon;
        };

        struct loot_s {
            bool loot;
        };

        struct position_s {
            int x;
            int y;
        };

        struct velocity_s {
            int vx;
            int vy;
        };
    }
#endif
