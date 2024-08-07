
#ifndef CLS_MONSTER_H
#define CLS_MONSTER_H

#include "header.h"
#include "cls_player.h"
#include "cls_item.h"
#include "cls_potion.h"
#include "cls_gold.h"


class Monster {
public:
    enum class Type {        
        SKELETON,
        ZOMBIE,
        GHOST,

        MAX_TYPE
    };

    struct MonsterBase {
        Type    type;
        int     health;
        int     damage;
    };

    static constexpr std::array<MonsterBase, static_cast<std::size_t>(Type::MAX_TYPE)> base {
        {
            {Type::SKELETON, 10, 10},
            {Type::ZOMBIE, 5, 30},
            {Type::GHOST, 10, 20},
        }
    };

    //Monster::Type getRandomType();

private:

    // ## SKELETON
    //static const int SKELETON_CHANCE_APPEAR { 50 };
//    static const int SKELETON_BASE_HEALTH   { 10 };
//    static const int SKELETON_BASE_DAMAGE   { 10 };

//    // ## ZOMBIE
//    //static const int ZOMBIE_CHANCE_APPEAR   { 30 };
//    static const int ZOMBIE_BASE_HEALTH     { 30 };
//    static const int ZOMBIE_BASE_DAMAGE     { 5 };

//    // ## GHOST
//    //static const int GHOST_CHANCE_APPEAR   { 20 };
//    static const int GHOST_BASE_HEALTH     { 10 };
//    static const int GHOST_BASE_DAMAGE     { 20 };


private:
    Type                        mb_type {Type::SKELETON};
    int                         mb_level {1};
    int                         mb_currentHealth {};
    int                         mb_damage {};

    // I generate several things of different types, but all things have the same BASE type..
    // Can't use reference 'casue componets of std::vector (and other containers) must be ASSIGNABLE
    std::vector<Item*>     mb_loot;
public:
    // #########  Constructors and Destructors  #############

    // #### Create random monster
    // #########
    Monster();

    // #### Create monster of the specific type;
    // #######
    //Monster(Type type = getRandomMonsterType());

    ~Monster() = default;

    // ##########  Setters and Getters  #####################

    int             setDamage(Type type, int level) const;
    int             setHealth(Type type, int level) const;
    int             getDamage() const;
    my::String      getName() const;
    int             getLevel() const;
    Type            getType() const;
    int             getCurrentHealth() const;


    // ##########  Other Functions  ##########################
    bool                    isDead() const;
    void                    attack(Player& player) const;
    void                    reduceHealth(int health);
    void                    commitSuicide();
    void                    generateLoot(const Player& player);

    static int getRandomMonsterLevel();
    static Type getRandomMonsterType();
};


#endif  // CLS_MONSTER_H





//    struct BaseStats {
//        Type type;
//        int chance;
//        int health;
//        int damage;
//    };

//    Monster createRandomMonster() const
//    {
//        // ## Get random monster type
//        Type type { static_cast<Type>(getRandomNumber(0, static_cast<unsigned int>(Type::MAX_TYPE) - 1)) };
//        int health {};
//        int level {getRandomNumber(1, 10)};
//        int damage {};

//        // ## Get current monster stats
//        switch (type) {
//        case Type::SKELETON:
//            health = 50 + 10 * level;
//            damage = 10 + level * 2;
//            break;
//        case Type::ZOMBIE:
//            health = 100 + 20 * level;
//            damage = 10 + level;
//            break;
//        case Type::GHOST:
//            health = 10 * level;
//            damage = level * 2 + 20;
//            break;
//        case Type::MAX_TYPE:
//            assert("[Error]: invalid monster type");
//            break;
//        //default:
//            //break;
//        }

//        return {type, level, health, damage};

//    }


//    static const Monster& Monster::getDefaultMonster(Monster::Type type)
//    {

//        // #### Array of default monsters (with their stats)
//        static const std::array<Monster, static_cast<std::size_t>(Type::MAX_TYPE)> defaultMonster {
//            {
//                      { Type::SKELETON, SKELETON_BASE_HEALTH, SKELETON_BASE_DAMAGE},
//                      { Type::ZOMBIE, ZOMBIE_BASE_HEALTH, ZOMBIE_BASE_DAMAGE},
//                      { Type::GHOST, GHOST_BASE_HEALTH, GHOST_BASE_DAMAGE},
//            }
//        };

//        return defaultMonster.at(static_cast<std::size_t>(type));
//    }
