#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "utilities.h"
using std::string;

class Player {

    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;

protected:

    std::string m_name;
    std::string m_job;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;


public:

    static const int MAX_LEVEL = 10;

    /**
     * @brief Constructs a new player
     *
     * @param name Name of the player
     * @param force Player's force. Default value is 5
     * @param maxHP Maximum HP of the player. Default value is 100
     */
    Player(string name, string job, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /**
     * @brief Constructs a new player and copies the data from the other player
     *
     * @param other Other player to copy from
     */
    Player(const Player& other);

    /**
     * @brief Destructs a player
     *
     */
    ~Player() = default;

    /**
     * @brief Assignment operator. Assign player object from another player
     *
     * @param other Another player to assign from
     * @return Returns the newly assigned player
     */
    Player& operator=(const Player& other);

    /**
     * @brief Levels up the player by 1 if current level is less then 10
     *
     */
    void levelUp();

    /**
     * @brief Get the current level of the player
     *
     * @return Returns the current level of the player
     */
    int getLevel() const;

    /**
     * @brief Increase player's force by input amount
     *
     * @param force The amount the increase the force by
     */
    void buff(int force);

    /**
     * @brief Increase player's current HP by input amount if current HP is less then maximum HP
     *
     * @param hp Increase HP by this amount
     */
    virtual void heal(int hp);

    /**
     * @brief Decrease player's HP by input amount, can't go lower then 0
     *
     * @param hp Decrease player's HP by this amount
     */
    void damage(int hp);

    /**
     * @brief Checks if player's health is 0
     *
     * @return true if player is knocked out
     * @return false otherwise.
     */
    bool isKnockedOut() const;

    /**
     * @brief Adds coins to the player by input amount
     *
     * @param coins The amount to increase the coins by
     */
    virtual void addCoins(int coins);

    /**
     * @brief Decrease player's coins (pay) by input amount if there is enough coins, otherwise does nothing
     *
     * @param price Decrease coins by this amount
     * @return true if pay was successful
     * @return false if player has not enough coins
     */
    bool pay(int price);

    /**
     * @brief Get the attack strength of the player which is defined by sum of force and level of the player
     *
     * @return Returns player's attack strength
     */
    virtual int getAttackStrength() const;

    /**
     * @brief Get the current HP of the player
     *
     * @return Returns the current HP of the player
     */
    int getHP() const;

    /**
     * @brief Get the Job of the player
     *
     * @return Returns the Job of the player
     */
    std::string getJob() const;

    std::ostream& operator<<(std::ostream &os) {
        printPlayerDetails(&os, this->m_name, this->m_job, this->m_level, this->m_force, this->m_hp, this->m_coins);
    }
};


#endif //PLAYER_H