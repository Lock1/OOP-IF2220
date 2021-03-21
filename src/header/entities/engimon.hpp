// Engimon class
// --- Constraint ---
// 1. Minimal 1 species for every type and combination element
#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include "attributes/elementtype.hpp"
#include "attributes/skill.hpp"
#include "tile.hpp"
#include "entity.hpp"
#include "species.hpp"
#include <string>
#include <vector>
#include <set>

class Engimon : public Entity, Species {
    private:
        // int EngimonID;
        // std::string Name;
        // std::string parentName; // TODO : Species (?)
        // ii.    Parent Names & Species
        
        // std::vector<Skill> learnedSkill;

        vector<Species> parentSpecies;
        vector<std::string> parentNames;

        std::set<ElementType> engimonElement;

        // int Level;
        // int Experience;
        // int CumulativeExperience;
        bool isWild;
        // bool isMultiElement;
        // std::string InteractionDescription;

        bool isTileCompatible(TileType type); // TODO : Multiple element
        // Tile compatibility checking
    public:
        // Engimon(Position pos, ElementType type, char icon, bool wild);  // WARNING : Basic, only for debugging
        Engimon(const Species& species, bool wild, Position pos);   // TODO : Get from database

        bool isMoveLocationValid(Tile &target) override;
        bool xpGain(int gainedXP);                                  // If Levelup -> return true, else false
        bool isMaxCXP();                                            // If over CumulativeExperience, return true
        bool addSkill(Skill& newSkill);                             // Only add if skill slot enough
        bool deleteskill(Skill& targetSkill);

        std::set<ElementType> getElement();

        bool isWildEngimon();
        std::string playerInteract();                               // Print description, only non-wild pokemon
};




#endif
